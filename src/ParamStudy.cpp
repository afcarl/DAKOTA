/*  _______________________________________________________________________

    DAKOTA: Design Analysis Kit for Optimization and Terascale Applications
    Copyright (c) 2010, Sandia National Laboratories.
    This software is distributed under the GNU Lesser General Public License.
    For more information, see the README file in the top Dakota directory.
    _______________________________________________________________________ */

//- Class:       ParamStudy
//- Description: Implementation code for the ParamStudy class
//- Owner:       Mike Eldred

#include "dakota_system_defs.hpp"
#include "dakota_tabular_io.hpp"
#include "ParamStudy.hpp"
#include "ProblemDescDB.hpp"
#include "ParallelLibrary.hpp"
#include "PolynomialApproximation.hpp"
#include <boost/lexical_cast.hpp>

static const char rcsId[]="@(#) $Id: ParamStudy.cpp 7024 2010-10-16 01:24:42Z mseldre $";

//#define DEBUG


namespace Dakota {

// special values for pStudyType
enum { LIST=1, VECTOR_SV, VECTOR_FP, CENTERED, MULTIDIM };


ParamStudy::ParamStudy(Model& model): PStudyDACE(model), pStudyType(0)
{
  // use allVariables instead of default allSamples
  compactMode = false;

  // Set pStudyType
  const RealVector& step_vector
    = probDescDB.get_rv("method.parameter_study.step_vector");
  if (strbegins(methodName, "list_"))
    pStudyType = LIST;
  else if (strbegins(methodName, "vector_"))
    pStudyType = (step_vector.empty()) ? VECTOR_FP : VECTOR_SV;
  else if (strbegins(methodName, "centered_"))
    pStudyType = CENTERED;
  else if (strbegins(methodName, "multidim_"))
    pStudyType = MULTIDIM;

  // Extract specification from ProblemDescDB, perform sanity checking, and
  // compute/estimate maxConcurrency.
  bool err_flag = false;
  switch (pStudyType) {
  case LIST: // list_parameter_study
    { // need braces due to variable initializations inside case 
      const RealVector& pt_list = 
	probDescDB.get_rv("method.parameter_study.list_of_points");
      if (pt_list.empty()) {
	const String& pt_fname = probDescDB.get_string("method.pstudy.filename");
	bool annotated = probDescDB.get_bool("method.pstudy.file_annotated");
	if (load_distribute_points(pt_fname, annotated))
	  err_flag = true;
      }
      else {
	if (distribute_list_of_points(pt_list))
	  err_flag = true;
      }
    }
    break;
  case VECTOR_FP: // vector_parameter_study (final_point & num_steps spec.)
    if (check_final_point(
	probDescDB.get_rv("method.parameter_study.final_point")))
      err_flag = true;
    if (check_num_steps(probDescDB.get_int("method.parameter_study.num_steps")))
      err_flag = true;
    // precompute steps (using construct-time initialPoint) and perform error
    // checks only if in check mode; else avoid additional overhead and rely
    // on run-time checks for run-time initialPoint.
    if (numSteps && iteratedModel.parallel_library().command_line_check()) {
      initialCVPoint  = iteratedModel.continuous_variables();    // view
      initialDIVPoint = iteratedModel.discrete_int_variables();  // view
      initialDRVPoint = iteratedModel.discrete_real_variables(); // view
      final_point_to_step_vector(); // covers check_ranges_sets(numSteps)
    }
    break;
  case VECTOR_SV: // vector_parameter_study (step_vector & num_steps spec.)
    if (distribute(step_vector, contStepVector, discIntStepVector,
		   discRealStepVector))
      err_flag = true;
    if (check_num_steps(probDescDB.get_int("method.parameter_study.num_steps")))
      err_flag = true;
    initialDIVPoint = iteratedModel.discrete_int_variables();  // view
    initialDRVPoint = iteratedModel.discrete_real_variables(); // view
    if (check_ranges_sets(numSteps))
      err_flag = true;
    break;
  case CENTERED: { // centered_parameter_study
    if (distribute(step_vector, contStepVector, discIntStepVector,
		   discRealStepVector))
      err_flag = true;
    if (check_steps_per_variable(
	probDescDB.get_iv("method.parameter_study.steps_per_variable")))
      err_flag = true;
    initialDIVPoint = iteratedModel.discrete_int_variables();  // view
    initialDRVPoint = iteratedModel.discrete_real_variables(); // view
    if (check_ranges_sets(contStepsPerVariable, discIntStepsPerVariable,
			  discRealStepsPerVariable))
      err_flag = true;
    break;
  }
  case MULTIDIM: // multidim_parameter_study
    if (check_variable_partitions(probDescDB.get_usa("method.partitions")))
      err_flag = true;
    if (check_finite_bounds())
      err_flag = true;
    // precompute steps (using construct-time bounds) and perform error checks
    // only if in check mode; else avoid additional overhead and rely on
    // run-time checks for run-time bounds.
    if (iteratedModel.parallel_library().command_line_check())
      distribute_partitions();
    break;
  default:
    Cerr << "\nError: bad pStudyType (" << pStudyType
	 << ") in ParamStudy constructor." << std::endl;
    err_flag = true;
  }
  if (err_flag)
    abort_handler(-1);

  maxConcurrency *= numEvals;
}


void ParamStudy::pre_run()
{
  Iterator::pre_run();  // for completeness

  // Capture any changes in initialCVPoint resulting from the strategy layer's
  // passing of best variable info between iterators.  If no such variable 
  // passing has occurred, then this reassignment is merely repetitive of the 
  // one in the ParamStudy constructor.  If there is a final_point 
  // specification, then contStepVector and numSteps must be (re)computed.
  const Variables& vars = iteratedModel.current_variables();
  const SharedVariablesData& svd = vars.shared_data();
  if (pStudyType == VECTOR_SV || pStudyType == VECTOR_FP ||
      pStudyType == CENTERED) {
    copy_data(vars.continuous_variables(),    initialCVPoint);  // copy
    copy_data(vars.discrete_int_variables(),  initialDIVPoint); // copy
    copy_data(vars.discrete_real_variables(), initialDRVPoint); // copy
  }

  size_t av_size = allVariables.size();
  if (av_size != numEvals) {
    allVariables.resize(numEvals);
    for (size_t i=av_size; i<numEvals; ++i)
      allVariables[i] = Variables(svd); // use minimal data ctor
    if ( outputLevel > SILENT_OUTPUT &&
	 ( pStudyType == VECTOR_SV || pStudyType == VECTOR_FP ||
	   pStudyType == CENTERED ) )
      allHeaders.resize(numEvals);
  }

  switch (pStudyType) {
  case LIST: // list_parameter_study
    if (outputLevel > SILENT_OUTPUT)
      Cout << "\nList parameter study for " << numEvals << " samples\n\n";
    sample();
    break;
  case VECTOR_FP: // vector_parameter_study (final_point & num_steps)
    if (outputLevel > SILENT_OUTPUT) {
      Cout << "\nVector parameter study from\n";
      write_ordered(Cout, svd.active_components_totals(),
		    initialCVPoint, initialDIVPoint, initialDRVPoint);
      Cout << "to\n";
      write_data(Cout, finalPoint);
      Cout << "using " << numSteps << " steps\n\n";
    }
    if (numSteps) // define step vectors from initial, final, & num steps
      final_point_to_step_vector();
    vector_loop();
    break;
  case VECTOR_SV: // vector_parameter_study (step_vector & num_steps)
    if (outputLevel > SILENT_OUTPUT) {
      Cout << "\nVector parameter study for " << numSteps
	   << " steps starting from\n";
      write_ordered(Cout, svd.active_components_totals(),
		    initialCVPoint, initialDIVPoint, initialDRVPoint);
      Cout << "with a step vector of\n";
      write_ordered(Cout, svd.active_components_totals(),
		    contStepVector, discIntStepVector, discRealStepVector);
      Cout << '\n';
    }
    vector_loop();
    break;
  case CENTERED: // centered_parameter_study
    if (outputLevel > SILENT_OUTPUT) {
      Cout << "\nCentered parameter study with steps per variable\n";
      write_ordered(Cout, svd.active_components_totals(), contStepsPerVariable,
		    discIntStepsPerVariable, discRealStepsPerVariable);
      Cout << "and increments of\n";
      write_ordered(Cout, svd.active_components_totals(),
		    contStepVector, discIntStepVector, discRealStepVector);
      Cout << "with the following center point:\n";
      write_ordered(Cout, svd.active_components_totals(),
		    initialCVPoint, initialDIVPoint, initialDRVPoint);
      Cout << '\n';
    }
    centered_loop();
    break;
  case MULTIDIM: // multidim_parameter_study
    if (outputLevel > SILENT_OUTPUT) {
      Cout << "\nMultidimensional parameter study variable partitions of\n";
      write_ordered(Cout, svd.active_components_totals(), contVarPartitions,
		    discIntVarPartitions, discRealVarPartitions);
    }
    distribute_partitions();
    multidim_loop();
    break;
  default:
    Cerr << "\nError: bad pStudyType in ParamStudy::extract_trends().\n       "
         << "pStudyType = " << pStudyType << std::endl;
    abort_handler(-1);
  }
}


void ParamStudy::extract_trends()
{
  // perform the evaluations; multidim exception
  bool log_resp_flag = (pStudyType == MULTIDIM) ? (!subIteratorFlag) : false;
  bool log_best_flag = (numObjFns || numLSqTerms); // opt or NLS data set
  evaluate_parameter_sets(iteratedModel, log_resp_flag, log_best_flag);
}


void ParamStudy::post_input()
{
  // call convenience function from Analyzer
  read_variables_responses(numEvals, numContinuousVars + numDiscreteIntVars + 
    numDiscreteRealVars);
}


void ParamStudy::post_run(std::ostream& s)
{
  bool log_resp_flag = (!subIteratorFlag);
  if (pStudyType == MULTIDIM && log_resp_flag)
    pStudyDACESensGlobal.compute_correlations(allVariables, allResponses);

  Iterator::post_run(s);
}


void ParamStudy::sample()
{
  // populate allVariables
  for (size_t i=0; i<numEvals; ++i) {
    if (numContinuousVars)
      allVariables[i].continuous_variables(listCVPoints[i]);
    if (numDiscreteIntVars)
      allVariables[i].discrete_int_variables(listDIVPoints[i]);
    if (numDiscreteRealVars)
      allVariables[i].discrete_real_variables(listDRVPoints[i]);
  }
  // free up redundant memory
  listCVPoints.clear();
  listDIVPoints.clear();
  listDRVPoints.clear();
}


void ParamStudy::vector_loop()
{
  // Steps along a n-dimensional vector through numSteps additions of
  // continuous/discrete step vectors.  The step is an absolute step defining
  // magnitude & direction.  The number of fn. evaluations in the study is
  // numSteps + 1 since the initial point is also evaluated.

  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();
  size_t i, j, dsi_cntr;

  for (i=0; i<=numSteps; ++i) {
    Variables& vars = allVariables[i];

    // active continuous
    for (j=0; j<numContinuousVars; ++j)
      c_step(j, i, vars);

    // active discrete int: ranges and sets
    for (j=0, dsi_cntr=0; j<numDiscreteIntVars; ++j)
      if (di_set_bits[j])
	dsi_step(j, i, dsi_values[dsi_cntr++], vars);
      else
	dri_step(j, i, vars);

    // active discrete real: sets only
    for (j=0; j<numDiscreteRealVars; ++j)
      dsr_step(j, i, dsr_values[j], vars);

    // store each output header in allHeaders
    if (outputLevel > SILENT_OUTPUT) {
      String& h_string = allHeaders[i];
      h_string.clear();
      if (asynchFlag)
	h_string += "\n\n";
      if (numSteps == 0) // Allow numSteps == 0 case
	h_string += ">>>>> Initial_point only (no steps)\n";
      h_string += ">>>>> Vector parameter study evaluation for ";
      h_string += boost::lexical_cast<std::string>(i*100./numSteps);
      h_string += "% along vector\n";
    }
  }
}


void ParamStudy::centered_loop()
{
  size_t k, cntr = 0, dsi_cntr = 0;
  String cv_str("cv"), div_str("div"), drv_str("drv");

  // Always evaluate center point, even if steps_per_variable = 0
  if (outputLevel > SILENT_OUTPUT)
    allHeaders[cntr] = (asynchFlag) ?
      "\n\n>>>>> Centered parameter study evaluation for center point\n" :
      ">>>>> Centered parameter study evaluation for center point\n";
  if (numContinuousVars)
    allVariables[cntr].continuous_variables(initialCVPoint);
  if (numDiscreteIntVars)
    allVariables[cntr].discrete_int_variables(initialDIVPoint);
  if (numDiscreteRealVars)
    allVariables[cntr].discrete_real_variables(initialDRVPoint);
  ++cntr;

  // Evaluate +/- steps for each continuous variable
  for (k=0; k<numContinuousVars; ++k) {
    int i, num_steps_k = contStepsPerVariable[k];
    for (i=-num_steps_k; i<=num_steps_k; ++i)
      if (i) {
	Variables& vars = allVariables[cntr];
	reset(vars); c_step(k, i, vars);
	if (outputLevel > SILENT_OUTPUT) centered_header(cv_str, k, i, cntr);
	++cntr;
      }
  }

  // Evaluate +/- steps for each discrete int variable
  const BitArray&   di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray& dsi_values = iteratedModel.discrete_set_int_values();
  for (k=0; k<numDiscreteIntVars; ++k) {
    int i, num_steps_k = discIntStepsPerVariable[k];
    if (di_set_bits[k]) {
      const IntSet& dsi_vals_k = dsi_values[dsi_cntr];
      for (i=-num_steps_k; i<=num_steps_k; ++i)
	if (i) {
	  Variables& vars = allVariables[cntr];
	  reset(vars); dsi_step(k, i, dsi_vals_k, vars);
	  if (outputLevel > SILENT_OUTPUT) centered_header(div_str, k, i, cntr);
	  ++cntr;
	}
      ++dsi_cntr;
    }
    else {
      for (i=-num_steps_k; i<=num_steps_k; ++i)
	if (i) {
	  Variables& vars = allVariables[cntr];
	  reset(vars); dri_step(k, i, vars);
	  if (outputLevel > SILENT_OUTPUT) centered_header(div_str, k, i, cntr);
	  ++cntr;
	}
    }
  }

  // Evaluate +/- steps for each discrete real variable
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();
  for (k=0; k<numDiscreteRealVars; ++k) {
    int i,  num_steps_k = discRealStepsPerVariable[k];
    const RealSet& dsr_vals_k = dsr_values[k];
    for (i=-num_steps_k; i<=num_steps_k; ++i)
      if (i) {
	Variables& vars = allVariables[cntr];
	reset(vars); dsr_step(k, i, dsr_vals_k, vars);
	if (outputLevel > SILENT_OUTPUT) centered_header(drv_str, k, i, cntr);
	++cntr;
      }
  }
}


void ParamStudy::multidim_loop()
{
  // Perform a multidimensional parameter study based on the number of 
  // partitions specified for each variable.

  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();
  size_t i, j, p_cntr, dsi_cntr,
    num_c_di_vars = numContinuousVars + numDiscreteIntVars,
    num_vars = num_c_di_vars + numDiscreteRealVars;
  UShortArray multidim_indices(num_vars, 0), partition_limits(num_vars);
  copy_data_partial(contVarPartitions,     partition_limits, 0);
  copy_data_partial(discIntVarPartitions,  partition_limits, numContinuousVars);
  copy_data_partial(discRealVarPartitions, partition_limits, num_c_di_vars);

  for (i=0; i<numEvals; ++i) {
    Variables& vars = allVariables[i];
    p_cntr = 0;
    // active continuous
    for (j=0; j<numContinuousVars; ++j, ++p_cntr)
      c_step(j, multidim_indices[p_cntr], vars);
    // active discrete int: ranges and sets
    for (j=0, dsi_cntr=0; j<numDiscreteIntVars; ++j, ++p_cntr)
      if (di_set_bits[j])
	dsi_step(j, multidim_indices[p_cntr], dsi_values[dsi_cntr++], vars);
      else
	dri_step(j, multidim_indices[p_cntr], vars);
    // active discrete real: sets only
    for (j=0; j<numDiscreteRealVars; ++j, ++p_cntr)
      dsr_step(j, multidim_indices[p_cntr], dsr_values[j], vars);
    // increment the multidimensional index set
    Pecos::SharedPolyApproxData::increment_indices(multidim_indices,
						   partition_limits, true);
  }
}

/** Load from file and distribute points; using this function to
    manage construction of the temporary array */
bool ParamStudy::
load_distribute_points(const String& points_filename, bool annotated)
{
  // don't know the size until the file is read, so use dynamic container
  RealArray point_list;
  size_t num_vars
    = numContinuousVars + numDiscreteIntVars + numDiscreteRealVars;
  TabularIO::read_data_tabular(points_filename, "List Parameter Study",
			       point_list, annotated, num_vars);
  // now get a view of it
  RealVector list_of_pts(Teuchos::View, &point_list[0], point_list.size());
  return distribute_list_of_points(list_of_pts);
}

bool ParamStudy::distribute_list_of_points(const RealVector& list_of_pts)
{
  size_t i, j, dsi_cntr, start, len_lop = list_of_pts.length(),
    num_vars = numContinuousVars + numDiscreteIntVars + numDiscreteRealVars;
  if (len_lop % num_vars) {
    Cerr << "\nError: length of list_of_points ("  << len_lop
	 << ") must be evenly divisable among number of active variables ("
	 << num_vars << ")." << std::endl;
    return true;
  }
  numEvals = len_lop / num_vars;
  if (numContinuousVars)   listCVPoints.resize(numEvals);
  if (numDiscreteIntVars)  listDIVPoints.resize(numEvals);
  if (numDiscreteRealVars) listDRVPoints.resize(numEvals);

  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();

  bool err = false;
  RealVector empty_rv; IntVector empty_iv;
  for (i=0, start=0; i<numEvals; ++i) {
    RealVector& list_cv_i  = (numContinuousVars)  ? listCVPoints[i]  : empty_rv;
    IntVector&  list_div_i = (numDiscreteIntVars) ? listDIVPoints[i] : empty_iv;
    RealVector& list_drv_i = (numDiscreteRealVars) ?
      listDRVPoints[i] : empty_rv;

    // take a view of each sample and partition it into {c,di,dr} components
    RealVector all_sample(Teuchos::View, const_cast<Real*>(&list_of_pts[start]),
			  num_vars);
    distribute(all_sample, list_cv_i, list_div_i, list_drv_i);
    start += num_vars;

    // Check for admissible set values
    for (j=0, dsi_cntr=0; j<numDiscreteIntVars; ++j) {
      if (di_set_bits[j]) {
	if (set_value_to_index(list_div_i[j], dsi_values[dsi_cntr]) == _NPOS) {
	  Cerr << "\nError: list value " << list_div_i[j] << " not admissible "
	       << "for discrete int set " << dsi_cntr+1 << '.' << std::endl;
	  err = true;
	}
	++dsi_cntr;
      }
    }
    for (j=0; j<numDiscreteRealVars; ++j)
      if (set_value_to_index(list_drv_i[j], dsr_values[j]) == _NPOS) {
	Cerr << "\nError: list value " << list_drv_i[j] << " not admissible "
	     << "for discrete real set " << j+1 << '.' << std::endl;
	err = true;
      }
  }

#ifdef DEBUG
  Cout << "distribute_list_of_points():\n";
  for (i=0; i<numEvals; ++i) {
    if (numContinuousVars) {
      Cout << "Eval " << i << " continuous:\n";
      write_data(Cout, listCVPoints[i]);
    }
    if (numDiscreteIntVars) {
      Cout << "Eval " << i << " discrete int:\n";
      write_data(Cout, listDIVPoints[i]);
    }
    if (numDiscreteRealVars) {
      Cout << "Eval " << i << " discrete real:\n";
      write_data(Cout, listDRVPoints[i]);
    }
  }
#endif // DEBUG

  return err;
}


void ParamStudy::distribute_partitions()
{
  contStepVector.sizeUninitialized(numContinuousVars);
  discIntStepVector.sizeUninitialized(numDiscreteIntVars);
  discRealStepVector.sizeUninitialized(numDiscreteRealVars);

  initialCVPoint.sizeUninitialized(numContinuousVars);
  initialDIVPoint.sizeUninitialized(numDiscreteIntVars);
  initialDRVPoint.sizeUninitialized(numDiscreteRealVars);

  const RealVector&       c_vars = iteratedModel.continuous_variables();
  const IntVector&       di_vars = iteratedModel.discrete_int_variables();
  const RealVector&      dr_vars = iteratedModel.discrete_real_variables();
  const RealVector&     c_l_bnds = iteratedModel.continuous_lower_bounds();
  const RealVector&     c_u_bnds = iteratedModel.continuous_upper_bounds();
  const IntVector&     di_l_bnds = iteratedModel.discrete_int_lower_bounds();
  const IntVector&     di_u_bnds = iteratedModel.discrete_int_upper_bounds();
  const RealVector&    dr_l_bnds = iteratedModel.discrete_real_lower_bounds();
  const RealVector&    dr_u_bnds = iteratedModel.discrete_real_upper_bounds();
  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();

  size_t i, dsi_cntr; unsigned short part;
  for (i=0; i<numContinuousVars; ++i) {
    part = contVarPartitions[i];
    if (part) {
      initialCVPoint[i] = c_l_bnds[i];
      contStepVector[i] = (c_u_bnds[i] - c_l_bnds[i]) / part;
    }
    else
      { initialCVPoint[i] = c_vars[i]; contStepVector[i] = 0.; }
  }
  for (i=0, dsi_cntr=0; i<numDiscreteIntVars; ++i) {
    part = discIntVarPartitions[i];
    if (part) {
      initialDIVPoint[i] = di_l_bnds[i];
      int range = (di_set_bits[i]) ? dsi_values[dsi_cntr++].size() - 1 :
	                             di_u_bnds[i] - di_l_bnds[i];
      discIntStepVector[i] = integer_step(range, part);
    }
    else
      { initialDIVPoint[i] = di_vars[i]; discIntStepVector[i] = 0; }
  }
  for (i=0; i<numDiscreteRealVars; ++i) {
    part = discRealVarPartitions[i];
    if (part) {
      initialDRVPoint[i]    = dr_l_bnds[i];
      discRealStepVector[i] = integer_step(dsr_values[i].size() - 1, part);
    }
    else
      { initialDRVPoint[i] = dr_vars[i]; discRealStepVector[i] = 0; }
  }

#ifdef DEBUG
  Cout << "distribute_partitions():\n";
  if (numContinuousVars) {
    Cout << "c_vars:\n";             write_data(Cout, c_vars);
    Cout << "c_l_bnds:\n";           write_data(Cout, c_l_bnds);
    Cout << "c_u_bnds:\n";           write_data(Cout, c_u_bnds);
    Cout << "initialCVPoint:\n";     write_data(Cout, initialCVPoint);
    Cout << "contStepVector:\n";     write_data(Cout, contStepVector);
  }
  if (numDiscreteIntVars) {
    Cout << "di_vars:\n";            write_data(Cout, di_vars);
    Cout << "di_l_bnds:\n";          write_data(Cout, di_l_bnds);
    Cout << "di_u_bnds:\n";          write_data(Cout, di_u_bnds);
    Cout << "initialDIVPoint:\n";    write_data(Cout, initialDIVPoint);
    Cout << "discIntStepVector:\n";  write_data(Cout, discIntStepVector);
  }
  if (numDiscreteRealVars) {
    Cout << "dr_vars:\n";            write_data(Cout, dr_vars);
    Cout << "dr_l_bnds:\n";          write_data(Cout, dr_l_bnds);
    Cout << "dr_u_bnds:\n";          write_data(Cout, dr_u_bnds);
    Cout << "initialDRVPoint:\n";    write_data(Cout, initialDRVPoint);
    Cout << "discRealStepVector:\n"; write_data(Cout, discRealStepVector);
  }
#endif // DEBUG
}


void ParamStudy::final_point_to_step_vector()
{
  RealVector cv_final, drv_final; IntVector div_final;
  distribute(finalPoint, cv_final, div_final, drv_final);

  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();
  size_t j, dsi_cntr;

  // active continuous
  contStepVector.sizeUninitialized(numContinuousVars);
  for (j=0; j<numContinuousVars; ++j)
    contStepVector[j] = (cv_final[j] - initialCVPoint[j]) / numSteps;

  // active discrete int: ranges and sets
  discIntStepVector.sizeUninitialized(numDiscreteIntVars);
  for (j=0, dsi_cntr=0; j<numDiscreteIntVars; ++j)
    if (di_set_bits[j]) {
      discIntStepVector[j] = index_step(
        set_value_to_index(initialDIVPoint[j], dsi_values[dsi_cntr]),
        set_value_to_index(div_final[j],       dsi_values[dsi_cntr]), numSteps);
      ++dsi_cntr;
    }
    else
      discIntStepVector[j]
	= integer_step(div_final[j] - initialDIVPoint[j], numSteps);

  // active discrete real: sets only
  discRealStepVector.sizeUninitialized(numDiscreteRealVars);
  for (j=0; j<numDiscreteRealVars; ++j)
    discRealStepVector[j] = index_step(
      set_value_to_index(initialDRVPoint[j], dsr_values[j]),
      set_value_to_index(drv_final[j],       dsr_values[j]), numSteps);

#ifdef DEBUG
  Cout << "final_point_to_step_vector():\n";
  if (numContinuousVars) {
    Cout << "continuous step vector:\n";
    write_data(Cout, contStepVector);
  }
  if (numDiscreteIntVars) {
    Cout << "discrete int step vector:\n";
    write_data(Cout, discIntStepVector);
  }
  if (numDiscreteRealVars) {
    Cout << "discrete real step vector:\n";
    write_data(Cout, discRealStepVector);
  }
#endif // DEBUG
}


bool ParamStudy::
check_sets(const IntVector& c_steps, const IntVector& di_steps,
	   const IntVector& dr_steps)
{
  // checks for vector and centered cases: admissibility of step vectors
  // and number of steps among int/real sets
  // > check terminal set indices for out of range
  // > don't enforce that range variables remain within bounds (for now)
  // Note: this check is performed at construct time and is dependent on the
  // initial points; therefore, it is not a definitive check in the case of
  // multi-iterator execution with updated initial points.  Nonetheless,
  // verify proper set support for specified steps.

  const BitArray&    di_set_bits = iteratedModel.discrete_int_sets();
  const IntSetArray&  dsi_values = iteratedModel.discrete_set_int_values();
  const RealSetArray& dsr_values = iteratedModel.discrete_set_real_values();
  size_t j, dsi_cntr;
  bool err = false;

  // active discrete int: ranges and sets
  for (j=0, dsi_cntr=0; j<numDiscreteIntVars; ++j)
    if (di_set_bits[j]) {
      const IntSet& dsi_vals_j = dsi_values[dsi_cntr];
      int terminal_index = set_value_to_index(initialDIVPoint[j], dsi_vals_j)
	+ discIntStepVector[j] * di_steps[j];
      if (terminal_index < 0 || terminal_index >= dsi_vals_j.size()) {
	Cerr << "\nError: ParamStudy index " << terminal_index
	     << " not admissible for discrete int set of size "
	     << dsi_vals_j.size() << '.' << std::endl;
	err = true;
      }
      ++dsi_cntr;
    }

  // active discrete real: sets only
  for (j=0; j<numDiscreteRealVars; ++j) {
    const RealSet& dsr_vals_j = dsr_values[j];
    int terminal_index = set_value_to_index(initialDRVPoint[j], dsr_vals_j)
      + discRealStepVector[j] * dr_steps[j];
    if (terminal_index < 0 || terminal_index >= dsr_vals_j.size()) {
      Cerr << "\nError: ParamStudy index " << terminal_index
	   << " not admissible for discrete real set of size "
	   << dsr_vals_j.size() << '.' << std::endl;
      err = true;
    }
  }

  return err;
}

} // namespace Dakota
