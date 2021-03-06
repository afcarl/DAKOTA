/*  _______________________________________________________________________

    DAKOTA: Design Analysis Kit for Optimization and Terascale Applications
    Copyright (c) 2010, Sandia National Laboratories.
    This software is distributed under the GNU Lesser General Public License.
    For more information, see the README file in the top Dakota directory.
    _______________________________________________________________________ */

//- Class:        RelaxedVariables
//- Description:  Class implementation
//- Owner:        Mike Eldred

#include "RelaxedVariables.hpp"
#include "ProblemDescDB.hpp"
#include "dakota_data_io.hpp"
#include "dakota_data_util.hpp"

static const char rcsId[]="@(#) $Id";


namespace Dakota {

/** In this class, a relaxed data approach is used in which continuous
    and discrete arrays are combined into a single continuous array
    (integrality is relaxed; the converse of truncating reals is not
    currently supported but could be in the future if needed).
    Iterators/strategies which use this class include:
    BranchBndOptimizer.  Extract fundamental variable types and labels
    and merge continuous and discrete domains to create aggregate
    arrays and views.  */
RelaxedVariables::
RelaxedVariables(const ProblemDescDB& problem_db,
		const std::pair<short,short>& view):
  Variables(BaseConstructor(), problem_db, view)
{
  const SizetArray& vc_totals = sharedVarsData.components_totals();
  size_t num_cdv = vc_totals[0], num_cauv = vc_totals[3],
    num_ceuv  = vc_totals[6], num_csv = vc_totals[9],
    num_ddrv  = sharedVarsData.vc_lookup(DISCRETE_DESIGN_RANGE),
    num_ddsiv = sharedVarsData.vc_lookup(DISCRETE_DESIGN_SET_INT),
    num_dauiv = vc_totals[4], num_deuiv = vc_totals[7],
    num_dsrv  = sharedVarsData.vc_lookup(DISCRETE_STATE_RANGE),
    num_dssiv = sharedVarsData.vc_lookup(DISCRETE_STATE_SET_INT),
    num_ddsrv = vc_totals[2], num_daurv = vc_totals[5],
    num_deurv = vc_totals[8],
    num_acv   = num_cdv      + num_cauv  + num_ceuv  + num_csv +
                vc_totals[1] + num_dauiv + num_deuiv + vc_totals[10] +
                num_ddsrv    + num_daurv + num_deurv + vc_totals[11];

  allContinuousVars.sizeUninitialized(num_acv);

  int start = 0;
  copy_data_partial(problem_db.get_rv(
    "variables.continuous_design.initial_point"), allContinuousVars, start);
  start += num_cdv;
  merge_data_partial(problem_db.get_iv(
    "variables.discrete_design_range.initial_point"), allContinuousVars, start);
  start += num_ddrv;
  merge_data_partial(problem_db.get_iv(
    "variables.discrete_design_set_int.initial_point"),
    allContinuousVars, start);
  start += num_ddsiv;
  copy_data_partial(problem_db.get_rv(
    "variables.discrete_design_set_real.initial_point"),
    allContinuousVars, start);
  start += num_ddsrv;
  copy_data_partial(problem_db.get_rv(
    "variables.continuous_aleatory_uncertain.initial_point"),
    allContinuousVars, start);
  start += num_cauv;
  merge_data_partial(problem_db.get_iv(
    "variables.discrete_aleatory_uncertain_int.initial_point"),
    allContinuousVars, start);
  start += num_dauiv;
  copy_data_partial(problem_db.get_rv(
    "variables.discrete_aleatory_uncertain_real.initial_point"),
    allContinuousVars, start);
  start += num_daurv;
  copy_data_partial(problem_db.get_rv(
    "variables.continuous_epistemic_uncertain.initial_point"),
    allContinuousVars, start);
  start += num_ceuv;
  merge_data_partial(problem_db.get_iv(
   "variables.discrete_epistemic_uncertain_int.initial_point"),
   allContinuousVars, start);
  start += num_deuiv;
  copy_data_partial(problem_db.get_rv(
   "variables.discrete_epistemic_uncertain_real.initial_point"),
   allContinuousVars, start);
  start += num_deurv;
  copy_data_partial(problem_db.get_rv(
    "variables.continuous_state.initial_state"), allContinuousVars, start);
  start += num_csv;
  merge_data_partial(problem_db.get_iv(
    "variables.discrete_state_range.initial_state"), allContinuousVars, start);
  start += num_dsrv;
  merge_data_partial(problem_db.get_iv(
    "variables.discrete_state_set_int.initial_state"),
    allContinuousVars, start);
  start += num_dssiv;
  copy_data_partial(problem_db.get_rv(
    "variables.discrete_state_set_real.initial_state"),
    allContinuousVars, start);

  // Construct active/inactive views of all arrays
  build_views();

#ifdef REFCOUNT_DEBUG
  Cout << "Letter instantiated: variablesView active = "
       << sharedVarsData.view().first << " inactive = "
       << sharedVarsData.view().second << std::endl;
#endif
}


void RelaxedVariables::reshape(const SizetArray& vc_totals)
{
  size_t i, num_acv = 0, num_totals = vc_totals.size();
  for (i=0; i<num_totals; ++i)
    num_acv += vc_totals[i];

  allContinuousVars.resize(num_acv);

  build_views(); // construct active/inactive views of all arrays
}


void RelaxedVariables::build_active_views()
{
  // Initialize active view vectors and counts.  Don't bleed over any logic
  // about supported view combinations; rather, keep this class general and
  // encapsulated.
  const SizetArray& vc_totals = sharedVarsData.components_totals();
  size_t num_cdv = vc_totals[0], num_ddv = vc_totals[1] + vc_totals[2],
    num_mdv  = num_cdv + num_ddv, num_cauv = vc_totals[3],
    num_dauv = vc_totals[4] + vc_totals[5], num_ceuv = vc_totals[6],
    num_deuv = vc_totals[7] + vc_totals[8], num_mauv = num_cauv + num_dauv,
    num_meuv = num_ceuv + num_deuv, num_muv = num_mauv + num_meuv,
    num_csv  = vc_totals[9], num_dsv = vc_totals[10] + vc_totals[11],
    num_msv  = num_csv + num_dsv;

  // Initialize active views
  size_t cv_start, num_cv;
  switch (sharedVarsData.view().first) {
  case EMPTY:
    Cerr << "Error: active view cannot be EMPTY in RelaxedVariables."
	 << std::endl; abort_handler(-1);             break;
  case RELAXED_ALL:
    // start at the beginning
    cv_start = 0; num_cv = num_mdv + num_muv + num_msv; break;
  case RELAXED_DESIGN:
    // start at the beginning
    cv_start = 0; num_cv = num_mdv;                     break;
  case RELAXED_ALEATORY_UNCERTAIN:
    // skip over the relaxed design variables
    cv_start = num_mdv; num_cv = num_mauv;              break;
  case RELAXED_EPISTEMIC_UNCERTAIN:
    // skip over the relaxed design and aleatory variables
    cv_start = num_mdv+num_mauv;  num_cv = num_meuv;    break;
  case RELAXED_UNCERTAIN:
    // skip over the relaxed design variables
    cv_start = num_mdv; num_cv = num_muv;               break;
  case RELAXED_STATE:
    // skip over the relaxed design and uncertain variables
    cv_start = num_mdv + num_muv; num_cv = num_msv;     break;
  }
  sharedVarsData.cv_start(cv_start); sharedVarsData.cv(num_cv);
  sharedVarsData.div_start(0);       sharedVarsData.div(0);
  sharedVarsData.drv_start(0);       sharedVarsData.drv(0);
  sharedVarsData.initialize_active_components();
  if (num_cv)
    continuousVars
      = RealVector(Teuchos::View, &allContinuousVars[cv_start], num_cv);
}


void RelaxedVariables::build_inactive_views()
{
  // Initialize inactive view vectors and counts.  Don't bleed over any logic
  // about supported view combinations; rather, keep this class general and
  // encapsulated.
  const SizetArray& vc_totals = sharedVarsData.components_totals();
  size_t num_mdv  = vc_totals[0] + vc_totals[1] + vc_totals[2],
    num_mauv = vc_totals[3] + vc_totals[4] + vc_totals[5],
    num_meuv = vc_totals[6] + vc_totals[7] + vc_totals[8],
    num_muv  = num_mauv + num_meuv,
    num_msv  = vc_totals[9] + vc_totals[10] + vc_totals[11];

  // Initialize inactive views
  size_t icv_start, num_icv;
  switch (sharedVarsData.view().second) {
  case EMPTY:
    icv_start = num_icv = 0;                            break;
  case RELAXED_ALL:
    Cerr << "Error: inactive view cannot be RELAXED_ALL in RelaxedVariables."
	 << std::endl;
    abort_handler(-1);                                break;
  case RELAXED_DESIGN:
    // start at the beginning
    icv_start = 0;                  num_icv = num_mdv;  break;
  case RELAXED_ALEATORY_UNCERTAIN:
    // skip over the relaxed design variables
    icv_start = num_mdv;            num_icv = num_mauv; break;
  case RELAXED_EPISTEMIC_UNCERTAIN:
    // skip over the relaxed design and aleatory variables
    icv_start = num_mdv + num_mauv; num_icv = num_meuv; break;
  case RELAXED_UNCERTAIN:
    // skip over the relaxed design variables
    icv_start = num_mdv;            num_icv = num_muv;  break;
  case RELAXED_STATE:
    // skip over the relaxed design and uncertain variables
    icv_start = num_mdv + num_muv;  num_icv = num_msv;  break;
  }
  sharedVarsData.icv_start(icv_start); sharedVarsData.icv(num_icv);
  sharedVarsData.idiv_start(0);        sharedVarsData.idiv(0);
  sharedVarsData.idrv_start(0);        sharedVarsData.idrv(0);
  sharedVarsData.initialize_inactive_components();
  if (num_icv)
    inactiveContinuousVars
      = RealVector(Teuchos::View, &allContinuousVars[icv_start], num_icv);
}


// Reordering is required in all read/write cases that will be visible to the
// user since all derived vars classes should use the same CDV/DDV/UV/CSV/DSV
// ordering for clarity.  Neutral file I/O, binary streams, and packed buffers
// do not need to reorder (so long as read/write are consistent) since this data
// is not intended for public consumption.
void RelaxedVariables::read(std::istream& s)
{ read_data(s, allContinuousVars, all_continuous_variable_labels()); }


void RelaxedVariables::write(std::ostream& s) const
{ write_data(s, allContinuousVars, all_continuous_variable_labels()); }


void RelaxedVariables::write_aprepro(std::ostream& s) const
{ write_data_aprepro(s, allContinuousVars, all_continuous_variable_labels()); }


/** Presumes variables object is appropriately sized to receive data */
void RelaxedVariables::read_tabular(std::istream& s)
{
  // Tabular format ordering is allCV,allDIV,allDRV, or in particular,
  // cdv:cauv:ceuv:csv,ddiv:dauiv:deuiv:dsiv,ddrv:daurv:deurv:dsrv
  const SizetArray& vc_totals = sharedVarsData.components_totals();
  size_t num_cdv = vc_totals[0], num_ddiv = vc_totals[1],
    num_ddrv = vc_totals[2], num_cauv = vc_totals[3], num_dauiv = vc_totals[4],
    num_daurv = vc_totals[5], num_ceuv = vc_totals[6], num_deuiv = vc_totals[7],
    num_deurv = vc_totals[8], num_csv = vc_totals[9], num_dsiv = vc_totals[10],
    num_dsrv = vc_totals[11], num_dv = num_cdv+num_ddiv+num_ddrv,
    num_auv = num_cauv + num_dauiv + num_daurv,
    num_euv = num_ceuv + num_deuiv + num_deurv, num_uv = num_auv + num_euv;
  read_data_partial_tabular(s, 0, num_cdv, allContinuousVars);
  read_data_partial_tabular(s, num_dv, num_cauv, allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_auv, num_ceuv, allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_uv, num_csv, allContinuousVars);
  read_data_partial_tabular(s, num_cdv, num_ddiv, allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_cauv, num_dauiv, allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_auv+num_ceuv, num_deuiv,
			    allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_uv+num_csv, num_dsiv,
			    allContinuousVars);
  read_data_partial_tabular(s, num_cdv+num_ddiv, num_ddrv, allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_cauv+num_dauiv, num_daurv,
			    allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_auv+num_ceuv+num_deuiv, num_deurv,
			    allContinuousVars);
  read_data_partial_tabular(s, num_dv+num_uv+num_csv+num_dsiv, num_dsrv,
			    allContinuousVars);
}


void RelaxedVariables::write_tabular(std::ostream& s) const
{
  // Tabular format ordering is allCV,allDIV,allDRV, or in particular,
  // cdv:cauv:ceuv:csv,ddiv:dauiv:deuiv:dsiv,ddrv:daurv:deurv:dsrv
  const SizetArray& vc_totals = sharedVarsData.components_totals();
  size_t num_cdv = vc_totals[0], num_ddiv = vc_totals[1],
    num_ddrv = vc_totals[2], num_cauv = vc_totals[3], num_dauiv = vc_totals[4],
    num_daurv = vc_totals[5], num_ceuv = vc_totals[6], num_deuiv = vc_totals[7],
    num_deurv = vc_totals[8], num_csv = vc_totals[9], num_dsiv = vc_totals[10],
    num_dsrv = vc_totals[11], num_dv = num_cdv+num_ddiv+num_ddrv,
    num_auv = num_cauv + num_dauiv + num_daurv,
    num_euv = num_ceuv + num_deuiv + num_deurv, num_uv = num_auv + num_euv;
  write_data_partial_tabular(s, 0, num_cdv, allContinuousVars);
  write_data_partial_tabular(s, num_dv, num_cauv, allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_auv, num_ceuv, allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_uv, num_csv, allContinuousVars);
  write_data_partial_tabular(s, num_cdv, num_ddiv, allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_cauv, num_dauiv, allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_auv+num_ceuv, num_deuiv,
			     allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_uv+num_csv, num_dsiv,
			     allContinuousVars);
  write_data_partial_tabular(s, num_cdv+num_ddiv, num_ddrv, allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_cauv+num_dauiv, num_daurv,
			     allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_auv+num_ceuv+num_deuiv, num_deurv,
			     allContinuousVars);
  write_data_partial_tabular(s, num_dv+num_uv+num_csv+num_dsiv, num_dsrv,
			     allContinuousVars);
}

} // namespace Dakota
