/*  _______________________________________________________________________

    DAKOTA: Design Analysis Kit for Optimization and Terascale Applications
    Copyright 2014 Sandia Corporation.
    This software is distributed under the GNU Lesser General Public License.
    For more information, see the README file in the top Dakota directory.
    _______________________________________________________________________ */

//- Class:        SharedVariablesData
//- Description:  Class implementation
//- Owner:        Mike Eldred

#include "SharedVariablesData.hpp"
#include "ProblemDescDB.hpp"
#include "dakota_data_util.hpp"

//#define REFCOUNT_DEBUG

static const char rcsId[]="@(#) $Id: SharedVariablesData.cpp 6886 2010-08-02 19:13:01Z mseldre $";

namespace Dakota {


/** This constructor is the one which must build the base class data for all
    derived classes.  get_variables() instantiates a derived class letter
    and the derived constructor selects this base class constructor in its 
    initialization list (to avoid the recursion of the base class constructor
    calling get_variables() again).  Since the letter IS the representation, 
    its representation pointer is set to NULL (an uninitialized pointer causes
    problems in ~Variables). */
SharedVariablesDataRep::
SharedVariablesDataRep(const ProblemDescDB& problem_db,
		       const std::pair<short,short>& view):
  variablesId(problem_db.get_string("variables.id")),
  variablesCompsTotals(16, 0), variablesView(view), cvStart(0), divStart(0),
  dsvStart(0), drvStart(0), icvStart(0), idivStart(0), idsvStart(0),
  idrvStart(0), numCV(0), numDIV(0), numDSV(0), numDRV(0), numICV(0),
  numIDIV(0), numIDSV(0), numIDRV(0), referenceCount(1)
{
  initialize_components_totals(problem_db);
  relax_noncategorical(problem_db); // defines allRelaxedDiscrete{Int,Real}
  initialize_labels(problem_db);

  initialize_all_types();
  initialize_all_ids();

#ifdef REFCOUNT_DEBUG
  Cout << "SharedVariablesDataRep::SharedVariablesDataRep(problem_db, view) "
       << "called to build body object." << std::endl;
#endif
}


SharedVariablesDataRep::
SharedVariablesDataRep(const std::pair<short,short>& view,
		       const SizetArray& vars_comps_totals):
  variablesCompsTotals(vars_comps_totals), variablesView(view), cvStart(0),
  divStart(0), dsvStart(0), drvStart(0), icvStart(0), idivStart(0),
  idsvStart(0), idrvStart(0), numCV(0), numDIV(0), numDSV(0), numDRV(0),
  numICV(0), numIDIV(0), numIDSV(0), numIDRV(0), referenceCount(1)
{
  size_all_labels();    // totals are sufficient to size labels
  initialize_all_ids(); // totals are sufficient for forming ids
  // totals are insufficient for forming types

#ifdef REFCOUNT_DEBUG
  Cout << "SharedVariablesDataRep::SharedVariablesDataRep(view, "
       << "vars_comps_totals) called to build body object." << std::endl;
#endif
}


SharedVariablesDataRep::
SharedVariablesDataRep(const std::pair<short,short>& view,
		       const std::map<unsigned short, size_t>& vars_comps):
  variablesComponents(vars_comps), variablesView(view), , cvStart(0),
  divStart(0), dsvStart(0), drvStart(0), icvStart(0), idivStart(0),
  idsvStart(0), idrvStart(0), numCV(0), numDIV(0), numDSV(0), numDRV(0),
  numICV(0), numIDIV(0), numIDSV(0), numIDRV(0), referenceCount(1)
{
  components_to_totals();

  size_all_labels();
  initialize_all_types();
  initialize_all_ids();

#ifdef REFCOUNT_DEBUG
  Cout << "SharedVariablesDataRep::SharedVariablesDataRep(view, vars_comps) "
       << "called to build body object." << std::endl;
#endif
}


void SharedVariablesDataRep::
initialize_components_totals(ProblemDescDB& problem_db)
{
  size_t count;
  // continuous design
  if (count = problem_db.get_sizet("variables.continuous_design")) {
    variablesComponents[CONTINUOUS_DESIGN] = count;
    variablesCompsTotals[TOTAL_CDV] += count;
  }
  // discrete integer design
  if (count = problem_db.get_sizet("variables.discrete_design_range")) {
    variablesComponents[DISCRETE_DESIGN_RANGE] = count;
    variablesCompsTotals[TOTAL_DDIV] += count;
  }
  if (count = problem_db.get_sizet("variables.discrete_design_set_int")) {
    variablesComponents[DISCRETE_DESIGN_SET_INT] = count;
    variablesCompsTotals[TOTAL_DDIV] += count;
  }
  // discrete string design
  if (count = problem_db.get_sizet("variables.discrete_design_set_string")){
    variablesComponents[DISCRETE_DESIGN_SET_STRING] = count;
    variablesCompsTotals[TOTAL_DDSV] += count;
  }
  // discrete real design
  if (count = problem_db.get_sizet("variables.discrete_design_set_real")) {
    variablesComponents[DISCRETE_DESIGN_SET_REAL] = count;
    variablesCompsTotals[TOTAL_DDRV] += count;
  }
  // continuous aleatory uncertain
  if (count = problem_db.get_sizet("variables.normal_uncertain")) {
    variablesComponents[NORMAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.lognormal_uncertain")) {
    variablesComponents[LOGNORMAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.uniform_uncertain")) {
    variablesComponents[UNIFORM_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.loguniform_uncertain")) {
    variablesComponents[LOGUNIFORM_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.triangular_uncertain")) {
    variablesComponents[TRIANGULAR_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.exponential_uncertain")) {
    variablesComponents[EXPONENTIAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.beta_uncertain")) {
    variablesComponents[BETA_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.gamma_uncertain")) {
    variablesComponents[GAMMA_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.gumbel_uncertain")) {
    variablesComponents[GUMBEL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.frechet_uncertain")) {
    variablesComponents[FRECHET_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.weibull_uncertain")) {
    variablesComponents[WEIBULL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  if (count = problem_db.get_sizet("variables.histogram_uncertain.bin")) {
    variablesComponents[HISTOGRAM_BIN_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CAUV] += count;
  }
  // discrete integer aleatory uncertain
  if (count = problem_db.get_sizet("variables.poisson_uncertain")) {
    variablesComponents[POISSON_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.binomial_uncertain")) {
    variablesComponents[BINOMIAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.negative_binomial_uncertain")){
    variablesComponents[NEGATIVE_BINOMIAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.geometric_uncertain")) {
    variablesComponents[GEOMETRIC_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.hypergeometric_uncertain")) {
    variablesComponents[HYPERGEOMETRIC_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.histogram_uncertain.point_int")) {
    variablesComponents[HISTOGRAM_POINT_UNCERTAIN_INT] = count;
    variablesCompsTotals[TOTAL_DAUIV] += count;
  }
  // discrete string aleatory uncertain
  if (count =
      problem_db.get_sizet("variables.histogram_uncertain.point_string")) {
    variablesComponents[HISTOGRAM_POINT_UNCERTAIN_STRING] = count;
    variablesCompsTotals[TOTAL_DAUSV] += count;
  }
  // discrete real aleatory uncertain
  if (count = problem_db.get_sizet("variables.histogram_uncertain.point_real")){
    variablesComponents[HISTOGRAM_POINT_UNCERTAIN_REAL] = count;
    variablesCompsTotals[TOTAL_DAURV] += count;
  }
  // continuous epistemic uncertain
  if (count = problem_db.get_sizet("variables.continuous_interval_uncertain")) {
    variablesComponents[CONTINUOUS_INTERVAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_CEUV] += count;
  }
  // discrete integer epistemic uncertain
  if (count = problem_db.get_sizet("variables.discrete_interval_uncertain")){
    variablesComponents[DISCRETE_INTERVAL_UNCERTAIN] = count;
    variablesCompsTotals[TOTAL_DEUIV] += count;
  }
  if (count = problem_db.get_sizet("variables.discrete_uncertain_set_int")){
    variablesComponents[DISCRETE_UNCERTAIN_SET_INT] = count;
    variablesCompsTotals[TOTAL_DEUIV] += count;
  }
  // discrete string epistemic uncertain
  if (count = problem_db.get_sizet("variables.discrete_uncertain_set_string")) {
    variablesComponents[DISCRETE_UNCERTAIN_SET_STRING] = count;
    variablesCompsTotals[TOTAL_DEUSV] += count;
  }
  // discrete real epistemic uncertain
  if (count = problem_db.get_sizet("variables.discrete_uncertain_set_real")) {
    variablesComponents[DISCRETE_UNCERTAIN_SET_REAL] = count;
    variablesCompsTotals[TOTAL_DEURV] += count;
  }
  // continuous state
  if (count = problem_db.get_sizet("variables.continuous_state")) {
    variablesComponents[CONTINUOUS_STATE] = count;
    variablesCompsTotals[TOTAL_CSV] += count;
  }
  // discrete integer state
  if (count = problem_db.get_sizet("variables.discrete_state_range")) {
    variablesComponents[DISCRETE_STATE_RANGE] = count;
    variablesCompsTotals[TOTAL_DSIV] += count;
  }
  if (count = problem_db.get_sizet("variables.discrete_state_set_int")) {
    variablesComponents[DISCRETE_STATE_SET_INT] = count;
    variablesCompsTotals[TOTAL_DSIV] += count;
  }
  // discrete string state
  if (count = problem_db.get_sizet("variables.discrete_state_set_string")) {
    variablesComponents[DISCRETE_STATE_SET_STRING] = count;
    variablesCompsTotals[TOTAL_DSSV] += count;
  }
  // discrete real state
  if (count = problem_db.get_sizet("variables.discrete_state_set_real")) {
    variablesComponents[DISCRETE_STATE_SET_REAL] = count;
    variablesCompsTotals[TOTAL_DSRV] += count;
  }
}


void SharedVariablesDataRep::components_to_totals()
{
  variablesCompsTotals.resize(16);

  // continuous design
  variablesCompsTotals[TOTAL_CDV] = vc_lookup(CONTINUOUS_DESIGN);
  // discrete design integer
  variablesCompsTotals[TOTAL_DDIV] = vc_lookup(DISCRETE_DESIGN_RANGE)
    + vc_lookup(DISCRETE_DESIGN_SET_INT);
  // discrete design string
  variablesCompsTotals[TOTAL_DDSV] = vc_lookup(DISCRETE_DESIGN_SET_STRING);
  // discrete design real
  variablesCompsTotals[TOTAL_DDRV] = vc_lookup(DISCRETE_DESIGN_SET_REAL);
  // continuous aleatory uncertain
  variablesCompsTotals[TOTAL_CAUV]     = vc_lookup(NORMAL_UNCERTAIN)
    + vc_lookup(LOGNORMAL_UNCERTAIN)   + vc_lookup(UNIFORM_UNCERTAIN)
    + vc_lookup(LOGUNIFORM_UNCERTAIN)  + vc_lookup(TRIANGULAR_UNCERTAIN)
    + vc_lookup(EXPONENTIAL_UNCERTAIN) + vc_lookup(BETA_UNCERTAIN)
    + vc_lookup(GAMMA_UNCERTAIN)       + vc_lookup(GUMBEL_UNCERTAIN)
    + vc_lookup(FRECHET_UNCERTAIN)     + vc_lookup(WEIBULL_UNCERTAIN)
    + vc_lookup(HISTOGRAM_BIN_UNCERTAIN);
  // discrete aleatory uncertain integer
  variablesCompsTotals[TOTAL_DAUIV]  = vc_lookup(POISSON_UNCERTAIN)
    + vc_lookup(BINOMIAL_UNCERTAIN)  + vc_lookup(NEGATIVE_BINOMIAL_UNCERTAIN)
    + vc_lookup(GEOMETRIC_UNCERTAIN) + vc_lookup(HYPERGEOMETRIC_UNCERTAIN)
    + vc_lookup(HISTOGRAM_POINT_UNCERTAIN_INT);
  // discrete aleatory uncertain string
  variablesCompsTotals[TOTAL_DAUSV]
    = vc_lookup(HISTOGRAM_POINT_UNCERTAIN_STRING);
  // discrete aleatory uncertain real
  variablesCompsTotals[TOTAL_DAURV] = vc_lookup(HISTOGRAM_POINT_UNCERTAIN_REAL);
  // continuous epistemic uncertain
  variablesCompsTotals[TOTAL_CEUV] = vc_lookup(CONTINUOUS_INTERVAL_UNCERTAIN);
  // discrete epistemic uncertain integer
  variablesCompsTotals[TOTAL_DEUIV] = vc_lookup(DISCRETE_INTERVAL_UNCERTAIN)
    + vc_lookup(DISCRETE_UNCERTAIN_SET_INT);
  // discrete epistemic uncertain string
  variablesCompsTotals[TOTAL_DEUSV] = vc_lookup(DISCRETE_UNCERTAIN_SET_STRING);
  // discrete epistemic uncertain real
  variablesCompsTotals[TOTAL_DEURV] = vc_lookup(DISCRETE_UNCERTAIN_SET_REAL);
  // continuous state
  variablesCompsTotals[TOTAL_CSV] = vc_lookup(CONTINUOUS_STATE);
  // discrete state integer
  variablesCompsTotals[TOTAL_DSIV] = vc_lookup(DISCRETE_STATE_RANGE)
    + vc_lookup(DISCRETE_STATE_SET_INT);
  // discrete state string
  variablesCompsTotals[TOTAL_DSSV] = vc_lookup(DISCRETE_STATE_SET_STRING);
  // discrete state real
  variablesCompsTotals[TOTAL_DSRV] = vc_lookup(DISCRETE_STATE_SET_REAL);
}


void SharedVariablesDataRep::relax_noncategorical(ProblemDescDB& problem_db)
{
  // full length keys, init to false
  allRelaxedDiscreteInt.resize(
    variablesCompsTotals[TOTAL_DDIV] + variablesCompsTotals[TOTAL_DAUIV] +
    variablesCompsTotals[TOTAL_DEUIV] + variablesCompsTotals[TOTAL_DSIV]);
  allRelaxedDiscreteReal.resize(
    variablesCompsTotals[TOTAL_DDRV]  + variablesCompsTotals[TOTAL_DAURV] +
    variablesCompsTotals[TOTAL_DEURV] + variablesCompsTotals[TOTAL_DSRV]);

  // use of RELAXED domain is independent of active view
  bool relax = ( variablesView.first == RELAXED_ALL ||
		 ( variablesView.first >= RELAXED_DESIGN &&
		   variablesView.first <= RELAXED_STATE ) );
  if (!relax)
    return;

  // Note: NIDR handles empty and unit length specs

  const BitArray& ddrv_cat = problem_db.get_ba(
    "variables.discrete_design_range.categorical");
  const BitArray& ddsiv_cat = problem_db.get_ba(
    "variables.discrete_design_set_int.categorical");
  const BitArray& ddsrv_cat = problem_db.get_ba(
    "variables.discrete_design_set_real.categorical");

  const BitArray& puv_cat = problem_db.get_ba(
    "variables.poisson_uncertain.categorical");
  const BitArray& buv_cat = problem_db.get_ba(
    "variables.binomial_uncertain.categorical");
  const BitArray& nbuv_cat = problem_db.get_ba(
    "variables.negative_binomial_uncertain.categorical");
  const BitArray& guv_cat = problem_db.get_ba(
    "variables.geometric_uncertain.categorical");
  const BitArray& hguv_cat = problem_db.get_ba(
    "variables.hypergeometric_uncertain.categorical");
  const BitArray& hupiv_cat = problem_db.get_ba(
    "variables.histogram_uncertain.point_int.categorical");
  const BitArray& huprv_cat = problem_db.get_ba(
    "variables.histogram_uncertain.point_real.categorical");

  const BitArray& durv_cat = problem_db.get_ba(
    "variables.discrete_interval_uncertain.categorical");
  const BitArray& dusiv_cat = problem_db.get_ba(
    "variables.discrete_uncertain_set_int.categorical");
  const BitArray& dusrv_cat = problem_db.get_ba(
    "variables.discrete_uncertain_set_real.categorical");

  const BitArray& dsrv_cat = problem_db.get_ba(
    "variables.discrete_state_range.categorical");
  const BitArray& dssiv_cat = problem_db.get_ba(
    "variables.discrete_state_set_int.categorical");
  const BitArray& dssrv_cat = problem_db.get_ba(
    "variables.discrete_state_set_real.categorical");

  /* Would require negation!
  size_t offset_di = 0, offset_dr = 0;
  copy_data_partial(ddrv_cat,  allRelaxedDiscreteInt, offset_di);
  offset_di += ddrv_cat.size();
  copy_data_partial(ddsiv_cat, allRelaxedDiscreteInt, offset_di);
  offset_di += ddsiv_cat.size();
  copy_data_partial(ddsrv_cat, allRelaxedDiscreteReal);
  offset_dr += ddsrv_cat.size();
  */

  size_t i, ardi_cntr = 0, ardr_cntr = 0, num_ddrv = ddrv_cat.size(),
    num_ddsiv = ddsiv_cat.size(), num_ddsrv = ddsrv_cat.size(),
    num_puv   = puv_cat.size(),   num_buv   = buv_cat.size(),
    num_nbuv  = nbuv_cat.size(),  num_guv   = guv_cat.size(),
    num_hguv  = hguv_cat.size(),  num_hupiv = hupiv_cat.size(),
    num_huprv = huprv_cat.size(), num_durv  = durv_cat.size(),
    num_dusiv = dusiv_cat.size(), num_dusrv = dusrv_cat.size(),
    num_dsrv  = dsrv_cat.size(),  num_dssiv = dssiv_cat.size(),
    num_dssrv = dssrv_cat.size();
  // discrete design
  for (i=0; i<num_ddrv; ++i, ++ardi_cntr)
    if (!ddrv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_ddsiv; ++i, ++ardi_cntr)
    if (!ddsiv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_ddsrv; ++i, ++ardr_cntr)
    if (!ddsrv_cat[i]) allRelaxedDiscreteReal.set(ardr_cntr);
  // discrete aleatory uncertain
  for (i=0; i<num_puv; ++i, ++ardi_cntr)
    if (!puv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_buv; ++i, ++ardi_cntr)
    if (!buv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_nbuv; ++i, ++ardi_cntr)
    if (!nbuv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_guv; ++i, ++ardi_cntr)
    if (!guv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_hguv; ++i, ++ardi_cntr)
    if (!hguv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_hupiv; ++i, ++ardi_cntr)
    if (!hupiv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_huprv; ++i, ++ardr_cntr)
    if (!huprv_cat[i]) allRelaxedDiscreteReal.set(ardr_cntr);
  // discrete epistemic uncertain
  for (i=0; i<num_durv; ++i, ++ardi_cntr)
    if (!durv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_dusiv; ++i, ++ardi_cntr)
    if (!dusiv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_dusrv; ++i, ++ardr_cntr)
    if (!dusrv_cat[i]) allRelaxedDiscreteReal.set(ardr_cntr);
  // discrete state
  for (i=0; i<num_dsrv; ++i, ++ardi_cntr)
    if (!dsrv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_dssiv; ++i, ++ardi_cntr)
    if (!dssiv_cat[i]) allRelaxedDiscreteInt.set(ardi_cntr);
  for (i=0; i<num_dssrv; ++i, ++ardr_cntr)
    if (!dssrv_cat[i]) allRelaxedDiscreteReal.set(ardr_cntr);
}


void SharedVariablesDataRep::initialize_labels(ProblemDescDB& problem_db)
{
  size_t i, ardi_cntr = 0, ardr_cntr = 0,
    acv_offset = 0, adiv_offset = 0, adsv_offset = 0, adrv_offset = 0,
    num_acv
      = variablesCompsTotals[TOTAL_CDV]  + variablesCompsTotals[TOTAL_CAUV]
      + variablesCompsTotals[TOTAL_CEUV] + variablesCompsTotals[TOTAL_CSV],
    num_adiv = allRelaxedDiscreteInt.size(), // updated below for relax non-cat
    num_adrv = allRelaxedDiscreteReal.size(),// updated below for relax non-cat
    num_adsv                                 // always categorical
      = variablesCompsTotals[TOTAL_DDSV]  + variablesCompsTotals[TOTAL_DAUSV]
      + variablesCompsTotals[TOTAL_DEUSV] + variablesCompsTotals[TOTAL_DSSV];

  bool relax = (allRelaxedDiscreteInt.any() || allRelaxedDiscreteReal.any());
  if (relax) { // include discrete design/uncertain/state
    size_t num_relax_int  = allRelaxedDiscreteInt.count(),
           num_relax_real = allRelaxedDiscreteReal.count();
    num_acv  += num_relax_int + num_relax_real;
    num_adiv -= num_relax_int;
    num_adrv -= num_relax_real;
  }

  allContinuousLabels.resize(boost::extents[num_acv]);    // updated size
  allDiscreteIntLabels.resize(boost::extents[num_adiv]);  // updated size
  allDiscreteStringLabels.resize(boost::extents[num_adsv]);
  allDiscreteRealLabels.resize(boost::extents[num_adrv]); // updated size

  // design
  const StringArray& cdv_labels
    = problem_db.get_sa("variables.continuous_design.labels");
  const StringArray& ddrv_labels
    = problem_db.get_sa("variables.discrete_design_range.labels");
  const StringArray& ddsiv_labels
    = problem_db.get_sa("variables.discrete_design_set_int.labels");
  const StringArray& ddssv_labels
    = problem_db.get_sa("variables.discrete_design_set_string.labels");
  const StringArray& ddsrv_labels
    = problem_db.get_sa("variables.discrete_design_set_real.labels");
  copy_data_partial(cdv_labels, allContinuousLabels, acv_offset);
  acv_offset += cdv_labels.size();
  copy_data_partial(ddssv_labels, allDiscreteStringLabels, adsv_offset);
  adsv_offset += ddssv_labels.size();
  if (relax) {
    size_t num_ddrv  = ddrv_labels.size(), num_ddsiv = ddsiv_labels.size(),
           num_ddsrv = ddsrv_labels.size();
    for (i=0; i<num_ddrv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousLabels[acv_offset++]    = ddrv_labels[i];
      else
	allDiscreteIntLabels[adiv_offset++]  = ddrv_labels[i];
    for (i=0; i<num_ddsiv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousLabels[acv_offset++]    = ddsiv_labels[i];
      else
	allDiscreteIntLabels[adiv_offset++]  = ddsiv_labels[i];
    for (i=0; i<num_ddsrv; ++i, ++ardr_cntr)
      if (allRelaxedDiscreteReal[ardr_cntr])
	allContinuousLabels[acv_offset++]    = ddsrv_labels[i];
      else
	allDiscreteRealLabels[adrv_offset++] = ddsrv_labels[i];
  }
  else {
    copy_data_partial(ddrv_labels, allDiscreteIntLabels, adiv_offset);
    adiv_offset += ddrv_labels.size();
    copy_data_partial(ddsiv_labels, allDiscreteIntLabels, adiv_offset);
    adiv_offset += ddsiv_labels.size();
    copy_data_partial(ddssv_labels, allDiscreteStringLabels, adsv_offset);
    adsv_offset += ddssv_labels.size();
    copy_data_partial(ddsrv_labels, allDiscreteRealLabels, adrv_offset);
    adrv_offset += ddsrv_labels.size();
  }

  // aleatory uncertain
  const StringArray& cauv_labels
    = problem_db.get_sa("variables.continuous_aleatory_uncertain.labels")
  const StringArray& dauiv_labels
    = problem_db.get_sa("variables.discrete_aleatory_uncertain_int.labels");
  const StringArray& dausv_labels
    = problem_db.get_sa("variables.discrete_aleatory_uncertain_string.labels");
  const StringArray& daurv_labels
    = problem_db.get_sa("variables.discrete_aleatory_uncertain_real.labels");
  copy_data_partial(cauv_labels, allContinuousLabels, acv_offset);
  acv_offset += cauv_labels.size();
  copy_data_partial(dausv_labels, allDiscreteStringLabels, adsv_offset);
  adsv_offset += dausv_labels.size();

  // TO HERE

  if (relax) {
    // Note: for generality/consistency, we also support {,non}categorical for
    // all discrete aleatory random variables, even though continuous relaxation
    // is a logical stretch for poisson,{,negative_}binominal,{,hyper}geometric
    size_t dauiv_index = 0;
    for (i=0; i<num_puv; ++i, ++dauiv_index)
      if (puv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_buv; ++i, ++dauiv_index)
      if (buv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_nbuv; ++i, ++dauiv_index)
      if (nbuv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_guv; ++i, ++dauiv_index)
      if (guv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_hguv; ++i, ++dauiv_index)
      if (hguv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_hupiv; ++i, ++dauiv_index)
      if (hupiv_cat[i]) 
	allDiscreteIntLabels[adiv_offset++] = dauiv_labels[dauiv_index];
      else
	allContinuousLabels[acv_offset++]   = dauiv_labels[dauiv_index];
    for (i=0; i<num_huprv; ++i)
      if (huprv_cat[i])	allDiscreteRealLabels[adrv_offset++] = daurv_labels[i];
      else              allContinuousLabels[acv_offset++]    = daurv_labels[i];
  }
  else {
    copy_data_partial(dauiv_labels, allDiscreteIntLabels, adiv_offset);
    adiv_offset += dauiv_labels.size();
    copy_data_partial(dausv_labels, allDiscreteStringLabels, adsv_offset);
    adsv_offset += dausv_labels.size();
    copy_data_partial(daurv_labels, allDiscreteRealLabels, adrv_offset);
    adrv_offset += daurv_labels.size();
  }

  // epistemic uncertain
  copy_data_partial(problem_db.get_sa(
    "variables.continuous_epistemic_uncertain.labels"),
    allContinuousLabels, acv_offset);
  acv_offset += num_ceuv;
  const StringArray& deuiv_labels
    = problem_db.get_sa("variables.discrete_epistemic_uncertain_int.labels");
  const StringArray& deurv_labels
    = problem_db.get_sa("variables.discrete_epistemic_uncertain_real.labels");
  if (relax) {
    size_t deuiv_index = 0;
    for (i=0; i<num_durv; ++i, ++deuiv_index)
      if (durv_cat[i])
	allDiscreteIntLabels[adiv_offset++] = deuiv_labels[deuiv_index];
      else
	allContinuousLabels[acv_offset++]   = deuiv_labels[deuiv_index];
    for (i=0; i<num_dusiv; ++i, ++deuiv_index)
      if (dusiv_cat[i])
	allDiscreteIntLabels[adiv_offset++] = deuiv_labels[deuiv_index];
      else
	allContinuousLabels[acv_offset++]   = deuiv_labels[deuiv_index];
    for (i=0; i<num_dusrv; ++i)
      if (dusrv_cat[i]) allDiscreteRealLabels[adrv_offset++] = deurv_labels[i];
      else              allContinuousLabels[acv_offset++]    = deurv_labels[i];
  }
  else {
    copy_data_partial(deuiv_labels, allDiscreteIntLabels,  adiv_offset);
    adiv_offset += num_deuiv;
    copy_data_partial(deurv_labels, allDiscreteRealLabels, adrv_offset);
    adrv_offset += num_deurv;
  }

  // state
  copy_data_partial(problem_db.get_sa("variables.continuous_state.labels"),
    allContinuousLabels, acv_offset);
  acv_offset += num_csv;
  const StringArray& dsrv_labels
    = problem_db.get_sa("variables.discrete_state_range.labels");
  const StringArray& dssiv_labels
    = problem_db.get_sa("variables.discrete_state_set_int.labels");
  const StringArray& dssrv_labels
    = problem_db.get_sa("variables.discrete_state_set_real.labels");
  if (relax) {
    for (i=0; i<num_dsrv; ++i)
      if (dsrv_cat[i]) allDiscreteIntLabels[adiv_offset++]   = dsrv_labels[i];
      else             allContinuousLabels[acv_offset++]     = dsrv_labels[i];
    for (i=0; i<num_dssiv; ++i)
      if (dssiv_cat[i])	allDiscreteIntLabels[adiv_offset++]  = dssiv_labels[i];
      else              allContinuousLabels[acv_offset++]    = dssiv_labels[i];
    for (i=0; i<num_dssrv; ++i)
      if (dssrv_cat[i])	allDiscreteRealLabels[adrv_offset++] = dssrv_labels[i];
      else              allContinuousLabels[acv_offset++]    = dssrv_labels[i];
  }
  else {
    copy_data_partial(dsrv_labels,  allDiscreteIntLabels,  adiv_offset);
    adiv_offset += num_dsrv;
    copy_data_partial(dssiv_labels, allDiscreteIntLabels,  adiv_offset);
    adiv_offset += num_dssiv;
    copy_data_partial(dssrv_labels, allDiscreteRealLabels, adrv_offset);
    adrv_offset += num_dssrv;
  }
}


void SharedVariablesDataRep::initialize_all_types()
{
  size_t i, acv_cntr = 0, adiv_cntr = 0, adsv_cntr = 0, adrv_cntr = 0,
    num_acv
      = variablesCompsTotals[TOTAL_CDV]  + variablesCompsTotals[TOTAL_CAUV]
      + variablesCompsTotals[TOTAL_CEUV] + variablesCompsTotals[TOTAL_CSV],
    num_adiv = allRelaxedDiscreteInt.size(),  // to be updated
    num_adrv = allRelaxedDiscreteReal.size(), // to be updated
    num_adsv = variablesCompsTotals[TOTAL_DDSV]
      + variablesCompsTotals[TOTAL_DAUSV] + variablesCompsTotals[TOTAL_DEUSV]
      + variablesCompsTotals[TOTAL_DSSV];

  bool relax = (allRelaxedDiscreteInt.any() || allRelaxedDiscreteReal.any());
  if (relax) { // include discrete design/uncertain/state
    size_t num_relax_int  = allRelaxedDiscreteInt.count(),
           num_relax_real = allRelaxedDiscreteReal.count();
    num_acv  += num_relax_int + num_relax_real;
    num_adiv -= num_relax_int;
    num_adrv -= num_relax_real;
  }

  allContinuousTypes.resize(boost::extents[num_acv]);
  allDiscreteIntTypes.resize(boost::extents[num_adiv]);
  allDiscreteStringTypes.resize(boost::extents[num_adsv]);
  allDiscreteRealTypes.resize(boost::extents[num_adrv]);

  // DESIGN
  size_t num_cdv = vc_lookup(CONTINUOUS_DESIGN),
    num_ddrv  = vc_lookup(DISCRETE_DESIGN_RANGE),
    num_ddsiv = vc_lookup(DISCRETE_DESIGN_SET_INT),
    num_ddssv = vc_lookup(DISCRETE_DESIGN_SET_STRING),
    num_ddsrv = vc_lookup(DISCRETE_DESIGN_SET_REAL);
  for (i=0; i<num_cdv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = CONTINUOUS_DESIGN;
  for (i=0; i<num_ddssv; ++i, ++adst_cntr)
    allDiscreteStringTypes[adst_cntr] = DISCRETE_DESIGN_SET_STRING;
  if (relax) {
    for (i=0; i<num_ddrv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_DESIGN_RANGE;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_DESIGN_RANGE;
    for (i=0; i<num_ddsiv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_DESIGN_SET_INT;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_DESIGN_SET_INT;
    for (i=0; i<num_ddsrv; ++i, ++ardr_cntr)
      if (allRelaxedDiscreteReal[ardr_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_DESIGN_SET_REAL;
      else
	allDiscreteRealTypes[adrt_cntr++] = DISCRETE_DESIGN_SET_REAL;
  }
  else {
    for (i=0; i<num_ddrv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_DESIGN_RANGE;
    for (i=0; i<num_ddsiv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_DESIGN_SET_INT;
    for (i=0; i<num_ddsrv; ++i, ++adrt_cntr)
      allDiscreteRealTypes[adrt_cntr] = DISCRETE_DESIGN_SET_REAL;
  }

  // ALEATORY UNCERTAIN
  size_t num_nuv  = vc_lookup(NORMAL_UNCERTAIN),
    num_lnuv = vc_lookup(LOGNORMAL_UNCERTAIN),
    num_uuv  = vc_lookup(UNIFORM_UNCERTAIN),
    num_luuv = vc_lookup(LOGUNIFORM_UNCERTAIN),
    num_tuv  = vc_lookup(TRIANGULAR_UNCERTAIN),
    num_exuv = vc_lookup(EXPONENTIAL_UNCERTAIN),
    num_beuv = vc_lookup(BETA_UNCERTAIN),
    num_gauv = vc_lookup(GAMMA_UNCERTAIN),
    num_guuv = vc_lookup(GUMBEL_UNCERTAIN),
    num_fuv  = vc_lookup(FRECHET_UNCERTAIN),
    num_wuv  = vc_lookup(WEIBULL_UNCERTAIN),
    num_hbuv = vc_lookup(HISTOGRAM_BIN_UNCERTAIN),
    num_puv   = vc_lookup(POISSON_UNCERTAIN),
    num_biuv  = vc_lookup(BINOMIAL_UNCERTAIN),
    num_nbuv  = vc_lookup(NEGATIVE_BINOMIAL_UNCERTAIN),
    num_geuv  = vc_lookup(GEOMETRIC_UNCERTAIN),
    num_hguv  = vc_lookup(HYPERGEOMETRIC_UNCERTAIN),
    num_hpuiv = vc_lookup(HISTOGRAM_POINT_UNCERTAIN_INT),
    num_hpusv = vc_lookup(HISTOGRAM_POINT_UNCERTAIN_STRING),
    num_hpurv = vc_lookup(HISTOGRAM_POINT_UNCERTAIN_REAL);
  for (i=0; i<num_nuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = NORMAL_UNCERTAIN;
  for (i=0; i<num_lnuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = LOGNORMAL_UNCERTAIN;
  for (i=0; i<num_uuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = UNIFORM_UNCERTAIN;
  for (i=0; i<num_luuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = LOGUNIFORM_UNCERTAIN;
  for (i=0; i<num_tuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = TRIANGULAR_UNCERTAIN;
  for (i=0; i<num_exuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = EXPONENTIAL_UNCERTAIN;
  for (i=0; i<num_beuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = BETA_UNCERTAIN;
  for (i=0; i<num_gauv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = GAMMA_UNCERTAIN;
  for (i=0; i<num_guuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = GUMBEL_UNCERTAIN;
  for (i=0; i<num_fuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = FRECHET_UNCERTAIN;
  for (i=0; i<num_wuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = WEIBULL_UNCERTAIN;
  for (i=0; i<num_hbuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = HISTOGRAM_BIN_UNCERTAIN;
  for (i=0; i<num_hpusv; ++i, ++adst_cntr)
    allDiscreteStringTypes[adst_cntr] = HISTOGRAM_POINT_UNCERTAIN_STRING;
  if (relax) {
    for (i=0; i<num_puv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = POISSON_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = POISSON_UNCERTAIN;
    for (i=0; i<num_biuv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = BINOMIAL_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = BINOMIAL_UNCERTAIN;
    for (i=0; i<num_nbuv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = NEGATIVE_BINOMIAL_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = NEGATIVE_BINOMIAL_UNCERTAIN;
    for (i=0; i<num_geuv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = GEOMETRIC_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = GEOMETRIC_UNCERTAIN;
    for (i=0; i<num_hguv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = HYPERGEOMETRIC_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = HYPERGEOMETRIC_UNCERTAIN;
    for (i=0; i<num_hpuiv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = HISTOGRAM_POINT_UNCERTAIN_INT;
      else
	allDiscreteIntTypes[adit_cntr++] = HISTOGRAM_POINT_UNCERTAIN_INT;
    for (i=0; i<num_hpurv; ++i, ++ardr_cntr)
      if (allRelaxedDiscreteReal[ardr_cntr])
	allContinuousTypes[act_cntr++] = HISTOGRAM_POINT_UNCERTAIN_REAL;
      else
	allDiscreteRealTypes[adrt_cntr++] = HISTOGRAM_POINT_UNCERTAIN_REAL;
  }
  else {
    for (i=0; i<num_puv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = POISSON_UNCERTAIN;
    for (i=0; i<num_biuv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = BINOMIAL_UNCERTAIN;
    for (i=0; i<num_nbuv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = NEGATIVE_BINOMIAL_UNCERTAIN;
    for (i=0; i<num_geuv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = GEOMETRIC_UNCERTAIN;
    for (i=0; i<num_hguv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = HYPERGEOMETRIC_UNCERTAIN;
    for (i=0; i<num_hpuiv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = HISTOGRAM_POINT_UNCERTAIN_INT;
    for (i=0; i<num_hpurv; ++i, ++adrt_cntr)
      allDiscreteRealTypes[adrt_cntr] = HISTOGRAM_POINT_UNCERTAIN_REAL;
  }

  // EPISTEMIC UNCERTAIN
  size_t num_ciuv = vc_lookup(CONTINUOUS_INTERVAL_UNCERTAIN),
    num_diuv  = vc_lookup(DISCRETE_INTERVAL_UNCERTAIN),
    num_dusiv = vc_lookup(DISCRETE_UNCERTAIN_SET_INT),
    num_dussv = vc_lookup(DISCRETE_UNCERTAIN_SET_STRING),
    num_dusrv = vc_lookup(DISCRETE_UNCERTAIN_SET_REAL);
  for (i=0; i<num_ciuv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = CONTINUOUS_INTERVAL_UNCERTAIN;
  for (i=0; i<num_dussv; ++i, ++adst_cntr)
    allDiscreteStringTypes[adst_cntr] = DISCRETE_UNCERTAIN_SET_STRING;
  if (relax) {
    for (i=0; i<num_diuv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_INTERVAL_UNCERTAIN;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_INTERVAL_UNCERTAIN;
    for (i=0; i<num_dusiv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_UNCERTAIN_SET_INT;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_UNCERTAIN_SET_INT;
    for (i=0; i<num_dusrv; ++i, ++ardr_cntr)
      if (allRelaxedDiscreteReal[ardr_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_UNCERTAIN_SET_REAL;
      else
	allDiscreteRealTypes[adrt_cntr++] = DISCRETE_UNCERTAIN_SET_REAL;
  }
  else {
    for (i=0; i<num_diuv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_INTERVAL_UNCERTAIN;
    for (i=0; i<num_dusiv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_UNCERTAIN_SET_INT;
    for (i=0; i<num_dusrv; ++i, ++adrt_cntr)
      allDiscreteRealTypes[adrt_cntr] = DISCRETE_UNCERTAIN_SET_REAL;
  }

  // STATE
  size_t num_csv = vc_lookup(CONTINUOUS_STATE),
    num_dsrv  = vc_lookup(DISCRETE_STATE_RANGE),
    num_dssiv = vc_lookup(DISCRETE_STATE_SET_INT),
    num_dsssv = vc_lookup(DISCRETE_STATE_SET_STRING),
    num_dssrv = vc_lookup(DISCRETE_STATE_SET_REAL);
  for (i=0; i<num_csv; ++i, ++act_cntr)
    allContinuousTypes[act_cntr] = CONTINUOUS_STATE;
  for (i=0; i<num_dsssv; ++i, ++adst_cntr)
    allDiscreteStringlTypes[adst_cntr] = DISCRETE_STATE_SET_STRING;
  if (relax) {
    for (i=0; i<num_dsrv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_STATE_RANGE;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_STATE_RANGE;
    for (i=0; i<num_dssiv; ++i, ++ardi_cntr)
      if (allRelaxedDiscreteInt[ardi_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_STATE_SET_INT;
      else
	allDiscreteIntTypes[adit_cntr++] = DISCRETE_STATE_SET_INT;
    for (i=0; i<num_dssrv; ++i, ++ardr_cntr)
      if (allRelaxedDiscreteReal[ardr_cntr])
	allContinuousTypes[act_cntr++] = DISCRETE_STATE_SET_REAL;
      else
	allDiscreteRealTypes[adrt_cntr++] = DISCRETE_STATE_SET_REAL;
  }
  else {
    for (i=0; i<num_dsrv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_STATE_RANGE;
    for (i=0; i<num_dssiv; ++i, ++adit_cntr)
      allDiscreteIntTypes[adit_cntr] = DISCRETE_STATE_SET_INT;
    for (i=0; i<num_dssrv; ++i, ++adrt_cntr)
      allDiscreteRealTypes[adrt_cntr] = DISCRETE_STATE_SET_REAL;
  }
}


void SharedVariablesDataRep::initialize_all_ids()
{
  size_t i, id, acv_cntr = 0, num_cdv = variablesCompsTotals[TOTAL_CDV],
    num_ddiv  = variablesCompsTotals[TOTAL_DDIV],
    num_ddrv  = variablesCompsTotals[TOTAL_DDRV],
    num_cauv  = variablesCompsTotals[TOTAL_CAUV],
    num_dauiv = variablesCompsTotals[TOTAL_DAUIV],
    num_daurv = variablesCompsTotals[TOTAL_DAURV],
    num_ceuv  = variablesCompsTotals[TOTAL_CEUV],
    num_deuiv = variablesCompsTotals[TOTAL_DEUIV],
    num_deurv = variablesCompsTotals[TOTAL_DEURV],
    num_csv   = variablesCompsTotals[TOTAL_CSV],
    num_dsiv  = variablesCompsTotals[TOTAL_DSIV],
    num_dsrv  = variablesCompsTotals[TOTAL_DSRV],
    num_acv   = num_cdv + num_cauv + num_ceuv + num_csv;

  // aggregateBitArrays defined over all discrete int,real
  bool relax = (allRelaxedDiscreteInt.any() || allRelaxedDiscreteReal.any());
  if (relax) // include discrete design/uncertain/state
    num_acv += allRelaxedDiscreteInt.count() + allRelaxedDiscreteReal.count();
  allContinuousIds.resize(boost::extents[num_acv]);

  // DESIGN
  id = 1; // identifiers are 1-based (indices are 0-based)
  for (i=0; i<num_cdv; ++i, ++acv_cntr, ++id)
    allContinuousIds[acv_cntr] = id;
  if (relax) {
    for (i=0; i<num_ddiv; ++i, ++adiv_cntr, ++id)
      if (allRelaxedDiscreteInt[adiv_cntr])
	allContinuousIds[acv_cntr++] = id;
    id += num_ddsv;
    for (i=0; i<num_ddrv; ++i, ++adrv_cntr, ++id)
      if (allRelaxedDiscreteReal[adrv_cntr])
	allContinuousIds[acv_cntr++] = id;
  }
  else
    id += num_ddiv + num_ddsv + num_ddrv;

  // ALEATORY UNCERTAIN
  for (i=0; i<num_cauv; ++i, ++acv_cntr, ++id)
    allContinuousIds[acv_cntr] = id;
  if (relax) {
    for (i=0; i<num_dauiv; ++i, ++adiv_cntr, ++id)
      if (allRelaxedDiscreteInt[adiv_cntr])
	allContinuousIds[acv_cntr++] = id;
    id += num_dausv;
    for (i=0; i<num_daurv; ++i, ++adrv_cntr, ++id)
      if (allRelaxedDiscreteReal[adrv_cntr])
	allContinuousIds[acv_cntr++] = id;
  }
  else
    id += num_dauiv + num_dausv + num_daurv;

  // EPISTEMIC UNCERTAIN
  for (i=0; i<num_ceuv; ++i, ++acv_cntr, ++id)
    allContinuousIds[acv_cntr] = id;
  if (relax) {
    for (i=0; i<num_deuiv; ++i, ++adiv_cntr, ++id)
      if (allRelaxedDiscreteInt[adiv_cntr])
	allContinuousIds[acv_cntr++] = id;
    id += num_deusv;
    for (i=0; i<num_deurv; ++i, ++adrv_cntr, ++id)
      if (allRelaxedDiscreteReal[adrv_cntr])
	allContinuousIds[acv_cntr++] = id;
  }
  else
    id += num_deuiv + num_deusv + num_deurv;

  // STATE
  for (i=0; i<num_csv; ++i, ++acv_cntr, ++id)
    allContinuousIds[acv_cntr] = id;
  if (relax) {
    for (i=0; i<num_dsiv; ++i, ++adiv_cntr, ++id)
      if (allRelaxedDiscreteInt[adiv_cntr])
	allContinuousIds[acv_cntr++] = id;
    id += num_dssv;
    for (i=0; i<num_dsrv; ++i, ++adrv_cntr, ++id)
      if (allRelaxedDiscreteReal[adrv_cntr])
	allContinuousIds[acv_cntr++] = id;
  }

  /*
  // initialize relaxedDiscreteIds
  if (relax) {
    size_t i, offset = 1, cntr = 0,
      num_mdv  = num_cdv  + num_ddv,  num_mauv = num_cauv + num_dauv,
      num_meuv = num_ceuv + num_deuv, num_muv  = num_mauv + num_meuv;
    switch (variablesView.first) {
    case RELAXED_ALL:
      relaxedDiscreteIds.resize(num_ddv + num_dauv + num_deuv + num_dsv);
      offset += num_cdv;
      for (i=0; i<num_ddv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      offset += num_ddv + num_cauv;
      for (i=0; i<num_dauv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      offset += num_dauv + num_ceuv;
      for (i=0; i<num_deuv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      offset += num_deuv + num_csv;
      for (i=0; i<num_dsv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      break;
    case RELAXED_DESIGN:
      relaxedDiscreteIds.resize(num_ddv);
      offset += num_cdv;
      for (i=0; i<num_ddv; ++i)
	relaxedDiscreteIds[i] = i + offset;
      break;
    case RELAXED_ALEATORY_UNCERTAIN:
      relaxedDiscreteIds.resize(num_dauv);
      offset += num_mdv + num_cauv;
      for (i=0; i<num_dauv; ++i, ++cntr)
	relaxedDiscreteIds[i] = i + offset;
      break;
    case RELAXED_EPISTEMIC_UNCERTAIN:
      relaxedDiscreteIds.resize(num_deuv);
      offset += num_mdv + num_mauv + num_ceuv;
      for (i=0; i<num_deuv; ++i, ++cntr)
	relaxedDiscreteIds[i] = i + offset;
      break;
    case RELAXED_UNCERTAIN:
      relaxedDiscreteIds.resize(num_dauv + num_deuv);
      offset += num_mdv + num_cauv;
      for (i=0; i<num_dauv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      offset += num_dauv + num_ceuv;
      for (i=0; i<num_deuv; ++i, ++cntr)
	relaxedDiscreteIds[cntr] = i + offset;
      break;
    case RELAXED_STATE:
      relaxedDiscreteIds.resize(num_dsv);
      offset += num_mdv + num_muv + num_csv;
      for (i=0; i<num_dsv; ++i)
	relaxedDiscreteIds[i] = i + offset;
      break;
    }
  }
  */
}


void SharedVariablesDataRep::initialize_active_components()
{
  size_t i, j, num_cdv = variablesCompsTotals[TOTAL_CDV],
    num_ddiv  = variablesCompsTotals[TOTAL_DDIV],
    num_ddsv  = variablesCompsTotals[TOTAL_DDSV],
    num_ddrv  = variablesCompsTotals[TOTAL_DDRV],
    num_cauv  = variablesCompsTotals[TOTAL_CAUV],
    num_dauiv = variablesCompsTotals[TOTAL_DAUIV],
    num_dausv = variablesCompsTotals[TOTAL_DAUSV],
    num_daurv = variablesCompsTotals[TOTAL_DAURV],
    num_ceuv  = variablesCompsTotals[TOTAL_CEUV],
    num_deuiv = variablesCompsTotals[TOTAL_DEUIV],
    num_deusv = variablesCompsTotals[TOTAL_DEUSV],
    num_deurv = variablesCompsTotals[TOTAL_DEURV],
    num_csv   = variablesCompsTotals[TOTAL_CSV],
    num_dsiv  = variablesCompsTotals[TOTAL_DSIV],
    num_dssv  = variablesCompsTotals[TOTAL_DSSV],
    num_dsrv  = variablesCompsTotals[TOTAL_DSRV],
    cv_end    = cvStart  + numCV,  div_end  = divStart + numDIV,
    drv_end   = drvStart + numDRV, acv_cntr = 0,
    adiv_cntr = 0, adsv_cntr = 0, adrv_cntr = 0;

  activeVarsCompsTotals.resize(16);

  // TO DO: review this logic for case with relaxed discrete vars

  // design
  activeVarsCompsTotals[TOTAL_CDV]
    = (acv_cntr  >=  cvStart &&  acv_cntr <  cv_end) ? num_cdv  : 0;
  activeVarsCompsTotals[TOTAL_DDIV]
    = (adiv_cntr >= divStart && adiv_cntr < div_end) ? num_ddiv : 0;
  activeVarsCompsTotals[TOTAL_DDSV]
    = (adsv_cntr >= dsvStart && adsv_cntr < dsv_end) ? num_ddsv : 0;
  activeVarsCompsTotals[TOTAL_DDRV]
    = (adrv_cntr >= drvStart && adrv_cntr < drv_end) ? num_ddrv : 0;
  acv_cntr  += num_cdv;  adiv_cntr += num_ddiv;
  adsv_cntr += num_ddsv; adrv_cntr += num_ddrv;
  // aleatory uncertain
  activeVarsCompsTotals[TOTAL_CAUV]
    = (acv_cntr  >=  cvStart &&  acv_cntr <  cv_end) ? num_cauv  : 0;
  activeVarsCompsTotals[TOTAL_DAUIV]
    = (adiv_cntr >= divStart && adiv_cntr < div_end) ? num_dauiv : 0;
  activeVarsCompsTotals[TOTAL_DAUSV]
    = (adsv_cntr >= dsvStart && adsv_cntr < dsv_end) ? num_dausv : 0;
  activeVarsCompsTotals[TOTAL_DAURV]
    = (adrv_cntr >= drvStart && adrv_cntr < drv_end) ? num_daurv : 0;
  acv_cntr  += num_cauv;  adiv_cntr += num_dauiv;
  adsv_cntr += num_dausv; adrv_cntr += num_daurv;
  // epistemic uncertain
  activeVarsCompsTotals[TOTAL_CEUV]
    = (acv_cntr  >=  cvStart &&  acv_cntr <  cv_end) ? num_ceuv  : 0;
  activeVarsCompsTotals[TOTAL_DEUIV]
    = (adiv_cntr >= divStart && adiv_cntr < div_end) ? num_deuiv : 0;
  activeVarsCompsTotals[TOTAL_DEUSV]
    = (adsv_cntr >= dsvStart && adsv_cntr < dsv_end) ? num_deusv : 0;
  activeVarsCompsTotals[TOTAL_DEURV]
    = (adrv_cntr >= drvStart && adrv_cntr < drv_end) ? num_deurv : 0;
  acv_cntr  += num_ceuv;  adiv_cntr += num_deuiv;
  adsv_cntr += num_deusv; adrv_cntr += num_deurv;
  // state
  activeVarsCompsTotals[TOTAL_CSV]
    = (acv_cntr  >=  cvStart &&  acv_cntr <  cv_end) ? num_csv  : 0;
  activeVarsCompsTotals[TOTAL_DSIV]
    = (adiv_cntr >= divStart && adiv_cntr < div_end) ? num_dsiv : 0;
  activeVarsCompsTotals[TOTAL_DSSV]
    = (adsv_cntr >= dsvStart && adsv_cntr < dsv_end) ? num_dssv : 0;
  activeVarsCompsTotals[TOTAL_DSRV]
    = (adrv_cntr >= drvStart && adrv_cntr < drv_end) ? num_dsrv : 0;
  //acv_cntr  += num_csv;  adiv_cntr += num_dsiv;
  //adsv_cntr += num_dssv; adrv_cntr += num_dsrv;
}


void SharedVariablesDataRep::initialize_inactive_components()
{
  size_t i, j, num_cdv = variablesCompsTotals[TOTAL_CDV],
    num_ddiv  = variablesCompsTotals[TOTAL_DDIV],
    num_ddsv  = variablesCompsTotals[TOTAL_DDSV],
    num_ddrv  = variablesCompsTotals[TOTAL_DDRV],
    num_cauv  = variablesCompsTotals[TOTAL_CAUV],
    num_dauiv = variablesCompsTotals[TOTAL_DAUIV],
    num_dausv = variablesCompsTotals[TOTAL_DAUSV],
    num_daurv = variablesCompsTotals[TOTAL_DAURV],
    num_ceuv  = variablesCompsTotals[TOTAL_CEUV],
    num_deuiv = variablesCompsTotals[TOTAL_DEUIV],
    num_deusv = variablesCompsTotals[TOTAL_DEUSV],
    num_deurv = variablesCompsTotals[TOTAL_DEURV],
    num_csv   = variablesCompsTotals[TOTAL_CSV],
    num_dsiv  = variablesCompsTotals[TOTAL_DSIV],
    num_dssv  = variablesCompsTotals[TOTAL_DSSV],
    num_dsrv  = variablesCompsTotals[TOTAL_DSRV],
    icv_end   = icvStart  + numICV,  idiv_end = idivStart + numIDIV,
    idsv_end  = idsvStart + numIDSV, idrv_end = idrvStart + numIDRV,
    acv_cntr = 0, adiv_cntr = 0, adsv_cntr = 0, adrv_cntr = 0;

  inactiveVarsCompsTotals.resize(16);

  // TO DO: review this logic for case with relaxed discrete vars

  // design
  inactiveVarsCompsTotals[TOTAL_CDV]
    = (acv_cntr  >=  icvStart &&  acv_cntr <  icv_end) ? num_cdv  : 0;
  inactiveVarsCompsTotals[TOTAL_DDIV]
    = (adiv_cntr >= idivStart && adiv_cntr < idiv_end) ? num_ddiv : 0;
  inactiveVarsCompsTotals[TOTAL_DDSV]
    = (adsv_cntr >= idsvStart && adsv_cntr < idsv_end) ? num_ddsv : 0;
  inactiveVarsCompsTotals[TOTAL_DDRV]
    = (adrv_cntr >= idrvStart && adrv_cntr < idrv_end) ? num_ddrv : 0;
  acv_cntr  += num_cdv;  adiv_cntr += num_ddiv;
  adsv_cntr += num_ddsv; adrv_cntr += num_ddrv;
  // aleatory uncertain
  inactiveVarsCompsTotals[TOTAL_CAUV]
    = (acv_cntr  >=  icvStart &&  acv_cntr <  icv_end) ? num_cauv  : 0;
  inactiveVarsCompsTotals[TOTAL_DAUIV]
    = (adiv_cntr >= idivStart && adiv_cntr < idiv_end) ? num_dauiv : 0;
  inactiveVarsCompsTotals[TOTAL_DAUSV]
    = (adsv_cntr >= idsvStart && adsv_cntr < idsv_end) ? num_dausv : 0;
  inactiveVarsCompsTotals[TOTAL_DAURV]
    = (adrv_cntr >= idrvStart && adrv_cntr < idrv_end) ? num_daurv : 0;
  acv_cntr  += num_cauv;  adiv_cntr += num_dauiv;
  adsv_cntr += num_dausv; adrv_cntr += num_daurv;
  // epistemic uncertain
  inactiveVarsCompsTotals[TOTAL_CEUV]
    = (acv_cntr  >=  icvStart &&  acv_cntr <  icv_end) ? num_ceuv  : 0;
  inactiveVarsCompsTotals[TOTAL_DEUIV]
    = (adiv_cntr >= idivStart && adiv_cntr < idiv_end) ? num_deuiv : 0;
  inactiveVarsCompsTotals[TOTAL_DEUSV]
    = (adsv_cntr >= idsvStart && adsv_cntr < idsv_end) ? num_deusv : 0;
  inactiveVarsCompsTotals[TOTAL_DEURV]
    = (adrv_cntr >= idrvStart && adrv_cntr < idrv_end) ? num_deurv : 0;
  acv_cntr  += num_ceuv;  adiv_cntr += num_deuiv;
  adsv_cntr += num_deusv; adrv_cntr += num_deurv;
  // state
  inactiveVarsCompsTotals[TOTAL_CSV]
    = (acv_cntr  >=  icvStart &&  acv_cntr <  icv_end) ? num_csv  : 0;
  inactiveVarsCompsTotals[TOTAL_DSIV]
    = (adiv_cntr >= idivStart && adiv_cntr < idiv_end) ? num_dsiv : 0;
  inactiveVarsCompsTotals[TOTAL_DSSV]
    = (adsv_cntr >= idsvStart && adsv_cntr < idsv_end) ? num_dssv : 0;
  inactiveVarsCompsTotals[TOTAL_DSRV]
    = (adrv_cntr >= idrvStart && adrv_cntr < idrv_end) ? num_dsrv : 0;
  //acv_cntr  += num_csv;  adiv_cntr += num_dsiv;
  //adsv_cntr += num_dssv; adrv_cntr += num_dsrv;
}


/** Deep copies are used when recasting changes the nature of a
    Variables set. */
SharedVariablesData SharedVariablesData::copy() const
{
  // the handle class instantiates a new handle and a new body and copies
  // current attributes into the new body

#ifdef REFCOUNT_DEBUG
  Cout << "SharedVariablesData::copy() called to generate a deep copy with no "
       << "representation sharing." << std::endl;
#endif

  SharedVariablesData svd; // new handle: referenceCount=1, svdRep=NULL

  if (svdRep) {
    svd.svdRep = new SharedVariablesDataRep();

    svd.svdRep->variablesId             = svdRep->variablesId;
    svd.svdRep->variablesComponents     = svdRep->variablesComponents;
    svd.svdRep->variablesCompsTotals    = svdRep->variablesCompsTotals;
    svd.svdRep->activeVarsCompsTotals   = svdRep->activeVarsCompsTotals;
    svd.svdRep->inactiveVarsCompsTotals = svdRep->inactiveVarsCompsTotals;
    svd.svdRep->variablesView           = svdRep->variablesView;
    svd.svdRep->cvStart   = svdRep->cvStart;
    svd.svdRep->divStart  = svdRep->divStart;
    svd.svdRep->dsvStart  = svdRep->dsvStart;
    svd.svdRep->drvStart  = svdRep->drvStart;
    svd.svdRep->icvStart  = svdRep->icvStart;
    svd.svdRep->idivStart = svdRep->idivStart;
    svd.svdRep->idsvStart = svdRep->idsvStart;
    svd.svdRep->idrvStart = svdRep->idrvStart;
    svd.svdRep->numCV     = svdRep->numCV;
    svd.svdRep->numDIV    = svdRep->numDIV;
    svd.svdRep->numDSV    = svdRep->numDSV;
    svd.svdRep->numDRV    = svdRep->numDRV;
    svd.svdRep->numICV    = svdRep->numICV;
    svd.svdRep->numIDIV   = svdRep->numIDIV;
    svd.svdRep->numIDSV   = svdRep->numIDSV;
    svd.svdRep->numIDRV   = svdRep->numIDRV;

    // Boost MultiArrays must be resized prior to operator= assignment
    size_t num_acv  = svdRep->allContinuousLabels.size(),
           num_adiv = svdRep->allDiscreteIntLabels.size(),
           num_adsv = svdRep->allDiscreteStringLabels.size(),
           num_adrv = svdRep->allDiscreteRealLabels.size();
    svd.svdRep->allContinuousLabels.resize(boost::extents[num_acv]);
    svd.svdRep->allContinuousLabels = svdRep->allContinuousLabels;
    svd.svdRep->allDiscreteIntLabels.resize(boost::extents[num_adiv]);
    svd.svdRep->allDiscreteIntLabels = svdRep->allDiscreteIntLabels;
    svd.svdRep->allDiscreteStringLabels.resize(boost::extents[num_adsv]);
    svd.svdRep->allDiscreteStringLabels = svdRep->allDiscreteStringLabels;
    svd.svdRep->allDiscreteRealLabels.resize(boost::extents[num_adrv]);
    svd.svdRep->allDiscreteRealLabels = svdRep->allDiscreteRealLabels;
    svd.svdRep->allContinuousTypes.resize(boost::extents[num_acv]);
    svd.svdRep->allContinuousTypes = svdRep->allContinuousTypes;
    svd.svdRep->allDiscreteIntTypes.resize(boost::extents[num_adiv]);
    svd.svdRep->allDiscreteIntTypes = svdRep->allDiscreteIntTypes;
    svd.svdRep->allDiscreteStringTypes.resize(boost::extents[num_adsv]);
    svd.svdRep->allDiscreteStringTypes = svdRep->allDiscreteStringTypes;
    svd.svdRep->allDiscreteRealTypes.resize(boost::extents[num_adrv]);
    svd.svdRep->allDiscreteRealTypes = svdRep->allDiscreteRealTypes;
    svd.svdRep->allContinuousIds.resize(boost::extents[num_acv]);
    svd.svdRep->allContinuousIds = svdRep->allContinuousIds;

    svd.svdRep->allRelaxedDiscreteInt  = svdRep->allRelaxedDiscreteInt;
    svd.svdRep->allRelaxedDiscreteReal = svdRep->allRelaxedDiscreteReal;
    //svd.svdRep->relaxedDiscreteIds   = svdRep->relaxedDiscreteIds;
  }

  return svd;
}

} // namespace Dakota
