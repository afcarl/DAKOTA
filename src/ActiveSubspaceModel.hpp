/*  _______________________________________________________________________

    DAKOTA: Design Analysis Kit for Optimization and Terascale Applications
    Copyright 2014 Sandia Corporation.
    This software is distributed under the GNU Lesser General Public License.
    For more information, see the README file in the top Dakota directory.
    _______________________________________________________________________ */

#ifndef ACTIVE_SUBSPACE_MODEL_H
#define ACTIVE_SUBSPACE_MODEL_H

#include "RecastModel.hpp"
#include "DakotaIterator.hpp"

namespace Dakota {

// define special values for componentParallelMode
#define CONFIG_PHASE 0
#define OFFLINE_PHASE 1
#define ONLINE_PHASE 2

/// forward declarations
class ProblemDescDB;

//---
// BMA: Wishlist / notes:
//
// * Review use of linear algebra and dimensions throughout
//
// Convergence criteria:
//  * Consider using a single tolerance and using the derivative to
//    estimate the relationship between the ytol and svdtol
//  * Warn if convergenceTol < macheps since we reset it
//  * nullspaceTol needs to be bounded below too
//  * Add a convergence manager class
//  * Subtract UQ samples from the original function budget
//  * User control of bootstrap and choice of gap detection
//
// Algorithm enhancements
//  * Build surrogate in inactive dirs based on conditional expectation
//  * Add linear constraints to this Model for the recast domain
//
// Architecture:
//  * Be able to construct this Model type directly from problem db and
//    offer a user option.
//  * Verbosity control
//---

/// Active subspace model for input (variable space) reduction

/** Specialization of a RecastModel that identifies an active
    subspace during build phase and creates a RecastModel in the
    reduced space */
class ActiveSubspaceModel: public RecastModel
{
public:

  //
  //- Heading: Constructor and destructor
  //

  /// Problem database constructor
  ActiveSubspaceModel(ProblemDescDB& problem_db);

  /// lightweight constructor
  ActiveSubspaceModel(const Model& sub_model,
                      int random_seed, int initial_samples,
                      double conv_tol, size_t max_evals,
                      unsigned short subspace_id_method);

  /// destructor
  ~ActiveSubspaceModel();


  //
  //- Heading: Virtual function redefinitions
  //

  bool initialize_mapping(ParLevLIter pl_iter);
  bool finalize_mapping();
  bool mapping_initialized();

  /// called from IteratorScheduler::init_iterator() for iteratorComm rank 0 to
  /// terminate serve_init_mapping() on other iteratorComm processors
  void stop_init_mapping(ParLevLIter pl_iter);
  /// called from IteratorScheduler::init_iterator() for iteratorComm rank != 0
  /// to balance resize() calls on iteratorComm rank 0
  int serve_init_mapping(ParLevLIter pl_iter);


protected:

  //
  //- Heading: Virtual function redefinitions
  //

  void derived_init_communicators(ParLevLIter pl_iter, int max_eval_concurrency,
                                  bool recurse_flag);

  void derived_set_communicators(ParLevLIter pl_iter, int max_eval_concurrency,
                                 bool recurse_flag);

  void derived_free_communicators(ParLevLIter pl_iter, int max_eval_concurrency,
                                  bool recurse_flag);

  void derived_evaluate(const ActiveSet& set);
  void derived_evaluate_nowait(const ActiveSet& set);
  const IntResponseMap& derived_synchronize();
  const IntResponseMap& derived_synchronize_nowait();


  /// update component parallel mode for supporting parallelism in
  /// the offline and online phases
  void component_parallel_mode(short mode);

  /// Service the offline and online phase job requests received from the
  /// master; completes when termination message received from stop_servers().
  void serve_run(ParLevLIter pl_iter, int max_eval_concurrency);

  /// Executed by the master to terminate the offline and online phase
  /// server operations when iteration on the ActiveSubspaceModel is complete
  void stop_servers();

  // ---
  // Construct time convenience functions
  // ---

  /// retrieve the sub-Model from the DB to pass up the constructor chain
  Model get_sub_model(ProblemDescDB& problem_db);

  /// initialize the native problem space Monte Carlo sampler
  void init_fullspace_sampler();

  /// validate the build controls and set defaults
  void validate_inputs();


  // ---
  // Subspace identification functions: rank-revealing build phase
  // ---

  // Iteratively sample the fullspace model until subspace identified
  // that meets user-specified criteria
  void identify_subspace();

  /// generate fullspace samples, append to matrix, and factor,
  /// returning whether tolerance met
  void expand_basis();

  /// determine the number of full space samples for next iteration,
  /// based on batchSize, limiting by remaining function evaluation
  /// budget
  unsigned int calculate_fullspace_samples();

  /// sample the derivative at diff_samples points and leave temporary
  /// in dace_iterator
  void generate_fullspace_samples(unsigned int diff_samples);

  /// append the fullspaceSampler samples to the derivative and vars matrices
  void append_sample_matrices(unsigned int diff_samples);

  /// factor the derivative matrix and analyze singular values,
  /// assessing convergence and rank, returning whether tolerance met
  void compute_svd();

  /// compute Bing Li's criterion to identify the active subspace
  double computeBingLiCriterion(RealVector& singular_values);

  /// compute Constantine's metric to identify the active subspace
  double computeConstantineMetric(RealVector& singular_values);

  /// Compute active subspace size based on eigenvalue energy. Compatible with
  /// other truncation methods.
  double computeEnergyCriterion(RealVector& singular_values);


  // ---
  // Problem transformation functions
  // ---

  /// Initialize the base class RecastModel with reduced space variable sizes
  void initialize_recast();

  /// Create a variables components totals array with the reduced space
  /// size for continuous variables
  SizetArray variables_resize();

  /// translate the characterization of uncertain variables in the
  /// native_model to the reduced space of the transformed model
  void uncertain_vars_to_subspace();

  /// transform the original bounded domain (and any existing linear
  /// constraints) into linear constraints in the reduced space
  void update_linear_constraints();

  /// update variable labels
  void update_var_labels();


  // ---
  // Callback functions that perform data transform during the Recast operations
  // ---

  /// map the active continuous recast variables to the active
  /// submodel variables (linear transformation)
  static void vars_mapping(const Variables& recast_xi_vars,
                           Variables& sub_model_x_vars);

  /// map the inbound ActiveSet to the sub-model (map derivative variables)
  static void set_mapping(const Variables& recast_vars,
                          const ActiveSet& recast_set,
                          ActiveSet& sub_model_set);

  /// map responses from the sub-model to the recast model
  static void response_mapping(const Variables& recast_y_vars,
                               const Variables& sub_model_x_vars,
                               const Response& sub_model_resp,
                               Response& recast_resp);


  // ---
  // Member data
  // ---

  /// seed controlling all samplers
  int randomSeed;

  // Build phase controls

  /// initial number of samples at which to query the truth model
  int initialSamples;

  /// maximum number of build evaluations
  int maxFunctionEvals;

  /// Boolean flag signaling use of Bing Li criterion to identify active
  /// subspace dimension
  bool subspaceIdBingLi;

  /// Boolean flag signaling use of Constantine criterion to identify active
  /// subspace dimension
  bool subspaceIdConstantine;

  /// Boolean flag signaling use of eigenvalue energy criterion to identify
  /// active subspace dimension
  bool subspaceIdEnergy;

  /// Number of bootstrap samples for subspace identification
  size_t numReplicates;

  /// boolean flag to determine if variables should be transformed to u-space
  /// before active subspace initialization
  bool transformVars;

  // ---
  // TODO: add these criteria

  /// max bases to retain
  //  int maxBases;

  // ---

  // Number of fullspace active continuous variables
  size_t numFullspaceVars;
  // Total number of response functions
  size_t numFunctions;

  /// total construction samples evaluated so far
  unsigned int totalSamples;

  /// total evaluations of model (accounting for UQ phase)
  unsigned int totalEvals;

  /// boolean flag to determine if mapping has been fully initialized
  bool subspaceInitialized;

  // Data for numerical representation

  /// current approximation of system rank
  unsigned int reducedRank;

  /// basis for the reduced subspace
  RealMatrix activeBasis;

  /// basis for the inactive subspace
  RealMatrix inactiveBasis;

  /// current inactive variables
  RealVector inactiveVars;

  /// matrix of derivative data with numFunctions columns per fullspace sample;
  /// each column contains the gradient of one function at one sample point, 
  /// so total matrix size is numContinuousVars * (numFunctions * numSamples)
  /// [ D1 | D2 | ... | Dnum_samples]
  /// [ dy1/dx(k=1) | dy2/dx(k=1) | ... | dyM/dx(k=1) | k=2 | ... | k=n_s ]
  RealMatrix derivativeMatrix;

  /// matrix of the left singular vectors of derivativeMatrix
  RealMatrix leftSingularVectors;

  /// matrix of fullspace variable points samples
  /// size numContinuousVars * (numSamples)
  RealMatrix varsMatrix;

  /// Gradient scaling factors to make multiple response function gradients
  /// similar orders of magnitude.
  RealArray gradientScaleFactors;

  /// Truncation tolerance for eigenvalue energy subspace identification
  Real truncationTolerance;


  // Helper members

  /// Monte Carlo sampler for the full parameter space
  Iterator fullspaceSampler;

  /// static pointer to this class for use in static callbacks
  static ActiveSubspaceModel* asmInstance;

  /// the index of the active metaiterator-iterator parallelism level
  /// (corresponding to ParallelConfiguration::miPLIters) used at runtime
  size_t miPLIndex;

  /// Concurrency to use once subspace has been built.
  int onlineEvalConcurrency;

  /// Concurrency to use when building subspace.
  int offlineEvalConcurrency;

};

} // namespace Dakota

#endif
