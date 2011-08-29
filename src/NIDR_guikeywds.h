
namespace Dakota {

/** 891 distinct keywords (plus 103 aliases) **/

static GuiKeyWord
	kw_1[3] = {
		{"active_set_vector",8,0,1,0,1625},
		{"evaluation_cache",8,0,2,0,1627},
		{"restart_file",8,0,3,0,1629}
		},
	kw_2[1] = {
		{"processors_per_analysis",9,0,1,0,1609,0,0.,0.,0.,0,"{Number of processors per analysis} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicDF"}
		},
	kw_3[4] = {
		{"abort",8,0,1,1,1615,0,0.,0.,0.,0,"@[CHOOSE failure mitigation]"},
		{"continuation",8,0,1,1,1621},
		{"recover",14,0,1,1,1619},
		{"retry",9,0,1,1,1617}
		},
	kw_4[2] = {
		{"copy",8,0,1,0,1603,0,0.,0.,0.,0,"{Copy template files} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"replace",8,0,2,0,1605,0,0.,0.,0.,0,"{Replace existing files} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"}
		},
	kw_5[7] = {
		{"dir_save",0,0,3,0,1596},
		{"dir_tag",0,0,2,0,1594},
		{"directory_save",8,0,3,0,1597,0,0.,0.,0.,0,"{Save work directory} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"directory_tag",8,0,2,0,1595,0,0.,0.,0.,0,"{Tag work directory} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"named",11,0,1,0,1593,0,0.,0.,0.,0,"{Name of work directory} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"template_directory",11,2,4,0,1599,kw_4,0.,0.,0.,0,"{Template directory} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"template_files",15,2,4,0,1601,kw_4,0.,0.,0.,0,"{Template files} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"}
		},
	kw_6[8] = {
		{"allow_existing_results",8,0,3,0,1581,0,0.,0.,0.,0,"{Allow existing results files} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"aprepro",8,0,5,0,1585,0,0.,0.,0.,0,"{Aprepro parameters file format} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"file_save",8,0,7,0,1589,0,0.,0.,0.,0,"{Parameters and results file saving} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"file_tag",8,0,6,0,1587,0,0.,0.,0.,0,"{Parameters and results file tagging} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"parameters_file",11,0,1,0,1577,0,0.,0.,0.,0,"{Parameters file name} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"results_file",11,0,2,0,1579,0,0.,0.,0.,0,"{Results file name} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"verbatim",8,0,4,0,1583,0,0.,0.,0.,0,"{Verbatim driver/filter invocation syntax} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"},
		{"work_directory",8,7,8,0,1591,kw_5,0.,0.,0.,0,"{Create work directory} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"}
		},
	kw_7[9] = {
		{"analysis_components",15,0,1,0,1567,0,0.,0.,0.,0,"{Additional identifiers for use by the analysis_drivers} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"deactivate",8,3,6,0,1623,kw_1,0.,0.,0.,0,"{Feature deactivation} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"direct",8,1,4,1,1607,kw_2,0.,0.,0.,0,"[CHOOSE interface type]{Direct function interface } http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicDF"},
		{"failure_capture",8,4,5,0,1613,kw_3,0.,0.,0.,0,"{Failure capturing} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"fork",8,8,4,1,1575,kw_6,0.,0.,0.,0,"@"},
		{"grid",8,0,4,1,1611,0,0.,0.,0.,0,"{Grid interface } http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicG"},
		{"input_filter",11,0,2,0,1569,0,0.,0.,0.,0,"{Input filter} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"output_filter",11,0,3,0,1571,0,0.,0.,0.,0,"{Output filter} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"system",8,8,4,1,1573,kw_6,0.,0.,0.,0,"{System call interface } http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplicSC"}
		},
	kw_8[4] = {
		{"analysis_concurrency",9,0,3,0,1639,0,0.,0.,0.,0,"{Asynchronous analysis concurrency} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"evaluation_concurrency",9,0,1,0,1633,0,0.,0.,0.,0,"{Asynchronous evaluation concurrency} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"local_evaluation_self_scheduling",8,0,2,0,1635,0,0.,0.,0.,0,"{Self-schedule local evals} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"local_evaluation_static_scheduling",8,0,2,0,1637,0,0.,0.,0.,0,"{Static-schedule local evals} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"}
		},
	kw_9[10] = {
		{"algebraic_mappings",11,0,2,0,1563,0,0.,0.,0.,0,"{Algebraic mappings file} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfAlgebraic"},
		{"analysis_drivers",15,9,3,0,1565,kw_7,0.,0.,0.,0,"{Analysis drivers} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfApplic"},
		{"analysis_self_scheduling",8,0,8,0,1649,0,0.,0.,0.,0,"[CHOOSE analysis sched.]{Self scheduling of analyses} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"analysis_servers",9,0,7,0,1647,0,0.,0.,0.,0,"{Number of analysis servers} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"analysis_static_scheduling",8,0,8,0,1651,0,0.,0.,0.,0,"{Static scheduling of analyses} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"asynchronous",8,4,4,0,1631,kw_8,0.,0.,0.,0,"{Asynchronous interface usage} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"evaluation_self_scheduling",8,0,6,0,1643,0,0.,0.,0.,0,"[CHOOSE evaluation sched.]{Self scheduling of evaluations} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"evaluation_servers",9,0,5,0,1641,0,0.,0.,0.,0,"{Number of evaluation servers} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"evaluation_static_scheduling",8,0,6,0,1645,0,0.,0.,0.,0,"{Static scheduling of evaluations} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"},
		{"id_interface",11,0,1,0,1561,0,0.,0.,0.,0,"{Interface set identifier} http://dakota.sandia.gov/licensing/votd/html-ref/InterfCommands.html#InterfIndControl"}
		},
	kw_10[7] = {
		{"merit1",8,0,1,1,261,0,0.,0.,0.,0,"[CHOOSE merit function]"},
		{"merit1_smooth",8,0,1,1,263},
		{"merit2",8,0,1,1,265},
		{"merit2_smooth",8,0,1,1,267,0,0.,0.,0.,0,"@"},
		{"merit2_squared",8,0,1,1,269},
		{"merit_max",8,0,1,1,257},
		{"merit_max_smooth",8,0,1,1,259}
		},
	kw_11[2] = {
		{"blocking",8,0,1,1,251,0,0.,0.,0.,0,"[CHOOSE synchronization]"},
		{"nonblocking",8,0,1,1,253,0,0.,0.,0.,0,"@"}
		},
	kw_12[18] = {
		{"constraint_penalty",10,0,7,0,271,0,0.,0.,0.,0,"{Constraint penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"contraction_factor",10,0,2,0,243,0,0.,0.,0.,0,"{Pattern contraction factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"initial_delta",10,0,1,0,241,0,0.,0.,0.,0,"{Initial offset value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"linear_equality_constraint_matrix",14,0,14,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,16,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,17,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,15,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,9,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,10,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,12,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,13,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,11,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"merit_function",8,7,6,0,255,kw_10,0.,0.,0.,0,"{Merit function} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"smoothing_factor",10,0,8,0,273,0,0.,0.,0.,0,"{Smoothing factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"solution_accuracy",2,0,4,0,246},
		{"solution_target",10,0,4,0,247,0,0.,0.,0.,0,"{Solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"synchronization",8,2,5,0,249,kw_11,0.,0.,0.,0,"{Evaluation synchronization} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"},
		{"threshold_delta",10,0,3,0,245,0,0.,0.,0.,0,"{Threshold for offset values} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodAPPSDC"}
		},
	kw_13[1] = {
		{"emulator_samples",9,0,1,0,825}
		},
	kw_14[1] = {
		{"sparse_grid_level",13,0,1,0,829}
		},
	kw_15[1] = {
		{"sparse_grid_level",13,0,1,0,833}
		},
	kw_16[3] = {
		{"gp",8,1,1,1,823,kw_13},
		{"pce",8,1,1,1,827,kw_14},
		{"sc",8,1,1,1,831,kw_15}
		},
	kw_17[2] = {
		{"adaptive",8,0,1,1,845},
		{"hastings",8,0,1,1,843}
		},
	kw_18[2] = {
		{"delayed",8,0,1,1,839},
		{"standard",8,0,1,1,837}
		},
	kw_19[2] = {
		{"mt19937",8,0,1,1,851},
		{"rnum2",8,0,1,1,853}
		},
	kw_20[14] = {
		{"emulator",8,3,2,0,821,kw_16},
		{"gpmsa",8,0,1,1,819},
		{"likelihood_scale",10,0,11,0,863},
		{"metropolis",8,2,4,0,841,kw_17},
		{"proposal_covariance_scale",10,0,10,0,861},
		{"queso",8,0,1,1,817},
		{"rejection",8,2,3,0,835,kw_18},
		{"rng",8,2,6,0,849,kw_19},
		{"samples",9,0,13,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,12,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"use_derivatives",8,0,5,0,847},
		{"x_obs_data_file",11,0,7,0,855},
		{"y_obs_data_file",11,0,8,0,857},
		{"y_std_data_file",11,0,9,0,859}
		},
	kw_21[3] = {
		{"deltas_per_variable",5,0,2,2,1104},
		{"step_vector",14,0,1,1,1103,0,0.,0.,0.,0,"{Step vector} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSCPS"},
		{"steps_per_variable",13,0,2,2,1105,0,0.,0.,0.,0,"{Number of steps per variable} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSCPS"}
		},
	kw_22[7] = {
		{"initial_delta",10,0,5,1,459,0,0.,0.,0.,0,"{Initial offset value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"misc_options",15,0,4,0,545,0,0.,0.,0.,0,"{Specify miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"seed",9,0,2,0,541,0,0.,0.,0.,0,"{Random seed for stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"show_misc_options",8,0,3,0,543,0,0.,0.,0.,0,"{Show miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"solution_accuracy",2,0,1,0,538},
		{"solution_target",10,0,1,0,539,0,0.,0.,0.,0,"{Desired solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"threshold_delta",10,0,6,2,461,0,0.,0.,0.,0,"{Threshold for offset values} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"}
		},
	kw_23[2] = {
		{"all_dimensions",8,0,1,1,469},
		{"major_dimension",8,0,1,1,467}
		},
	kw_24[11] = {
		{"constraint_penalty",10,0,6,0,479,0,0.,0.,0.,0,"{Constraint penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"division",8,2,1,0,465,kw_23,0.,0.,0.,0,"{Box subdivision approach} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"global_balance_parameter",10,0,2,0,471,0,0.,0.,0.,0,"{Global search balancing parameter} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"local_balance_parameter",10,0,3,0,473,0,0.,0.,0.,0,"{Local search balancing parameter} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"max_boxsize_limit",10,0,4,0,475,0,0.,0.,0.,0,"{Maximum boxsize limit} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"min_boxsize_limit",10,0,5,0,477,0,0.,0.,0.,0,"{Minimum boxsize limit} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDIR"},
		{"misc_options",15,0,10,0,545,0,0.,0.,0.,0,"{Specify miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"seed",9,0,8,0,541,0,0.,0.,0.,0,"{Random seed for stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"show_misc_options",8,0,9,0,543,0,0.,0.,0.,0,"{Show miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"solution_accuracy",2,0,7,0,538},
		{"solution_target",10,0,7,0,539,0,0.,0.,0.,0,"{Desired solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"}
		},
	kw_25[3] = {
		{"blend",8,0,1,1,515},
		{"two_point",8,0,1,1,513},
		{"uniform",8,0,1,1,517}
		},
	kw_26[2] = {
		{"linear_rank",8,0,1,1,495},
		{"merit_function",8,0,1,1,497}
		},
	kw_27[3] = {
		{"flat_file",11,0,1,1,491},
		{"simple_random",8,0,1,1,487},
		{"unique_random",8,0,1,1,489}
		},
	kw_28[2] = {
		{"mutation_range",9,0,2,0,533,0,0.,0.,0.,0,"{Mutation range} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"mutation_scale",10,0,1,0,531,0,0.,0.,0.,0,"{Mutation scale} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"}
		},
	kw_29[5] = {
		{"non_adaptive",8,0,2,0,535,0,0.,0.,0.,0,"{Non-adaptive mutation flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"offset_cauchy",8,2,1,1,527,kw_28},
		{"offset_normal",8,2,1,1,525,kw_28},
		{"offset_uniform",8,2,1,1,529,kw_28},
		{"replace_uniform",8,0,1,1,523}
		},
	kw_30[4] = {
		{"chc",9,0,1,1,503,0,0.,0.,0.,0,"{CHC replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"elitist",9,0,1,1,505,0,0.,0.,0.,0,"{Elitist replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"new_solutions_generated",9,0,2,0,507,0,0.,0.,0.,0,"{New solutions generated} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"random",9,0,1,1,501,0,0.,0.,0.,0,"{Random replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"}
		},
	kw_31[14] = {
		{"constraint_penalty",10,0,9,0,537},
		{"crossover_rate",10,0,5,0,509,0,0.,0.,0.,0,"{Crossover rate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"crossover_type",8,3,6,0,511,kw_25,0.,0.,0.,0,"{Crossover type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"fitness_type",8,2,3,0,493,kw_26,0.,0.,0.,0,"{Fitness type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"initialization_type",8,3,2,0,485,kw_27,0.,0.,0.,0,"{Initialization type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"misc_options",15,0,13,0,545,0,0.,0.,0.,0,"{Specify miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"mutation_rate",10,0,7,0,519,0,0.,0.,0.,0,"{Mutation rate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"mutation_type",8,5,8,0,521,kw_29,0.,0.,0.,0,"{Mutation type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"population_size",9,0,1,0,483,0,0.,0.,0.,0,"{Number of population members} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"replacement_type",8,4,4,0,499,kw_30,0.,0.,0.,0,"{Replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYEA"},
		{"seed",9,0,11,0,541,0,0.,0.,0.,0,"{Random seed for stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"show_misc_options",8,0,12,0,543,0,0.,0.,0.,0,"{Show miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"solution_accuracy",2,0,10,0,538},
		{"solution_target",10,0,10,0,539,0,0.,0.,0.,0,"{Desired solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"}
		},
	kw_32[3] = {
		{"adaptive_pattern",8,0,1,1,433},
		{"basic_pattern",8,0,1,1,435},
		{"multi_step",8,0,1,1,431}
		},
	kw_33[2] = {
		{"coordinate",8,0,1,1,421},
		{"simplex",8,0,1,1,423}
		},
	kw_34[2] = {
		{"blocking",8,0,1,1,439},
		{"nonblocking",8,0,1,1,441}
		},
	kw_35[17] = {
		{"constant_penalty",8,0,1,0,413,0,0.,0.,0.,0,"{Control of dynamic penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"constraint_penalty",10,0,16,0,455,0,0.,0.,0.,0,"{Constraint penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"contraction_factor",10,0,15,0,453,0,0.,0.,0.,0,"{Pattern contraction factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"expand_after_success",9,0,3,0,417,0,0.,0.,0.,0,"{Number of consecutive improvements before expansion} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"exploratory_moves",8,3,7,0,429,kw_32,0.,0.,0.,0,"{Exploratory moves selection} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"initial_delta",10,0,13,1,459,0,0.,0.,0.,0,"{Initial offset value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"misc_options",15,0,12,0,545,0,0.,0.,0.,0,"{Specify miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"no_expansion",8,0,2,0,415,0,0.,0.,0.,0,"{No expansion flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"pattern_basis",8,2,4,0,419,kw_33,0.,0.,0.,0,"{Pattern basis selection} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"seed",9,0,10,0,541,0,0.,0.,0.,0,"{Random seed for stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"show_misc_options",8,0,11,0,543,0,0.,0.,0.,0,"{Show miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"solution_accuracy",2,0,9,0,538},
		{"solution_target",10,0,9,0,539,0,0.,0.,0.,0,"{Desired solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"stochastic",8,0,5,0,425,0,0.,0.,0.,0,"{Stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"synchronization",8,2,8,0,437,kw_34,0.,0.,0.,0,"{Evaluation synchronization} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"threshold_delta",10,0,14,2,461,0,0.,0.,0.,0,"{Threshold for offset values} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"total_pattern_size",9,0,6,0,427,0,0.,0.,0.,0,"{Total number of points in pattern} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"}
		},
	kw_36[13] = {
		{"constant_penalty",8,0,4,0,451,0,0.,0.,0.,0,"{Control of dynamic penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYSW"},
		{"constraint_penalty",10,0,12,0,455,0,0.,0.,0.,0,"{Constraint penalty} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"contract_after_failure",9,0,1,0,445,0,0.,0.,0.,0,"{Number of consecutive failures before contraction} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYSW"},
		{"contraction_factor",10,0,11,0,453,0,0.,0.,0.,0,"{Pattern contraction factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"expand_after_success",9,0,3,0,449,0,0.,0.,0.,0,"{Number of consecutive improvements before expansion} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYSW"},
		{"initial_delta",10,0,9,1,459,0,0.,0.,0.,0,"{Initial offset value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"misc_options",15,0,8,0,545,0,0.,0.,0.,0,"{Specify miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"no_expansion",8,0,2,0,447,0,0.,0.,0.,0,"{No expansion flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYSW"},
		{"seed",9,0,6,0,541,0,0.,0.,0.,0,"{Random seed for stochastic pattern search} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"},
		{"show_misc_options",8,0,7,0,543,0,0.,0.,0.,0,"{Show miscellaneous options} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"solution_accuracy",2,0,5,0,538},
		{"solution_target",10,0,5,0,539,0,0.,0.,0.,0,"{Desired solution target} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYDC"},
		{"threshold_delta",10,0,10,2,461,0,0.,0.,0.,0,"{Threshold for offset values} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodCOLINYPS"}
		},
	kw_37[9] = {
		{"linear_equality_constraint_matrix",14,0,14,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,16,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,17,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,15,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,9,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,10,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,12,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,13,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,11,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"}
		},
	kw_38[1] = {
		{"drop_tolerance",10,0,1,0,887}
		},
	kw_39[14] = {
		{"box_behnken",8,0,1,1,877,0,0.,0.,0.,0,"[CHOOSE DACE type]"},
		{"central_composite",8,0,1,1,879},
		{"fixed_seed",8,0,5,0,889,0,0.,0.,0.,0,"{Fixed seed flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDDACE"},
		{"grid",8,0,1,1,867},
		{"lhs",8,0,1,1,873},
		{"main_effects",8,0,2,0,881,0,0.,0.,0.,0,"{Main effects} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDDACE"},
		{"oa_lhs",8,0,1,1,875},
		{"oas",8,0,1,1,871},
		{"quality_metrics",8,0,3,0,883,0,0.,0.,0.,0,"{Quality metrics} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDDACE"},
		{"random",8,0,1,1,869},
		{"samples",9,0,8,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,7,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"symbols",9,0,6,0,891,0,0.,0.,0.,0,"{Number of symbols} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDDACE"},
		{"variance_based_decomp",8,1,4,0,885,kw_38,0.,0.,0.,0,"{Variance based decomposition} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDDACE"}
		},
	kw_40[2] = {
		{"maximize",8,0,1,1,177},
		{"minimize",8,0,1,1,175}
		},
	kw_41[15] = {
		{"bfgs",8,0,1,1,167},
		{"frcg",8,0,1,1,163},
		{"linear_equality_constraint_matrix",14,0,7,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,9,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,10,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,8,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,2,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,3,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,5,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,6,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,4,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"mmfd",8,0,1,1,165},
		{"optimization_type",8,2,11,0,173,kw_40,0.,0.,0.,0,"{Optimization type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDOTDC"},
		{"slp",8,0,1,1,169},
		{"sqp",8,0,1,1,171}
		},
	kw_42[10] = {
		{"linear_equality_constraint_matrix",14,0,6,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,8,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,9,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,7,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,1,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,2,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,4,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,5,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,3,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"optimization_type",8,2,10,0,173,kw_40,0.,0.,0.,0,"{Optimization type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodDOTDC"}
		},
	kw_43[2] = {
		{"seed",9,0,2,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"use_derivatives",8,0,1,0,581}
		},
	kw_44[3] = {
		{"grid",8,0,1,1,907,0,0.,0.,0.,0,"[CHOOSE trial type]"},
		{"halton",8,0,1,1,909},
		{"random",8,0,1,1,911,0,0.,0.,0.,0,"@"}
		},
	kw_45[1] = {
		{"drop_tolerance",10,0,1,0,901}
		},
	kw_46[8] = {
		{"fixed_seed",8,0,4,0,903,0,0.,0.,0.,0,"{Fixed seed flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"latinize",8,0,1,0,895,0,0.,0.,0.,0,"{Latinization of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"num_trials",9,0,6,0,913,0,0.,0.,0.,0,"{Number of trials  } http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"quality_metrics",8,0,2,0,897,0,0.,0.,0.,0,"{Quality metrics} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"samples",9,0,8,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,7,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"trial_type",8,3,5,0,905,kw_44,0.,0.,0.,0,"{Trial type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"variance_based_decomp",8,1,3,0,899,kw_45,0.,0.,0.,0,"{Variance based decomposition} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"}
		},
	kw_47[1] = {
		{"drop_tolerance",10,0,1,0,1077}
		},
	kw_48[10] = {
		{"fixed_sequence",8,0,6,0,1081,0,0.,0.,0.,0,"{Fixed sequence flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"halton",8,0,1,1,1067,0,0.,0.,0.,0,"[CHOOSE sequence type]"},
		{"hammersley",8,0,1,1,1069},
		{"latinize",8,0,2,0,1071,0,0.,0.,0.,0,"{Latinization of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"prime_base",13,0,9,0,1087,0,0.,0.,0.,0,"{Prime bases for sequences} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"quality_metrics",8,0,3,0,1073,0,0.,0.,0.,0,"{Quality metrics} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"samples",9,0,5,0,1079,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"sequence_leap",13,0,8,0,1085,0,0.,0.,0.,0,"{Sequence leaping indices} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"sequence_start",13,0,7,0,1083,0,0.,0.,0.,0,"{Sequence starting indices} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"},
		{"variance_based_decomp",8,1,4,0,1075,kw_47,0.,0.,0.,0,"{Variance based decomposition} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodFSUDACE"}
		},
	kw_49[2] = {
		{"complementary",8,0,1,1,785},
		{"cumulative",8,0,1,1,783}
		},
	kw_50[1] = {
		{"num_gen_reliability_levels",13,0,1,0,793,0,0.,0.,0.,0,"{Number of generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"}
		},
	kw_51[1] = {
		{"num_probability_levels",13,0,1,0,789,0,0.,0.,0.,0,"{Number of probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"}
		},
	kw_52[2] = {
		{"mt19937",8,0,1,1,797},
		{"rnum2",8,0,1,1,799}
		},
	kw_53[1] = {
		{"use_derivatives",8,0,1,0,767}
		},
	kw_54[2] = {
		{"gen_reliabilities",8,0,1,1,779},
		{"probabilities",8,0,1,1,777}
		},
	kw_55[2] = {
		{"compute",8,2,2,0,775,kw_54},
		{"num_response_levels",13,0,1,0,773}
		},
	kw_56[9] = {
		{"distribution",8,2,5,0,781,kw_49,0.,0.,0.,0,"{Distribution type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"ego",8,1,1,0,765,kw_53},
		{"gen_reliability_levels",14,1,7,0,791,kw_50,0.,0.,0.,0,"{Generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"lhs",8,0,1,0,769},
		{"probability_levels",14,1,6,0,787,kw_51,0.,0.,0.,0,"{Probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"response_levels",14,2,2,0,771,kw_55},
		{"rng",8,2,8,0,795,kw_52,0.,0.,0.,0,"{Random number generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"samples",9,0,4,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,3,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"}
		},
	kw_57[1] = {
		{"use_derivatives",8,0,1,0,805}
		},
	kw_58[2] = {
		{"mt19937",8,0,1,1,811},
		{"rnum2",8,0,1,1,813}
		},
	kw_59[5] = {
		{"ego",8,1,1,0,803,kw_57},
		{"lhs",8,0,1,0,807},
		{"rng",8,2,2,0,809,kw_58,0.,0.,0.,0,"{Random seed generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDGlobalIntervalEst"},
		{"samples",9,0,4,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,3,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"}
		},
	kw_60[2] = {
		{"complementary",8,0,1,1,1055},
		{"cumulative",8,0,1,1,1053}
		},
	kw_61[1] = {
		{"num_gen_reliability_levels",13,0,1,0,1063}
		},
	kw_62[1] = {
		{"num_probability_levels",13,0,1,0,1059}
		},
	kw_63[2] = {
		{"gen_reliabilities",8,0,1,1,1049},
		{"probabilities",8,0,1,1,1047}
		},
	kw_64[2] = {
		{"compute",8,2,2,0,1045,kw_63},
		{"num_response_levels",13,0,1,0,1043}
		},
	kw_65[2] = {
		{"mt19937",8,0,1,1,1037},
		{"rnum2",8,0,1,1,1039}
		},
	kw_66[10] = {
		{"all_variables",8,0,2,0,1029,0,0.,0.,0.,0,"{All variables flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDGlobalRel"},
		{"distribution",8,2,7,0,1051,kw_60},
		{"gen_reliability_levels",14,1,9,0,1061,kw_61},
		{"probability_levels",14,1,8,0,1057,kw_62},
		{"response_levels",14,2,6,0,1041,kw_64},
		{"rng",8,2,5,0,1035,kw_65},
		{"seed",9,0,4,0,1033,0,0.,0.,0.,0,"{Refinement seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDLocalRel"},
		{"u_gaussian_process",8,0,1,1,1027},
		{"use_derivatives",8,0,3,0,1031},
		{"x_gaussian_process",8,0,1,1,1025}
		},
	kw_67[2] = {
		{"gen_reliabilities",8,0,1,1,761},
		{"probabilities",8,0,1,1,759}
		},
	kw_68[2] = {
		{"compute",8,2,2,0,757,kw_67},
		{"num_response_levels",13,0,1,0,755}
		},
	kw_69[7] = {
		{"distribution",8,2,4,0,781,kw_49,0.,0.,0.,0,"{Distribution type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"gen_reliability_levels",14,1,6,0,791,kw_50,0.,0.,0.,0,"{Generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"probability_levels",14,1,5,0,787,kw_51,0.,0.,0.,0,"{Probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"response_levels",14,2,1,0,753,kw_68},
		{"rng",8,2,7,0,795,kw_52,0.,0.,0.,0,"{Random number generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"samples",9,0,3,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,2,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"}
		},
	kw_70[1] = {
		{"list_of_points",14,0,1,1,1099,0,0.,0.,0.,0,"{List of points to evaluate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSLPS"}
		},
	kw_71[2] = {
		{"complementary",8,0,1,1,959},
		{"cumulative",8,0,1,1,957}
		},
	kw_72[1] = {
		{"num_gen_reliability_levels",13,0,1,0,953}
		},
	kw_73[1] = {
		{"num_probability_levels",13,0,1,0,949}
		},
	kw_74[2] = {
		{"gen_reliabilities",8,0,1,1,945},
		{"probabilities",8,0,1,1,943}
		},
	kw_75[2] = {
		{"compute",8,2,2,0,941,kw_74},
		{"num_response_levels",13,0,1,0,939}
		},
	kw_76[6] = {
		{"distribution",8,2,5,0,955,kw_71},
		{"gen_reliability_levels",14,1,4,0,951,kw_72},
		{"nip",8,0,1,0,935},
		{"probability_levels",14,1,3,0,947,kw_73},
		{"response_levels",14,2,2,0,937,kw_75},
		{"sqp",8,0,1,0,933}
		},
	kw_77[2] = {
		{"nip",8,0,1,0,965},
		{"sqp",8,0,1,0,963}
		},
	kw_78[5] = {
		{"adapt_import",8,0,1,1,999},
		{"import",8,0,1,1,997},
		{"mm_adapt_import",8,0,1,1,1001},
		{"samples",9,0,2,0,1003,0,0.,0.,0.,0,"{Refinement samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDLocalRel"},
		{"seed",9,0,3,0,1005,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"}
		},
	kw_79[3] = {
		{"first_order",8,0,1,1,991},
		{"sample_refinement",8,5,2,0,995,kw_78},
		{"second_order",8,0,1,1,993}
		},
	kw_80[9] = {
		{"nip",8,0,2,0,987},
		{"no_approx",8,0,1,1,983},
		{"sqp",8,0,2,0,985},
		{"u_taylor_mean",8,0,1,1,973},
		{"u_taylor_mpp",8,0,1,1,977},
		{"u_two_point",8,0,1,1,981},
		{"x_taylor_mean",8,0,1,1,971},
		{"x_taylor_mpp",8,0,1,1,975},
		{"x_two_point",8,0,1,1,979}
		},
	kw_81[1] = {
		{"num_reliability_levels",13,0,1,0,1021}
		},
	kw_82[3] = {
		{"gen_reliabilities",8,0,1,1,1017},
		{"probabilities",8,0,1,1,1013},
		{"reliabilities",8,0,1,1,1015}
		},
	kw_83[2] = {
		{"compute",8,3,2,0,1011,kw_82},
		{"num_response_levels",13,0,1,0,1009}
		},
	kw_84[7] = {
		{"distribution",8,2,5,0,1051,kw_60},
		{"gen_reliability_levels",14,1,7,0,1061,kw_61},
		{"integration",8,3,2,0,989,kw_79,0.,0.,0.,0,"{Integration method} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDLocalRel"},
		{"mpp_search",8,9,1,0,969,kw_80,0.,0.,0.,0,"{MPP search type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDLocalRel"},
		{"probability_levels",14,1,6,0,1057,kw_62},
		{"reliability_levels",14,1,4,0,1019,kw_81},
		{"response_levels",14,2,3,0,1007,kw_83}
		},
	kw_85[2] = {
		{"num_offspring",0x19,0,2,0,371,0,0.,0.,0.,0,"{Number of offspring in random shuffle crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"num_parents",0x19,0,1,0,369,0,0.,0.,0.,0,"{Number of parents in random shuffle crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"}
		},
	kw_86[5] = {
		{"crossover_rate",10,0,2,0,373,0,0.,0.,0.,0,"{Crossover rate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"multi_point_binary",9,0,1,1,361,0,0.,0.,0.,0,"{Multi point binary crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"multi_point_parameterized_binary",9,0,1,1,363,0,0.,0.,0.,0,"{Multi point parameterized binary crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"multi_point_real",9,0,1,1,365,0,0.,0.,0.,0,"{Multi point real crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"shuffle_random",8,2,1,1,367,kw_85,0.,0.,0.,0,"{Random shuffle crossover} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"}
		},
	kw_87[3] = {
		{"flat_file",11,0,1,1,357},
		{"simple_random",8,0,1,1,353},
		{"unique_random",8,0,1,1,355}
		},
	kw_88[1] = {
		{"mutation_scale",10,0,1,0,387,0,0.,0.,0.,0,"{Mutation scale} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"}
		},
	kw_89[6] = {
		{"bit_random",8,0,1,1,377},
		{"mutation_rate",10,0,2,0,389,0,0.,0.,0.,0,"{Mutation rate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"offset_cauchy",8,1,1,1,383,kw_88},
		{"offset_normal",8,1,1,1,381,kw_88},
		{"offset_uniform",8,1,1,1,385,kw_88},
		{"replace_uniform",8,0,1,1,379}
		},
	kw_90[3] = {
		{"metric_tracker",8,0,1,1,303,0,0.,0.,0.,0,"{Convergence type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"},
		{"num_generations",0x29,0,3,0,307,0,0.,0.,0.,0,"{Number generations for metric_tracker converger} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"},
		{"percent_change",10,0,2,0,305,0,0.,0.,0.,0,"{Percent change limit for metric_tracker converger} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"}
		},
	kw_91[2] = {
		{"domination_count",8,0,1,1,281},
		{"layer_rank",8,0,1,1,279}
		},
	kw_92[2] = {
		{"distance",14,0,1,1,299},
		{"radial",14,0,1,1,297}
		},
	kw_93[1] = {
		{"orthogonal_distance",14,0,1,1,311,0,0.,0.,0.,0,"{Post_processor distance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"}
		},
	kw_94[2] = {
		{"shrinkage_fraction",10,0,1,0,293},
		{"shrinkage_percentage",2,0,1,0,292}
		},
	kw_95[4] = {
		{"below_limit",10,2,1,1,291,kw_94,0.,0.,0.,0,"{Below limit selection} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"elitist",8,0,1,1,285},
		{"roulette_wheel",8,0,1,1,287},
		{"unique_roulette_wheel",8,0,1,1,289}
		},
	kw_96[21] = {
		{"convergence_type",8,3,4,0,301,kw_90},
		{"crossover_type",8,5,19,0,359,kw_86,0.,0.,0.,0,"{Crossover type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"fitness_type",8,2,1,0,277,kw_91,0.,0.,0.,0,"{Fitness type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"},
		{"initialization_type",8,3,18,0,351,kw_87,0.,0.,0.,0,"{Initialization type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"linear_equality_constraint_matrix",14,0,11,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,13,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,14,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,12,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,6,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,7,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,9,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,10,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,8,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"log_file",11,0,16,0,347,0,0.,0.,0.,0,"{Log file} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"mutation_type",8,6,20,0,375,kw_89,0.,0.,0.,0,"{Mutation type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"niching_type",8,2,3,0,295,kw_92,0.,0.,0.,0,"{Niche pressure type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"},
		{"population_size",9,0,15,0,345,0,0.,0.,0.,0,"{Number of population members} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"postprocessor_type",8,1,5,0,309,kw_93,0.,0.,0.,0,"{Post_processor type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGAMOGA"},
		{"print_each_pop",8,0,17,0,349,0,0.,0.,0.,0,"{Population output} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"replacement_type",8,4,2,0,283,kw_95,0.,0.,0.,0,"{Replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"seed",9,0,21,0,391,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"}
		},
	kw_97[1] = {
		{"partitions",13,0,1,1,1109,0,0.,0.,0.,0,"{Partitions per variable} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSMPS"}
		},
	kw_98[4] = {
		{"min_boxsize_limit",10,0,2,0,927,0,0.,0.,0.,0,"{Min boxsize limit} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNCSUDC"},
		{"solution_accuracy",2,0,1,0,924},
		{"solution_target",10,0,1,0,925,0,0.,0.,0.,0,"{Solution Target } http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNCSUDC"},
		{"volume_boxsize_limit",10,0,3,0,929}
		},
	kw_99[9] = {
		{"absolute_conv_tol",10,0,2,0,551,0,0.,0.,0.,0,"{Absolute function convergence tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"covariance",9,0,8,0,563,0,0.,0.,0.,0,"{Covariance post-processing} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"false_conv_tol",10,0,6,0,559,0,0.,0.,0.,0,"{False convergence tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"function_precision",10,0,1,0,549,0,0.,0.,0.,0,"{Relative precision in least squares terms} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"initial_trust_radius",10,0,7,0,561,0,0.,0.,0.,0,"{Initial trust region radius} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"regression_diagnostics",8,0,9,0,565,0,0.,0.,0.,0,"{Regression diagnostics post-processing} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"singular_conv_tol",10,0,4,0,555,0,0.,0.,0.,0,"{Singular convergence tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"singular_radius",10,0,5,0,557,0,0.,0.,0.,0,"{Step limit for sctol} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"},
		{"x_conv_tol",10,0,3,0,553,0,0.,0.,0.,0,"{Convergence tolerance for change in parameter vector} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodLSNL2SOL"}
		},
	kw_100[1] = {
		{"num_reliability_levels",13,0,1,0,737,0,0.,0.,0.,0,"{Number of reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"}
		},
	kw_101[3] = {
		{"gen_reliabilities",8,0,1,1,749},
		{"probabilities",8,0,1,1,745},
		{"reliabilities",8,0,1,1,747}
		},
	kw_102[2] = {
		{"compute",8,3,2,0,743,kw_101,0.,0.,0.,0,"{Target statistics for response levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"num_response_levels",13,0,1,0,741,0,0.,0.,0.,0,"{Number of response levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"}
		},
	kw_103[6] = {
		{"expansion_order",13,0,4,1,633,0,0.,0.,0.,0,"{Expansion order} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"expansion_terms",9,0,4,1,635,0,0.,0.,0.,0,"{Expansion terms} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"reuse_points",8,0,1,0,621,0,0.,0.,0.,0,"{Reuse points flag for PCE coefficient estimation by collocation_points or collocation_ratio} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"reuse_samples",0,0,1,0,620},
		{"tensor_grid",8,0,3,0,625},
		{"use_derivatives",8,0,2,0,623,0,0.,0.,0.,0,"{Derivative usage flag for PCE coefficient estimation by collocation_points or collocation_ratio} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"}
		},
	kw_104[2] = {
		{"expansion_order",13,0,4,1,633,0,0.,0.,0.,0,"{Expansion order} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"expansion_terms",9,0,4,1,635,0,0.,0.,0.,0,"{Expansion terms} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"}
		},
	kw_105[3] = {
		{"expansion_order",13,0,2,1,633,0,0.,0.,0.,0,"{Expansion order} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"expansion_terms",9,0,2,1,635,0,0.,0.,0.,0,"{Expansion terms} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"incremental_lhs",8,0,1,0,629,0,0.,0.,0.,0,"{Incremental LHS flag for PCE coefficient estimation by expansion_samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"}
		},
	kw_106[3] = {
		{"decay",8,0,1,1,593},
		{"generalized",8,0,1,1,595},
		{"sobol",8,0,1,1,591}
		},
	kw_107[2] = {
		{"dimension_adaptive",8,3,1,1,589,kw_106},
		{"uniform",8,0,1,1,587}
		},
	kw_108[3] = {
		{"dimension_preference",14,0,1,0,609,0,0.,0.,0.,0,"{Dimension preference for anisotropic tensor and sparse grids} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"nested",8,0,2,0,611},
		{"non_nested",8,0,2,0,613}
		},
	kw_109[3] = {
		{"adapt_import",8,0,1,1,647},
		{"import",8,0,1,1,645},
		{"mm_adapt_import",8,0,1,1,649}
		},
	kw_110[2] = {
		{"lhs",8,0,1,1,653},
		{"random",8,0,1,1,655}
		},
	kw_111[5] = {
		{"dimension_preference",14,0,2,0,609,0,0.,0.,0.,0,"{Dimension preference for anisotropic tensor and sparse grids} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"nested",8,0,3,0,611},
		{"non_nested",8,0,3,0,613},
		{"restricted",8,0,1,0,605},
		{"unrestricted",8,0,1,0,607}
		},
	kw_112[2] = {
		{"drop_tolerance",10,0,2,0,641,0,0.,0.,0.,0,"{VBD tolerance for omitting small indices} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"univariate_effects",8,0,1,0,639,0,0.,0.,0.,0,"{Restriction of VBD indices to main/total} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"}
		},
	kw_113[23] = {
		{"all_variables",8,0,15,0,731,0,0.,0.,0.,0,"{All variables flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"askey",8,0,2,0,597},
		{"collocation_points",9,6,3,1,617,kw_103,0.,0.,0.,0,"{Number of collocation points for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"collocation_ratio",10,6,3,1,619,kw_103,0.,0.,0.,0,"{Collocation point oversampling ratio for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"cubature_integrand",9,0,3,1,615,0,0.,0.,0.,0,"{Cubature integrand order for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"distribution",8,2,9,0,781,kw_49,0.,0.,0.,0,"{Distribution type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"expansion_import_file",11,2,3,1,631,kw_104,0.,0.,0.,0,"{File name for import of PCE coefficients} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"expansion_samples",9,3,3,1,627,kw_105,0.,0.,0.,0,"{Number of LHS simulation samples for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"fixed_seed",8,0,16,0,733,0,0.,0.,0.,0,"{Fixed seed flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"gen_reliability_levels",14,1,11,0,791,kw_50,0.,0.,0.,0,"{Generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"p_refinement",8,2,1,0,585,kw_107,0.,0.,0.,0,"{Automated polynomial order refinement} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"probability_levels",14,1,10,0,787,kw_51,0.,0.,0.,0,"{Probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"quadrature_order",13,3,3,1,601,kw_108,0.,0.,0.,0,"{Quadrature order for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"reliability_levels",14,1,13,0,735,kw_100,0.,0.,0.,0,"{Reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"response_levels",14,2,14,0,739,kw_102,0.,0.,0.,0,"{Response levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"rng",8,2,12,0,795,kw_52,0.,0.,0.,0,"{Random number generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"sample_refinement",8,3,5,0,643,kw_109,0.,0.,0.,0,"{Importance sampling refinement} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"sample_type",8,2,6,0,651,kw_110,0.,0.,0.,0,"{Sampling type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"samples",9,0,8,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,7,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"sparse_grid_level",13,5,3,1,603,kw_111,0.,0.,0.,0,"{Sparse grid level for PCE coefficient estimation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDPCE"},
		{"variance_based_decomp",8,2,4,0,637,kw_112,0.,0.,0.,0,"{Variance based decomposition (VBD)} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"wiener",8,0,2,0,599}
		},
	kw_114[1] = {
		{"previous_samples",9,0,1,1,725,0,0.,0.,0.,0,"{Previous samples for incremental approaches} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"}
		},
	kw_115[4] = {
		{"incremental_lhs",8,1,1,1,721,kw_114},
		{"incremental_random",8,1,1,1,723,kw_114},
		{"lhs",8,0,1,1,719},
		{"random",8,0,1,1,717}
		},
	kw_116[1] = {
		{"drop_tolerance",10,0,1,0,729}
		},
	kw_117[12] = {
		{"all_variables",8,0,11,0,731,0,0.,0.,0.,0,"{All variables flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"distribution",8,2,5,0,781,kw_49,0.,0.,0.,0,"{Distribution type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"fixed_seed",8,0,12,0,733,0,0.,0.,0.,0,"{Fixed seed flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"gen_reliability_levels",14,1,7,0,791,kw_50,0.,0.,0.,0,"{Generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"probability_levels",14,1,6,0,787,kw_51,0.,0.,0.,0,"{Probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"reliability_levels",14,1,9,0,735,kw_100,0.,0.,0.,0,"{Reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"response_levels",14,2,10,0,739,kw_102,0.,0.,0.,0,"{Response levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"rng",8,2,8,0,795,kw_52,0.,0.,0.,0,"{Random number generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"sample_type",8,4,1,0,715,kw_115},
		{"samples",9,0,4,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,3,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"variance_based_decomp",8,1,2,0,727,kw_116}
		},
	kw_118[2] = {
		{"generalized",8,0,1,1,669},
		{"sobol",8,0,1,1,667}
		},
	kw_119[2] = {
		{"dimension_adaptive",8,2,1,1,665,kw_118},
		{"uniform",8,0,1,1,663}
		},
	kw_120[3] = {
		{"adapt_import",8,0,1,1,703},
		{"import",8,0,1,1,701},
		{"mm_adapt_import",8,0,1,1,705}
		},
	kw_121[2] = {
		{"lhs",8,0,1,1,709},
		{"random",8,0,1,1,711}
		},
	kw_122[2] = {
		{"restricted",8,0,1,0,681},
		{"unrestricted",8,0,1,0,683}
		},
	kw_123[2] = {
		{"drop_tolerance",10,0,2,0,697,0,0.,0.,0.,0,"{VBD tolerance for omitting small indices} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"univariate_effects",8,0,1,0,695,0,0.,0.,0.,0,"{Restriction of VBD indices to main/total} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"}
		},
	kw_124[24] = {
		{"all_variables",8,0,18,0,731,0,0.,0.,0.,0,"{All variables flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"askey",8,0,2,0,671},
		{"dimension_preference",14,0,4,0,685,0,0.,0.,0.,0,"{Dimension preference for anisotropic tensor and sparse grids} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"distribution",8,2,12,0,781,kw_49,0.,0.,0.,0,"{Distribution type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"fixed_seed",8,0,19,0,733,0,0.,0.,0.,0,"{Fixed seed flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"gen_reliability_levels",14,1,14,0,791,kw_50,0.,0.,0.,0,"{Generalized reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"h_refinement",8,2,1,0,661,kw_119},
		{"nested",8,0,6,0,689},
		{"non_nested",8,0,6,0,691},
		{"p_refinement",8,2,1,0,659,kw_119},
		{"piecewise",8,0,2,0,675},
		{"probability_levels",14,1,13,0,787,kw_51,0.,0.,0.,0,"{Probability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"quadrature_order",13,0,3,1,677,0,0.,0.,0.,0,"{Quadrature order for collocation points} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"reliability_levels",14,1,16,0,735,kw_100,0.,0.,0.,0,"{Reliability levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"response_levels",14,2,17,0,739,kw_102,0.,0.,0.,0,"{Response levels} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonD"},
		{"rng",8,2,15,0,795,kw_52,0.,0.,0.,0,"{Random number generator} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"sample_refinement",8,3,8,0,699,kw_120},
		{"sample_type",8,2,9,0,707,kw_121},
		{"samples",9,0,11,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,10,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"},
		{"sparse_grid_level",13,2,3,1,679,kw_122,0.,0.,0.,0,"{Sparse grid level for collocation points} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"use_derivatives",8,0,5,0,687,0,0.,0.,0.,0,"{Derivative usage flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"variance_based_decomp",8,2,7,0,693,kw_123,0.,0.,0.,0,"{Variance-based decomposition (VBD)} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDSC"},
		{"wiener",8,0,2,0,673}
		},
	kw_125[1] = {
		{"misc_options",15,0,1,0,569}
		},
	kw_126[12] = {
		{"function_precision",10,0,11,0,197,0,0.,0.,0.,0,"{Function precision} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"},
		{"linear_equality_constraint_matrix",14,0,6,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,8,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,9,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,7,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,1,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,2,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,4,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,5,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,3,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linesearch_tolerance",10,0,12,0,199,0,0.,0.,0.,0,"{Line search tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"},
		{"verify_level",9,0,10,0,195,0,0.,0.,0.,0,"{Gradient verification level} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"}
		},
	kw_127[11] = {
		{"gradient_tolerance",10,0,11,0,233},
		{"linear_equality_constraint_matrix",14,0,6,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,8,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,9,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,7,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,1,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,2,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,4,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,5,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,3,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"max_step",10,0,10,0,231}
		},
	kw_128[10] = {
		{"linear_equality_constraint_matrix",14,0,7,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,9,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,10,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,8,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,2,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,3,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,5,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,6,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,4,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"search_scheme_size",9,0,1,0,237}
		},
	kw_129[4] = {
		{"gradient_based_line_search",8,0,1,1,217,0,0.,0.,0.,0,"[CHOOSE line search type]"},
		{"tr_pds",8,0,1,1,221},
		{"trust_region",8,0,1,1,219},
		{"value_based_line_search",8,0,1,1,215}
		},
	kw_130[16] = {
		{"centering_parameter",10,0,5,0,229},
		{"central_path",11,0,3,0,225},
		{"gradient_tolerance",10,0,16,0,233},
		{"linear_equality_constraint_matrix",14,0,11,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,13,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,14,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,12,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,6,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,7,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,9,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,10,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,8,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"max_step",10,0,15,0,231},
		{"merit_function",11,0,2,0,223},
		{"search_method",8,4,1,0,213,kw_129},
		{"steplength_to_boundary",10,0,4,0,227}
		},
	kw_131[5] = {
		{"debug",8,0,1,1,67,0,0.,0.,0.,0,"[CHOOSE output level]"},
		{"normal",8,0,1,1,71},
		{"quiet",8,0,1,1,73},
		{"silent",8,0,1,1,75},
		{"verbose",8,0,1,1,69}
		},
	kw_132[3] = {
		{"partitions",13,0,1,0,917,0,0.,0.,0.,0,"{Number of partitions} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSUADE"},
		{"samples",9,0,3,0,919,0,0.,0.,0.,0,"{Number of samples} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC"},
		{"seed",9,0,2,0,921,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodEG"}
		},
	kw_133[4] = {
		{"converge_order",8,0,1,1,1115},
		{"converge_qoi",8,0,1,1,1117},
		{"estimate_order",8,0,1,1,1113},
		{"refinement_rate",10,0,2,0,1119,0,0.,0.,0.,0,"{Refinement rate} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSolnRichardson"}
		},
	kw_134[2] = {
		{"num_generations",0x29,0,2,0,343},
		{"percent_change",10,0,1,0,341}
		},
	kw_135[2] = {
		{"num_generations",0x29,0,2,0,337,0,0.,0.,0.,0,"{Number of generations (for convergence test) } http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"},
		{"percent_change",10,0,1,0,335,0,0.,0.,0.,0,"{Percent change in fitness} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"}
		},
	kw_136[2] = {
		{"average_fitness_tracker",8,2,1,1,339,kw_134},
		{"best_fitness_tracker",8,2,1,1,333,kw_135}
		},
	kw_137[2] = {
		{"constraint_penalty",10,0,2,0,319,0,0.,0.,0.,0,"{Constraint penalty in merit function} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"},
		{"merit_function",8,0,1,1,317}
		},
	kw_138[4] = {
		{"elitist",8,0,1,1,323},
		{"favor_feasible",8,0,1,1,325},
		{"roulette_wheel",8,0,1,1,327},
		{"unique_roulette_wheel",8,0,1,1,329}
		},
	kw_139[19] = {
		{"convergence_type",8,2,3,0,331,kw_136,0.,0.,0.,0,"{Convergence type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"},
		{"crossover_type",8,5,17,0,359,kw_86,0.,0.,0.,0,"{Crossover type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"fitness_type",8,2,1,0,315,kw_137,0.,0.,0.,0,"{Fitness type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"},
		{"initialization_type",8,3,16,0,351,kw_87,0.,0.,0.,0,"{Initialization type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"linear_equality_constraint_matrix",14,0,9,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,11,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,12,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,10,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,4,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,5,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,7,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,8,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,6,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"log_file",11,0,14,0,347,0,0.,0.,0.,0,"{Log file} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"mutation_type",8,6,18,0,375,kw_89,0.,0.,0.,0,"{Mutation type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"population_size",9,0,13,0,345,0,0.,0.,0.,0,"{Number of population members} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"print_each_pop",8,0,15,0,349,0,0.,0.,0.,0,"{Population output} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"},
		{"replacement_type",8,4,2,0,321,kw_138,0.,0.,0.,0,"{Replacement type} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGASOGA"},
		{"seed",9,0,19,0,391,0,0.,0.,0.,0,"{Random seed} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodJEGADC"}
		},
	kw_140[14] = {
		{"function_precision",10,0,12,0,197,0,0.,0.,0.,0,"{Function precision} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"},
		{"linear_equality_constraint_matrix",14,0,7,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,9,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,10,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,8,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,2,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,3,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,5,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,6,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,4,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linesearch_tolerance",10,0,13,0,199,0,0.,0.,0.,0,"{Line search tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"},
		{"nlssol",8,0,1,1,193},
		{"npsol",8,0,1,1,191},
		{"verify_level",9,0,11,0,195,0,0.,0.,0.,0,"{Gradient verification level} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNPSOLDC"}
		},
	kw_141[3] = {
		{"approx_method_name",11,0,1,1,573,0,0.,0.,0.,0,"[CHOOSE sub-method ref.]{Approximate sub-problem minimization method name} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBG"},
		{"approx_method_pointer",11,0,1,1,575,0,0.,0.,0.,0,"{Approximate sub-problem minimization method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBG"},
		{"replace_points",8,0,2,0,577,0,0.,0.,0.,0,"{Replace points used in surrogate construction with best points from previous iteration} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBG"}
		},
	kw_142[2] = {
		{"filter",8,0,1,1,145,0,0.,0.,0.,0,"@[CHOOSE acceptance logic]"},
		{"tr_ratio",8,0,1,1,143}
		},
	kw_143[7] = {
		{"augmented_lagrangian_objective",8,0,1,1,121,0,0.,0.,0.,0,"[CHOOSE objective formulation]"},
		{"lagrangian_objective",8,0,1,1,123},
		{"linearized_constraints",8,0,2,2,127,0,0.,0.,0.,0,"[CHOOSE constraint formulation]"},
		{"no_constraints",8,0,2,2,129},
		{"original_constraints",8,0,2,2,125,0,0.,0.,0.,0,"@"},
		{"original_primary",8,0,1,1,117,0,0.,0.,0.,0,"@"},
		{"single_objective",8,0,1,1,119}
		},
	kw_144[1] = {
		{"homotopy",8,0,1,1,149}
		},
	kw_145[4] = {
		{"adaptive_penalty_merit",8,0,1,1,135,0,0.,0.,0.,0,"[CHOOSE merit function]"},
		{"augmented_lagrangian_merit",8,0,1,1,139,0,0.,0.,0.,0,"@"},
		{"lagrangian_merit",8,0,1,1,137},
		{"penalty_merit",8,0,1,1,133}
		},
	kw_146[6] = {
		{"contract_threshold",10,0,3,0,107,0,0.,0.,0.,0,"{Shrink trust region if trust region ratio is below this value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"contraction_factor",10,0,5,0,111,0,0.,0.,0.,0,"{Trust region contraction factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"expand_threshold",10,0,4,0,109,0,0.,0.,0.,0,"{Expand trust region if trust region ratio is above this value} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"expansion_factor",10,0,6,0,113,0,0.,0.,0.,0,"{Trust region expansion factor} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"initial_size",10,0,1,0,103,0,0.,0.,0.,0,"{Trust region initial size (relative to bounds)} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"minimum_size",10,0,2,0,105,0,0.,0.,0.,0,"{Trust region minimum size} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"}
		},
	kw_147[18] = {
		{"acceptance_logic",8,2,7,0,141,kw_142,0.,0.,0.,0,"{SBL iterate acceptance logic} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"approx_method_name",11,0,1,1,93,0,0.,0.,0.,0,"[CHOOSE sub-method ref.]{Approximate sub-problem minimization method name} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"approx_method_pointer",11,0,1,1,95,0,0.,0.,0.,0,"{Approximate sub-problem minimization method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"approx_subproblem",8,7,5,0,115,kw_143,0.,0.,0.,0,"{Approximate subproblem formulation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"constraint_relax",8,1,8,0,147,kw_144,0.,0.,0.,0,"{SBL constraint relaxation method for infeasible iterates} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"linear_equality_constraint_matrix",14,0,14,0,403,0,0.,0.,0.,0,"{Linear equality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scale_types",15,0,16,0,407,0,0.,0.,0.,0,"{Linear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_scales",14,0,17,0,409,0,0.,0.,0.,0,"{Linear equality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_equality_targets",14,0,15,0,405,0,0.,0.,0.,0,"{Linear equality targets} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_constraint_matrix",14,0,9,0,393,0,0.,0.,0.,0,"{Linear inequality coefficient matrix} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_lower_bounds",14,0,10,0,395,0,0.,0.,0.,0,"{Linear inequality lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scale_types",15,0,12,0,399,0,0.,0.,0.,0,"{Linear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_scales",14,0,13,0,401,0,0.,0.,0.,0,"{Linear inequality scales} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"linear_inequality_upper_bounds",14,0,11,0,397,0,0.,0.,0.,0,"{Linear inequality upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"merit_function",8,4,6,0,131,kw_145,0.,0.,0.,0,"{SBL merit function} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"soft_convergence_limit",9,0,2,0,97,0,0.,0.,0.,0,"{Soft convergence limit for SBL iterations} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"trust_region",8,6,4,0,101,kw_146,0.,0.,0.,0,"{Trust region group specification} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"},
		{"truth_surrogate_bypass",8,0,3,0,99,0,0.,0.,0.,0,"{Flag for bypassing lower level surrogates in truth verifications} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSBL"}
		},
	kw_148[3] = {
		{"final_point",14,0,1,1,1091,0,0.,0.,0.,0,"[CHOOSE final pt or increment]{Termination point of vector} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSVPS"},
		{"num_steps",9,0,2,2,1095,0,0.,0.,0.,0,"{Number of steps along vector} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSVPS"},
		{"step_vector",14,0,1,1,1093,0,0.,0.,0.,0,"{Step vector} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSVPS"}
		},
	kw_149[75] = {
		{"asynch_pattern_search",8,18,11,1,239,kw_12,0.,0.,0.,0,0,"Optimization: Local, Derivative-free"},
		{"bayes_calibration",8,14,11,1,815,kw_20},
		{"centered_parameter_study",8,3,11,1,1101,kw_21,0.,0.,0.,0,"[CHOOSE PSTUDY method]{Centered parameter study} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSCPS","Parameter Studies"},
		{"coliny_apps",0,18,11,1,238,kw_12},
		{"coliny_cobyla",8,7,11,1,457,kw_22,0.,0.,0.,0,0,"Optimization: Local, Derivative-free"},
		{"coliny_direct",8,11,11,1,463,kw_24,0.,0.,0.,0,0,"Optimization: Global"},
		{"coliny_ea",8,14,11,1,481,kw_31,0.,0.,0.,0,0,"Optimization: Global"},
		{"coliny_pattern_search",8,17,11,1,411,kw_35,0.,0.,0.,0,0,"Optimization: Local, Derivative-free"},
		{"coliny_solis_wets",8,13,11,1,443,kw_36,0.,0.,0.,0,0,"Optimization: Local, Derivative-free"},
		{"conmin_frcg",8,9,11,1,179,kw_37,0.,0.,0.,0,"[CHOOSE OPT method]","Optimization: Local, Derivative-based"},
		{"conmin_mfd",8,9,11,1,181,kw_37,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"constraint_tolerance",10,0,8,0,85,0,0.,0.,0.,0,"{Constraint tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"convergence_tolerance",10,0,7,0,83,0,0.,0.,0.,0,"{Convergence tolerance} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"dace",8,14,11,1,865,kw_39,0.,0.,0.,0,0,"[CHOOSE method category]DACE"},
		{"dl_solver",11,9,11,1,183,kw_37,0.,0.,0.,0,0,"Optimization: Plug-in"},
		{"dot",8,15,11,1,161,kw_41},
		{"dot_bfgs",8,10,11,1,155,kw_42,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"dot_frcg",8,10,11,1,151,kw_42,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"dot_mmfd",8,10,11,1,153,kw_42,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"dot_slp",8,10,11,1,157,kw_42,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"dot_sqp",8,10,11,1,159,kw_42,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"efficient_global",8,2,11,1,579,kw_43,0.,0.,0.,0,0,"Surrogate-based Methods"},
		{"final_solutions",0x29,0,10,0,89,0,0.,0.,0.,0,"{Final solutions} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"fsu_cvt",8,8,11,1,893,kw_46,0.,0.,0.,0,0,"DACE"},
		{"fsu_quasi_mc",8,10,11,1,1065,kw_48,0.,0.,0.,0,0,"DACE"},
		{"global_evidence",8,9,11,1,763,kw_56,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"global_interval_est",8,5,11,1,801,kw_59,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"global_reliability",8,10,11,1,1023,kw_66,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"id_method",11,0,1,0,61,0,0.,0.,0.,0,"{Method set identifier} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"importance_sampling",8,7,11,1,751,kw_69,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"list_parameter_study",8,1,11,1,1097,kw_70,0.,0.,0.,0,"{List parameter study} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSLPS","Parameter Studies"},
		{"local_evidence",8,6,11,1,931,kw_76,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"local_interval_est",8,2,11,1,961,kw_77,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"local_reliability",8,7,11,1,967,kw_84,0.,0.,0.,0,"{Reliability method} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDLocalRel","Uncertainty Quantification"},
		{"max_function_evaluations",9,0,5,0,79,0,0.,0.,0.,0,"{Maximum function evaluations} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"max_iterations",9,0,4,0,77,0,0.,0.,0.,0,"{Maximum iterations} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"model_pointer",11,0,2,0,63,0,0.,0.,0.,0,"{Model pointer} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"moga",8,21,11,1,275,kw_96,0.,0.,0.,0,0,"Optimization: Global"},
		{"multidim_parameter_study",8,1,11,1,1107,kw_97,0.,0.,0.,0,"{Multidimensional parameter study} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSMPS","Parameter Studies"},
		{"ncsu_direct",8,4,11,1,923,kw_98,0.,0.,0.,0,0,"Optimization: Global"},
		{"nl2sol",8,9,11,1,547,kw_99,0.,0.,0.,0,"[CHOOSE LSQ method]","Nonlinear Least Squares"},
		{"nlpql_sqp",8,9,11,1,201,kw_37,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"nlssol_sqp",8,12,11,1,187,kw_126,0.,0.,0.,0,0,"Nonlinear Least Squares"},
		{"nond_bayes_calibration",0,14,11,1,814,kw_20},
		{"nond_global_evidence",0,9,11,1,762,kw_56},
		{"nond_global_interval_est",0,5,11,1,800,kw_59},
		{"nond_global_reliability",0,10,11,1,1022,kw_66},
		{"nond_importance_sampling",0,7,11,1,750,kw_69},
		{"nond_local_evidence",0,6,11,1,930,kw_76},
		{"nond_local_interval_est",0,2,11,1,960,kw_77},
		{"nond_local_reliability",0,7,11,1,966,kw_84},
		{"nond_polynomial_chaos",0,23,11,1,582,kw_113},
		{"nond_sampling",0,12,11,1,712,kw_117},
		{"nond_stoch_collocation",0,24,11,1,656,kw_124},
		{"nonlinear_cg",8,1,11,1,567,kw_125,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"npsol_sqp",8,12,11,1,185,kw_126,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"optpp_cg",8,11,11,1,203,kw_127,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"optpp_fd_newton",8,16,11,1,207,kw_130,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"optpp_g_newton",8,16,11,1,209,kw_130,0.,0.,0.,0,0,"Nonlinear Least Squares"},
		{"optpp_newton",8,16,11,1,211,kw_130,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"optpp_pds",8,10,11,1,235,kw_128,0.,0.,0.,0,0,"Optimization: Local, Derivative-free"},
		{"optpp_q_newton",8,16,11,1,205,kw_130,0.,0.,0.,0,0,"Optimization: Local, Derivative-based"},
		{"output",8,5,3,0,65,kw_131,0.,0.,0.,0,"{Output verbosity} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"polynomial_chaos",8,23,11,1,583,kw_113,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"psuade_moat",8,3,11,1,915,kw_132,0.,0.,0.,0,"{PSUADE MOAT method} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSUADE","DACE"},
		{"richardson_extrap",8,4,11,1,1111,kw_133,0.,0.,0.,0,"{Richardson extrapolation} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodSolnRichardson"},
		{"sampling",8,12,11,1,713,kw_117,0.,0.,0.,0,"{Nondeterministic sampling method} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodNonDMC","Uncertainty Quantification"},
		{"scaling",8,0,9,0,87,0,0.,0.,0.,0,"{Scaling flag} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"soga",8,19,11,1,313,kw_139,0.,0.,0.,0,0,"Optimization: Global"},
		{"speculative",8,0,6,0,81,0,0.,0.,0.,0,"{Speculative gradients and Hessians} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodIndControl"},
		{"stanford",8,14,11,1,189,kw_140},
		{"stoch_collocation",8,24,11,1,657,kw_124,0.,0.,0.,0,0,"Uncertainty Quantification"},
		{"surrogate_based_global",8,3,11,1,571,kw_141,0.,0.,0.,0,0,"Surrogate-based Methods"},
		{"surrogate_based_local",8,18,11,1,91,kw_147,0.,0.,0.,0,0,"Surrogate-based Methods"},
		{"vector_parameter_study",8,3,11,1,1089,kw_148,0.,0.,0.,0,"{Vector parameter study} http://dakota.sandia.gov/licensing/votd/html-ref/MethodCommands.html#MethodPSVPS","Parameter Studies"}
		},
	kw_150[1] = {
		{"optional_interface_responses_pointer",11,0,1,0,1281,0,0.,0.,0.,0,"{Responses pointer for nested model optional interfaces} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"}
		},
	kw_151[4] = {
		{"primary_response_mapping",14,0,3,0,1289,0,0.,0.,0.,0,"{Primary response mappings for nested models} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"},
		{"primary_variable_mapping",15,0,1,0,1285,0,0.,0.,0.,0,"{Primary variable mappings for nested models} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"},
		{"secondary_response_mapping",14,0,4,0,1291,0,0.,0.,0.,0,"{Secondary response mappings for nested models} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"},
		{"secondary_variable_mapping",15,0,2,0,1287,0,0.,0.,0.,0,"{Secondary variable mappings for nested models} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"}
		},
	kw_152[2] = {
		{"optional_interface_pointer",11,1,1,0,1279,kw_150,0.,0.,0.,0,"{Optional interface set pointer} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"},
		{"sub_method_pointer",11,4,2,1,1283,kw_151,0.,0.,0.,0,"{Sub-method pointer for nested models} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelNested"}
		},
	kw_153[1] = {
		{"interface_pointer",11,0,1,0,1131,0,0.,0.,0.,0,"{Interface set pointer} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSingle"}
		},
	kw_154[6] = {
		{"additive",8,0,2,2,1239,0,0.,0.,0.,0,"[CHOOSE correction type]"},
		{"combined",8,0,2,2,1243},
		{"first_order",8,0,1,1,1235,0,0.,0.,0.,0,"[CHOOSE correction order]"},
		{"multiplicative",8,0,2,2,1241},
		{"second_order",8,0,1,1,1237},
		{"zeroth_order",8,0,1,1,1233}
		},
	kw_155[3] = {
		{"constant",8,0,1,1,1145,0,0.,0.,0.,0,"[CHOOSE trend type]"},
		{"linear",8,0,1,1,1147},
		{"reduced_quadratic",8,0,1,1,1149}
		},
	kw_156[2] = {
		{"point_selection",8,0,1,0,1141,0,0.,0.,0.,0,"{GP point selection} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"trend",8,3,2,0,1143,kw_155,0.,0.,0.,0,"{GP trend function} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_157[4] = {
		{"constant",8,0,1,1,1197},
		{"linear",8,0,1,1,1199},
		{"quadratic",8,0,1,1,1203},
		{"reduced_quadratic",8,0,1,1,1201}
		},
	kw_158[4] = {
		{"correlation_lengths",14,0,4,0,1209,0,0.,0.,0.,0,"{Kriging correlation lengths} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"max_trials",0x19,0,3,0,1207,0,0.,0.,0.,0,"{Kriging maximum trials} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"optimization_method",11,0,2,0,1205,0,0.,0.,0.,0,"{Kriging optimization method} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"trend",8,4,1,0,1195,kw_157,0.,0.,0.,0,"{Kriging trend function} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_159[2] = {
		{"cubic",8,0,1,1,1159},
		{"linear",8,0,1,1,1157}
		},
	kw_160[2] = {
		{"interpolation",8,2,2,0,1155,kw_159,0.,0.,0.,0,"{MARS interpolation} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"max_bases",9,0,1,0,1153,0,0.,0.,0.,0,"{MARS maximum bases} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_161[2] = {
		{"poly_order",9,0,1,0,1163,0,0.,0.,0.,0,"{MLS polynomial order} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"weight_function",9,0,2,0,1165,0,0.,0.,0.,0,"{MLS weight function} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_162[3] = {
		{"nodes",9,0,1,0,1169,0,0.,0.,0.,0,"{ANN number nodes} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"random_weight",9,0,3,0,1173,0,0.,0.,0.,0,"{ANN random weight} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"range",10,0,2,0,1171,0,0.,0.,0.,0,"{ANN range} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_163[3] = {
		{"cubic",8,0,1,1,1191,0,0.,0.,0.,0,"[CHOOSE polynomial order]"},
		{"linear",8,0,1,1,1187},
		{"quadratic",8,0,1,1,1189}
		},
	kw_164[4] = {
		{"bases",9,0,1,0,1177,0,0.,0.,0.,0,"{RBF number of bases} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"max_pts",9,0,2,0,1179,0,0.,0.,0.,0,"{RBF maximum points} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"max_subsets",9,0,4,0,1183},
		{"min_partition",9,0,3,0,1181,0,0.,0.,0.,0,"{RBF minimum partitions} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"}
		},
	kw_165[3] = {
		{"all",8,0,1,1,1221},
		{"none",8,0,1,1,1225},
		{"region",8,0,1,1,1223}
		},
	kw_166[18] = {
		{"correction",8,6,7,0,1231,kw_154,0.,0.,0.,0,"{Surrogate correction approach} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"dace_method_pointer",11,0,3,0,1217,0,0.,0.,0.,0,"{Design of experiments method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"diagnostics",15,0,8,0,1245,0,0.,0.,0.,0,"{Print diagnostic metrics about the surrogate goodness of fit} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"gaussian_process",8,2,1,1,1139,kw_156,0.,0.,0.,0,"[CHOOSE surrogate type]{Gaussian process} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"kriging",8,4,1,1,1193,kw_158,0.,0.,0.,0,"{Kriging interpolation} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"mars",8,2,1,1,1151,kw_160,0.,0.,0.,0,"{Multivariate adaptive regression splines} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"minimum_points",8,0,2,0,1213},
		{"moving_least_squares",8,2,1,1,1161,kw_161,0.,0.,0.,0,"{Moving least squares} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"neural_network",8,3,1,1,1167,kw_162,0.,0.,0.,0,"{Artificial neural network} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"points_file",11,0,5,0,1227},
		{"polynomial",8,3,1,1,1185,kw_163,0.,0.,0.,0,"{Polynomial} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"radial_basis",8,4,1,1,1175,kw_164},
		{"recommended_points",8,0,2,0,1215},
		{"reuse_points",8,3,4,0,1219,kw_165},
		{"reuse_samples",0,3,4,0,1218,kw_165},
		{"samples_file",3,0,5,0,1226},
		{"total_points",9,0,2,0,1211},
		{"use_derivatives",8,0,6,0,1229}
		},
	kw_167[6] = {
		{"additive",8,0,2,2,1271,0,0.,0.,0.,0,"[CHOOSE correction type]"},
		{"combined",8,0,2,2,1275},
		{"first_order",8,0,1,1,1267,0,0.,0.,0.,0,"[CHOOSE correction order]"},
		{"multiplicative",8,0,2,2,1273},
		{"second_order",8,0,1,1,1269},
		{"zeroth_order",8,0,1,1,1265}
		},
	kw_168[3] = {
		{"correction",8,6,3,3,1263,kw_167,0.,0.,0.,0,"{Surrogate correction approach} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrH"},
		{"high_fidelity_model_pointer",11,0,2,2,1261,0,0.,0.,0.,0,"{Pointer to the high fidelity model specification} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrH"},
		{"low_fidelity_model_pointer",11,0,1,1,1259,0,0.,0.,0.,0,"{Pointer to the low fidelity model specification} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrH"}
		},
	kw_169[2] = {
		{"actual_model_pointer",11,0,2,2,1255,0,0.,0.,0.,0,"{Pointer to the truth model specification} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrMP"},
		{"taylor_series",8,0,1,1,1253,0,0.,0.,0.,0,"{Taylor series local approximation } http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrL"}
		},
	kw_170[2] = {
		{"actual_model_pointer",11,0,2,2,1255,0,0.,0.,0.,0,"{Pointer to the truth model specification} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrMP"},
		{"tana",8,0,1,1,1249,0,0.,0.,0.,0,"{Two-point adaptive nonlinear approximation } http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrMP"}
		},
	kw_171[5] = {
		{"global",8,18,2,1,1137,kw_166,0.,0.,0.,0,"[CHOOSE surrogate category]{Global approximations } http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrG"},
		{"hierarchical",8,3,2,1,1257,kw_168,0.,0.,0.,0,"{Hierarchical approximation } http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrH"},
		{"id_surrogates",13,0,1,0,1135,0,0.,0.,0.,0,"{Surrogate response ids} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrogate"},
		{"local",8,2,2,1,1251,kw_169,0.,0.,0.,0,"{Local approximation} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrL"},
		{"multipoint",8,2,2,1,1247,kw_170,0.,0.,0.,0,"{Multipoint approximation} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelSurrMP"}
		},
	kw_172[6] = {
		{"id_model",11,0,1,0,1123,0,0.,0.,0.,0,"{Model set identifier} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelIndControl"},
		{"nested",8,2,4,1,1277,kw_152,0.,0.,0.,0,"[CHOOSE model type]"},
		{"responses_pointer",11,0,3,0,1127,0,0.,0.,0.,0,"{Responses set pointer} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelIndControl"},
		{"single",8,1,4,1,1129,kw_153,0.,0.,0.,0,"@"},
		{"surrogate",8,5,4,1,1133,kw_171},
		{"variables_pointer",11,0,2,0,1125,0,0.,0.,0.,0,"{Variables set pointer} http://dakota.sandia.gov/licensing/votd/html-ref/ModelCommands.html#ModelIndControl"}
		},
	kw_173[1] = {
		{"ignore_bounds",8,0,1,0,1731,0,0.,0.,0.,0,"{Ignore variable bounds} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"}
		},
	kw_174[10] = {
		{"central",8,0,6,0,1739,0,0.,0.,0.,0,"[CHOOSE difference interval]"},
		{"dakota",8,1,4,0,1729,kw_173,0.,0.,0.,0,"@[CHOOSE gradient source]"},
		{"fd_gradient_step_size",0x406,0,7,0,1740,0,0.,0.,0.001},
		{"fd_step_size",0x40e,0,7,0,1741,0,0.,0.,0.001,0,"{Finite difference step size} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"},
		{"forward",8,0,6,0,1737,0,0.,0.,0.,0,"@"},
		{"id_analytic_gradients",13,0,2,2,1723,0,0.,0.,0.,0,"{Analytic derivatives function list} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"},
		{"id_numerical_gradients",13,0,1,1,1721,0,0.,0.,0.,0,"{Numerical derivatives function list} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"},
		{"interval_type",8,0,5,0,1735,0,0.,0.,0.,0,"{Interval type} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradNum"},
		{"method_source",8,0,3,0,1727,0,0.,0.,0.,0,"{Method source} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradNum"},
		{"vendor",8,0,4,0,1733}
		},
	kw_175[2] = {
		{"fd_hessian_step_size",6,0,1,0,1766},
		{"fd_step_size",14,0,1,0,1767,0,0.,0.,0.,0,"{Finite difference step size} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"}
		},
	kw_176[1] = {
		{"damped",8,0,1,0,1777,0,0.,0.,0.,0,"{Numerical safeguarding of BFGS update} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"}
		},
	kw_177[2] = {
		{"bfgs",8,1,1,1,1775,kw_176,0.,0.,0.,0,"[CHOOSE Hessian approx.]"},
		{"sr1",8,0,1,1,1779}
		},
	kw_178[5] = {
		{"central",8,0,2,0,1771,0,0.,0.,0.,0,"[CHOOSE difference interval]"},
		{"forward",8,0,2,0,1769,0,0.,0.,0.,0,"@"},
		{"id_analytic_hessians",13,0,4,0,1781,0,0.,0.,0.,0,"{Analytic Hessians function list} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"},
		{"id_numerical_hessians",13,2,1,0,1765,kw_175,0.,0.,0.,0,"{Numerical Hessians function list} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"},
		{"id_quasi_hessians",13,2,3,0,1773,kw_177,0.,0.,0.,0,"{Quasi Hessians function list} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"}
		},
	kw_179[3] = {
		{"nonlinear_equality_scale_types",0x80f,0,2,0,1709,0,0.,0.,0.,0,"{Nonlinear equality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_equality_constraints"},
		{"nonlinear_equality_scales",0x80e,0,3,0,1711,0,0.,0.,0.,0,"{Nonlinear equality constraint scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_equality_constraints"},
		{"nonlinear_equality_targets",14,0,1,0,1707,0,0.,0.,0.,0,"{Nonlinear equality constraint targets} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_equality_constraints"}
		},
	kw_180[4] = {
		{"nonlinear_inequality_lower_bounds",14,0,1,0,1697,0,0.,0.,0.,0,"{Nonlinear inequality constraint lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_scale_types",0x80f,0,3,0,1701,0,0.,0.,0.,0,"{Nonlinear inequality scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_scales",0x80e,0,4,0,1703,0,0.,0.,0.,0,"{Nonlinear inequality constraint scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_upper_bounds",14,0,2,0,1699,0,0.,0.,0.,0,"{Nonlinear inequality constraint upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_nonlinear_inequality_constraints"}
		},
	kw_181[6] = {
		{"least_squares_data_file",11,0,1,0,1687,0,0.,0.,0.,0,"{Least squares data source file} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS"},
		{"least_squares_term_scale_types",0x80f,0,2,0,1689,0,0.,0.,0.,0,"{Least squares term scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_least_squares_terms"},
		{"least_squares_term_scales",0x80e,0,3,0,1691,0,0.,0.,0.,0,"{Least squares terms scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_least_squares_terms"},
		{"least_squares_weights",14,0,4,0,1693,0,0.,0.,0.,0,"{Least squares terms weightings} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS",0,"num_least_squares_terms"},
		{"num_nonlinear_equality_constraints",0x29,3,6,0,1705,kw_179,0.,0.,0.,0,"{Number of nonlinear equality constraints} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS"},
		{"num_nonlinear_inequality_constraints",0x29,4,5,0,1695,kw_180,0.,0.,0.,0,"{Number of nonlinear inequality constraints} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS"}
		},
	kw_182[3] = {
		{"nonlinear_equality_scale_types",0x80f,0,2,0,1681,0,0.,0.,0.,0,"{Nonlinear equality constraint scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_equality_constraints"},
		{"nonlinear_equality_scales",0x80e,0,3,0,1683,0,0.,0.,0.,0,"{Nonlinear equality constraint scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_equality_constraints"},
		{"nonlinear_equality_targets",14,0,1,0,1679,0,0.,0.,0.,0,"{Nonlinear equality constraint targets} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_equality_constraints"}
		},
	kw_183[4] = {
		{"nonlinear_inequality_lower_bounds",14,0,1,0,1669,0,0.,0.,0.,0,"{Nonlinear inequality constraint lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_scale_types",0x80f,0,3,0,1673,0,0.,0.,0.,0,"{Nonlinear inequality constraint scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_scales",0x80e,0,4,0,1675,0,0.,0.,0.,0,"{Nonlinear inequality constraint scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_inequality_constraints"},
		{"nonlinear_inequality_upper_bounds",14,0,2,0,1671,0,0.,0.,0.,0,"{Nonlinear inequality constraint upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_inequality_constraints"}
		},
	kw_184[5] = {
		{"multi_objective_weights",14,0,3,0,1665,0,0.,0.,0.,0,"{Multiobjective weightings} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_objective_functions"},
		{"num_nonlinear_equality_constraints",0x29,3,5,0,1677,kw_182,0.,0.,0.,0,"{Number of nonlinear equality constraints} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_nonlinear_equality_constraints"},
		{"num_nonlinear_inequality_constraints",0x29,4,4,0,1667,kw_183,0.,0.,0.,0,"{Number of nonlinear inequality constraints} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt"},
		{"objective_function_scale_types",0x80f,0,1,0,1661,0,0.,0.,0.,0,"{Objective function scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_objective_functions"},
		{"objective_function_scales",0x80e,0,2,0,1663,0,0.,0.,0.,0,"{Objective function scales} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt",0,"num_objective_functions"}
		},
	kw_185[8] = {
		{"central",8,0,6,0,1739,0,0.,0.,0.,0,"[CHOOSE difference interval]"},
		{"dakota",8,1,4,0,1729,kw_173,0.,0.,0.,0,"@[CHOOSE gradient source]"},
		{"fd_gradient_step_size",0x406,0,7,0,1740,0,0.,0.,0.001},
		{"fd_step_size",0x40e,0,7,0,1741,0,0.,0.,0.001,0,"{Finite difference step size} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"},
		{"forward",8,0,6,0,1737,0,0.,0.,0.,0,"@"},
		{"interval_type",8,0,5,0,1735,0,0.,0.,0.,0,"{Interval type} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradNum"},
		{"method_source",8,0,3,0,1727,0,0.,0.,0.,0,"{Method source} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradNum"},
		{"vendor",8,0,4,0,1733}
		},
	kw_186[4] = {
		{"central",8,0,2,0,1751,0,0.,0.,0.,0,"[CHOOSE difference interval]"},
		{"fd_hessian_step_size",6,0,1,0,1746},
		{"fd_step_size",14,0,1,0,1747,0,0.,0.,0.,0,"{Finite difference step size} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessNum"},
		{"forward",8,0,2,0,1749,0,0.,0.,0.,0,"@"}
		},
	kw_187[1] = {
		{"damped",8,0,1,0,1757,0,0.,0.,0.,0,"{Numerical safeguarding of BFGS update} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessQuasi"}
		},
	kw_188[2] = {
		{"bfgs",8,1,1,1,1755,kw_187,0.,0.,0.,0,"[CHOOSE Hessian approx.]"},
		{"sr1",8,0,1,1,1759}
		},
	kw_189[15] = {
		{"analytic_gradients",8,0,4,2,1717,0,0.,0.,0.,0,"[CHOOSE gradient type]"},
		{"analytic_hessians",8,0,5,3,1761,0,0.,0.,0.,0,"[CHOOSE Hessian type]"},
		{"descriptors",15,0,2,0,1657,0,0.,0.,0.,0,"{Response labels} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespLabels"},
		{"id_responses",11,0,1,0,1655,0,0.,0.,0.,0,"{Responses set identifier} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespSetId"},
		{"mixed_gradients",8,10,4,2,1719,kw_174,0.,0.,0.,0,"{Mixed gradients} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradMixed"},
		{"mixed_hessians",8,5,5,3,1763,kw_178,0.,0.,0.,0,"{Mixed Hessians} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessMixed"},
		{"no_gradients",8,0,4,2,1715,0,0.,0.,0.,0,"@"},
		{"no_hessians",8,0,5,3,1743,0,0.,0.,0.,0,"@"},
		{"num_least_squares_terms",0x29,6,3,1,1685,kw_181,0.,0.,0.,0,"[CHOOSE response type]{{Least squares (calibration)} Number of least squares terms} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnLS"},
		{"num_objective_functions",0x29,5,3,1,1659,kw_184,0.,0.,0.,0,"{{Optimization} Number of objective functions} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnOpt"},
		{"num_response_functions",0x29,0,3,1,1713,0,0.,0.,0.,0,"{{Generic responses} Number of response functions} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespFnGen"},
		{"numerical_gradients",8,8,4,2,1725,kw_185,0.,0.,0.,0,"{Numerical gradients} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespGradNum"},
		{"numerical_hessians",8,4,5,3,1745,kw_186,0.,0.,0.,0,"{Numerical Hessians} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessNum"},
		{"quasi_hessians",8,2,5,3,1753,kw_188,0.,0.,0.,0,"{Quasi Hessians} http://dakota.sandia.gov/licensing/votd/html-ref/RespCommands.html#RespHessQuasi"},
		{"response_descriptors",7,0,2,0,1656}
		},
	kw_190[1] = {
		{"method_list",15,0,1,1,33,0,0.,0.,0.,0,"{List of methods} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"}
		},
	kw_191[3] = {
		{"global_method_pointer",11,0,1,1,25,0,0.,0.,0.,0,"{Pointer to the global method specification} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"local_method_pointer",11,0,2,2,27,0,0.,0.,0.,0,"{Pointer to the local method specification} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"local_search_probability",10,0,3,0,29,0,0.,0.,0.,0,"{Probability of executing local searches} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"}
		},
	kw_192[1] = {
		{"method_list",15,0,1,1,21,0,0.,0.,0.,0,"{List of methods} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"}
		},
	kw_193[5] = {
		{"collaborative",8,1,1,1,31,kw_190,0.,0.,0.,0,"[CHOOSE hybrid type]{Collaborative hybrid} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"coupled",0,3,1,1,22,kw_191},
		{"embedded",8,3,1,1,23,kw_191,0.,0.,0.,0,"{Embedded hybrid} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"sequential",8,1,1,1,19,kw_192,0.,0.,0.,0,"{Sequential hybrid} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"uncoupled",0,1,1,1,18,kw_192}
		},
	kw_194[1] = {
		{"seed",9,0,1,0,41,0,0.,0.,0.,0,"{Seed for random starting points} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratMultiStart"}
		},
	kw_195[3] = {
		{"method_pointer",11,0,1,1,37,0,0.,0.,0.,0,"{Method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratMultiStart"},
		{"random_starts",9,1,2,0,39,kw_194,0.,0.,0.,0,"{Number of random starting points} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratMultiStart"},
		{"starting_points",14,0,3,0,43,0,0.,0.,0.,0,"{List of user-specified starting points} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratMultiStart"}
		},
	kw_196[1] = {
		{"seed",9,0,1,0,51,0,0.,0.,0.,0,"{Seed for random weighting sets} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratParetoSet"}
		},
	kw_197[5] = {
		{"method_pointer",11,0,1,1,47,0,0.,0.,0.,0,"{Optimization method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratParetoSet"},
		{"multi_objective_weight_sets",6,0,3,0,52},
		{"opt_method_pointer",3,0,1,1,46},
		{"random_weight_sets",9,1,2,0,49,kw_196,0.,0.,0.,0,"{Number of random weighting sets} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratParetoSet"},
		{"weight_sets",14,0,3,0,53,0,0.,0.,0.,0,"{List of user-specified weighting sets} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratParetoSet"}
		},
	kw_198[1] = {
		{"method_pointer",11,0,1,0,57,0,0.,0.,0.,0,"{Method pointer} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratSingle"}
		},
	kw_199[1] = {
		{"tabular_graphics_file",11,0,1,0,7,0,0.,0.,0.,0,"{File name for tabular graphics data} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"}
		},
	kw_200[10] = {
		{"graphics",8,0,1,0,3,0,0.,0.,0.,0,"{Graphics flag} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"},
		{"hybrid",8,5,7,1,17,kw_193,0.,0.,0.,0,"[CHOOSE strategy type]{Hybrid strategy} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratHybrid"},
		{"iterator_self_scheduling",8,0,5,0,13,0,0.,0.,0.,0,"{Self-scheduling of iterator jobs} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"},
		{"iterator_servers",9,0,4,0,11,0,0.,0.,0.,0,"{Number of iterator servers} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"},
		{"iterator_static_scheduling",8,0,6,0,15,0,0.,0.,0.,0,"{Static scheduling of iterator jobs} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"},
		{"multi_start",8,3,7,1,35,kw_195,0.,0.,0.,0,"{Multi-start iteration strategy} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratMultiStart"},
		{"output_precision",0x29,0,3,0,9,0,0.,0.,0.,0,"{Numeric output precision} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"},
		{"pareto_set",8,5,7,1,45,kw_197,0.,0.,0.,0,"{Pareto set optimization strategy} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratParetoSet"},
		{"single_method",8,1,7,1,55,kw_198,0.,0.,0.,0,"@{Single method strategy} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratSingle"},
		{"tabular_graphics_data",8,1,2,0,5,kw_199,0.,0.,0.,0,"{Tabulation of graphics data} http://dakota.sandia.gov/licensing/votd/html-ref/StratCommands.html#StratIndControl"}
		},
	kw_201[10] = {
		{"alphas",14,0,1,1,1405,0,0.,0.,0.,0,"{beta uncertain alphas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta",0,"beta_uncertain"},
		{"betas",14,0,2,2,1407,0,0.,0.,0.,0,"{beta uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta",0,"beta_uncertain"},
		{"buv_alphas",6,0,1,1,1404,0,0.,0.,0.,0,0,0,"beta_uncertain"},
		{"buv_betas",6,0,2,2,1406,0,0.,0.,0.,0,0,0,"beta_uncertain"},
		{"buv_descriptors",7,0,5,0,1412,0,0.,0.,0.,0,0,0,"beta_uncertain"},
		{"buv_lower_bounds",6,0,3,3,1408,0,0.,0.,0.,0,0,0,"beta_uncertain"},
		{"buv_upper_bounds",6,0,4,4,1410,0,0.,0.,0.,0,0,0,"beta_uncertain"},
		{"descriptors",15,0,5,0,1413,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta",0,"beta_uncertain"},
		{"lower_bounds",14,0,3,3,1409,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta",0,"beta_uncertain"},
		{"upper_bounds",14,0,4,4,1411,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta",0,"beta_uncertain"}
		},
	kw_202[3] = {
		{"descriptors",15,0,3,0,1471,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Binomial",0,"binomial_uncertain"},
		{"num_trials",13,0,2,2,1469,0,0.,0.,0.,0,"{binomial uncertain num_trials} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Binomial",0,"binomial_uncertain"},
		{"prob_per_trial",14,0,1,1,1467,0,0.,0.,0.,0,"{binomial uncertain prob_per_trial} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Binomial",0,"binomial_uncertain"}
		},
	kw_203[12] = {
		{"cdv_descriptors",7,0,6,0,1308,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"cdv_initial_point",6,0,1,0,1298,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"cdv_lower_bounds",6,0,2,0,1300,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"cdv_scale_types",0x807,0,4,0,1304,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"cdv_scales",0x806,0,5,0,1306,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"cdv_upper_bounds",6,0,3,0,1302,0,0.,0.,0.,0,0,0,"continuous_design"},
		{"descriptors",15,0,6,0,1309,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"},
		{"initial_point",14,0,1,0,1299,0,0.,0.,0.,0,"{Initial point} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"},
		{"lower_bounds",14,0,2,0,1301,0,0.,0.,0.,0,"{Lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"},
		{"scale_types",0x80f,0,4,0,1305,0,0.,0.,0.,0,"{Scaling types} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"},
		{"scales",0x80e,0,5,0,1307,0,0.,0.,0.,0,"{Scales} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"},
		{"upper_bounds",14,0,3,0,1303,0,0.,0.,0.,0,"{Upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV",0,"continuous_design"}
		},
	kw_204[8] = {
		{"csv_descriptors",7,0,4,0,1526,0,0.,0.,0.,0,0,0,"continuous_state"},
		{"csv_initial_state",6,0,1,0,1520,0,0.,0.,0.,0,0,0,"continuous_state"},
		{"csv_lower_bounds",6,0,2,0,1522,0,0.,0.,0.,0,0,0,"continuous_state"},
		{"csv_upper_bounds",6,0,3,0,1524,0,0.,0.,0.,0,0,0,"continuous_state"},
		{"descriptors",15,0,4,0,1527,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCSV",0,"continuous_state"},
		{"initial_state",14,0,1,0,1521,0,0.,0.,0.,0,"{Initial states} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCSV",0,"continuous_state"},
		{"lower_bounds",14,0,2,0,1523,0,0.,0.,0.,0,"{Lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCSV",0,"continuous_state"},
		{"upper_bounds",14,0,3,0,1525,0,0.,0.,0.,0,"{Upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCSV",0,"continuous_state"}
		},
	kw_205[8] = {
		{"ddv_descriptors",7,0,4,0,1318,0,0.,0.,0.,0,0,0,"discrete_design_range"},
		{"ddv_initial_point",5,0,1,0,1312,0,0.,0.,0.,0,0,0,"discrete_design_range"},
		{"ddv_lower_bounds",5,0,2,0,1314,0,0.,0.,0.,0,0,0,"discrete_design_range"},
		{"ddv_upper_bounds",5,0,3,0,1316,0,0.,0.,0.,0,0,0,"discrete_design_range"},
		{"descriptors",15,0,4,0,1319,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDRIV",0,"discrete_design_range"},
		{"initial_point",13,0,1,0,1313,0,0.,0.,0.,0,"{Initial point} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDRIV",0,"discrete_design_range"},
		{"lower_bounds",13,0,2,0,1315,0,0.,0.,0.,0,"{Lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDRIV",0,"discrete_design_range"},
		{"upper_bounds",13,0,3,0,1317,0,0.,0.,0.,0,"{Upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDRIV",0,"discrete_design_range"}
		},
	kw_206[4] = {
		{"descriptors",15,0,4,0,1329,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSIV",0,"discrete_design_set_integer"},
		{"initial_point",13,0,1,0,1323,0,0.,0.,0.,0,"{Initial point} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSIV",0,"discrete_design_set_integer"},
		{"num_set_values",13,0,2,0,1325,0,0.,0.,0.,0,"{Number of values for each variable} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSIV",0,"discrete_design_set_integer"},
		{"set_values",13,0,3,1,1327,0,0.,0.,0.,0,"{Set values} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSIV"}
		},
	kw_207[4] = {
		{"descriptors",15,0,4,0,1339,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSRV",0,"discrete_design_set_real"},
		{"initial_point",14,0,1,0,1333,0,0.,0.,0.,0,"{Initial point} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSRV",0,"discrete_design_set_real"},
		{"num_set_values",13,0,2,0,1335,0,0.,0.,0.,0,"{Number of values for each variable} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSRV",0,"discrete_design_set_real"},
		{"set_values",14,0,3,1,1337,0,0.,0.,0.,0,"{Set values} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSRV"}
		},
	kw_208[8] = {
		{"descriptors",15,0,4,0,1537,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSRIV",0,"discrete_state_range"},
		{"dsv_descriptors",7,0,4,0,1536,0,0.,0.,0.,0,0,0,"discrete_state_range"},
		{"dsv_initial_state",5,0,1,0,1530,0,0.,0.,0.,0,0,0,"discrete_state_range"},
		{"dsv_lower_bounds",5,0,2,0,1532,0,0.,0.,0.,0,0,0,"discrete_state_range"},
		{"dsv_upper_bounds",5,0,3,0,1534,0,0.,0.,0.,0,0,0,"discrete_state_range"},
		{"initial_state",13,0,1,0,1531,0,0.,0.,0.,0,"{Initial states} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSRIV",0,"discrete_state_range"},
		{"lower_bounds",13,0,2,0,1533,0,0.,0.,0.,0,"{Lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSRIV",0,"discrete_state_range"},
		{"upper_bounds",13,0,3,0,1535,0,0.,0.,0.,0,"{Upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSRIV",0,"discrete_state_range"}
		},
	kw_209[4] = {
		{"descriptors",15,0,4,0,1547,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSIV",0,"discrete_state_set_integer"},
		{"initial_state",13,0,1,0,1541,0,0.,0.,0.,0,"{Initial state} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSIV",0,"discrete_state_set_integer"},
		{"num_set_values",13,0,2,0,1543,0,0.,0.,0.,0,"{Number of values for each variable} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSIV",0,"discrete_state_set_integer"},
		{"set_values",13,0,3,1,1545,0,0.,0.,0.,0,"{Set values} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSIV"}
		},
	kw_210[4] = {
		{"descriptors",15,0,4,0,1557,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSRV",0,"discrete_state_set_real"},
		{"initial_state",14,0,1,0,1551,0,0.,0.,0.,0,"{Initial state} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSRV",0,"discrete_state_set_real"},
		{"num_set_values",13,0,2,0,1553,0,0.,0.,0.,0,"{Number of values for each variable} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSRV",0,"discrete_state_set_real"},
		{"set_values",14,0,3,1,1555,0,0.,0.,0.,0,"{Set values} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSRV"}
		},
	kw_211[4] = {
		{"betas",14,0,1,1,1399,0,0.,0.,0.,0,"{exponential uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Exponential",0,"exponential_uncertain"},
		{"descriptors",15,0,2,0,1401,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Exponential",0,"exponential_uncertain"},
		{"euv_betas",6,0,1,1,1398,0,0.,0.,0.,0,0,0,"exponential_uncertain"},
		{"euv_descriptors",7,0,2,0,1400,0,0.,0.,0.,0,0,0,"exponential_uncertain"}
		},
	kw_212[6] = {
		{"alphas",14,0,1,1,1433,0,0.,0.,0.,0,"{frechet uncertain alphas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Frechet",0,"frechet_uncertain"},
		{"betas",14,0,2,2,1435,0,0.,0.,0.,0,"{frechet uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Frechet",0,"frechet_uncertain"},
		{"descriptors",15,0,3,0,1437,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Frechet",0,"frechet_uncertain"},
		{"fuv_alphas",6,0,1,1,1432,0,0.,0.,0.,0,0,0,"frechet_uncertain"},
		{"fuv_betas",6,0,2,2,1434,0,0.,0.,0.,0,0,0,"frechet_uncertain"},
		{"fuv_descriptors",7,0,3,0,1436,0,0.,0.,0.,0,0,0,"frechet_uncertain"}
		},
	kw_213[6] = {
		{"alphas",14,0,1,1,1417,0,0.,0.,0.,0,"{gamma uncertain alphas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gamma",0,"gamma_uncertain"},
		{"betas",14,0,2,2,1419,0,0.,0.,0.,0,"{gamma uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gamma",0,"gamma_uncertain"},
		{"descriptors",15,0,3,0,1421,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gamma",0,"gamma_uncertain"},
		{"gauv_alphas",6,0,1,1,1416,0,0.,0.,0.,0,0,0,"gamma_uncertain"},
		{"gauv_betas",6,0,2,2,1418,0,0.,0.,0.,0,0,0,"gamma_uncertain"},
		{"gauv_descriptors",7,0,3,0,1420,0,0.,0.,0.,0,0,0,"gamma_uncertain"}
		},
	kw_214[2] = {
		{"descriptors",15,0,2,0,1485,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Geometric",0,"geometric_uncertain"},
		{"prob_per_trial",14,0,1,1,1483,0,0.,0.,0.,0,"{geometric uncertain prob_per_trial} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Geometric",0,"geometric_uncertain"}
		},
	kw_215[6] = {
		{"alphas",14,0,1,1,1425,0,0.,0.,0.,0,"{gumbel uncertain alphas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gumbel",0,"gumbel_uncertain"},
		{"betas",14,0,2,2,1427,0,0.,0.,0.,0,"{gumbel uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gumbel",0,"gumbel_uncertain"},
		{"descriptors",15,0,3,0,1429,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gumbel",0,"gumbel_uncertain"},
		{"guuv_alphas",6,0,1,1,1424,0,0.,0.,0.,0,0,0,"gumbel_uncertain"},
		{"guuv_betas",6,0,2,2,1426,0,0.,0.,0.,0,0,0,"gumbel_uncertain"},
		{"guuv_descriptors",7,0,3,0,1428,0,0.,0.,0.,0,0,0,"gumbel_uncertain"}
		},
	kw_216[10] = {
		{"abscissas",14,0,2,1,1451,0,0.,0.,0.,0,"{sets of abscissas for bin-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram"},
		{"counts",14,0,3,2,1455,0,0.,0.,0.,0,"{sets of counts for bin-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram"},
		{"descriptors",15,0,4,0,1457,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram",0,"histogram_bin_uncertain"},
		{"huv_bin_abscissas",6,0,2,1,1450},
		{"huv_bin_counts",6,0,3,2,1454},
		{"huv_bin_descriptors",7,0,4,0,1456,0,0.,0.,0.,0,0,0,"histogram_bin_uncertain"},
		{"huv_bin_ordinates",6,0,3,2,1452},
		{"huv_num_bin_pairs",5,0,1,0,1448,0,0.,0.,0.,0,0,0,"histogram_bin_uncertain"},
		{"num_pairs",13,0,1,0,1449,0,0.,0.,0.,0,"{key to apportionment among bin-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram",0,"histogram_bin_uncertain"},
		{"ordinates",14,0,3,2,1453,0,0.,0.,0.,0,"{sets of ordinates for bin-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram"}
		},
	kw_217[8] = {
		{"abscissas",14,0,2,1,1501,0,0.,0.,0.,0,"{sets of abscissas for point-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Point_Histogram"},
		{"counts",14,0,3,2,1503,0,0.,0.,0.,0,"{sets of counts for point-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Point_Histogram"},
		{"descriptors",15,0,4,0,1505,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Point_Histogram",0,"histogram_point_uncertain"},
		{"huv_num_point_pairs",5,0,1,0,1498,0,0.,0.,0.,0,0,0,"histogram_point_uncertain"},
		{"huv_point_abscissas",6,0,2,1,1500},
		{"huv_point_counts",6,0,3,2,1502},
		{"huv_point_descriptors",7,0,4,0,1504,0,0.,0.,0.,0,0,0,"histogram_point_uncertain"},
		{"num_pairs",13,0,1,0,1499,0,0.,0.,0.,0,"{key to apportionment among point-based histogram variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Point_Histogram",0,"histogram_point_uncertain"}
		},
	kw_218[4] = {
		{"descriptors",15,0,4,0,1495,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Hypergeometric",0,"hypergeometric_uncertain"},
		{"num_drawn",13,0,3,3,1493,0,0.,0.,0.,0,"{hypergeometric uncertain num_drawn } http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Hypergeometric",0,"hypergeometric_uncertain"},
		{"selected_population",13,0,2,2,1491,0,0.,0.,0.,0,"{hypergeometric uncertain selected_population} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Hypergeometric",0,"hypergeometric_uncertain"},
		{"total_population",13,0,1,1,1489,0,0.,0.,0.,0,"{hypergeometric uncertain total_population} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Hypergeometric",0,"hypergeometric_uncertain"}
		},
	kw_219[8] = {
		{"descriptors",15,0,4,0,1517,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCEUV_Interval",0,"interval_uncertain"},
		{"interval_bounds",14,0,3,2,1515,0,0.,0.,0.,0,"{bounds per interval} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCEUV_Interval"},
		{"interval_probs",14,0,2,1,1513,0,0.,0.,0.,0,"{basic probability assignments per interval} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCEUV_Interval"},
		{"iuv_descriptors",7,0,4,0,1516,0,0.,0.,0.,0,0,0,"interval_uncertain"},
		{"iuv_interval_bounds",6,0,3,2,1514},
		{"iuv_interval_probs",6,0,2,1,1512},
		{"iuv_num_intervals",5,0,1,0,1510,0,0.,0.,0.,0,0,0,"interval_uncertain"},
		{"num_intervals",13,0,1,0,1511,0,0.,0.,0.,0,"{number of intervals defined for each interval variable} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCEUV_Interval",0,"interval_uncertain"}
		},
	kw_220[2] = {
		{"lnuv_zetas",6,0,1,1,1356,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"zetas",14,0,1,1,1357,0,0.,0.,0.,0,"{lognormal uncertain zetas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"}
		},
	kw_221[4] = {
		{"error_factors",14,0,1,1,1363,0,0.,0.,0.,0,"[CHOOSE variance spec.]{lognormal uncertain error factors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"},
		{"lnuv_error_factors",6,0,1,1,1362,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lnuv_std_deviations",6,0,1,1,1360,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"std_deviations",14,0,1,1,1361,0,0.,0.,0.,0,"@{lognormal uncertain standard deviations} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"}
		},
	kw_222[10] = {
		{"descriptors",15,0,4,0,1369,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"},
		{"lambdas",14,2,1,1,1355,kw_220,0.,0.,0.,0,"[CHOOSE characterization]{lognormal uncertain lambdas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"},
		{"lnuv_descriptors",7,0,4,0,1368,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lnuv_lambdas",6,2,1,1,1354,kw_220,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lnuv_lower_bounds",6,0,2,0,1364,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lnuv_means",6,4,1,1,1358,kw_221,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lnuv_upper_bounds",6,0,3,0,1366,0,0.,0.,0.,0,0,0,"lognormal_uncertain"},
		{"lower_bounds",14,0,2,0,1365,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"},
		{"means",14,4,1,1,1359,kw_221,0.,0.,0.,0,"@{lognormal uncertain means} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"},
		{"upper_bounds",14,0,3,0,1367,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal",0,"lognormal_uncertain"}
		},
	kw_223[6] = {
		{"descriptors",15,0,3,0,1385,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Loguniform",0,"loguniform_uncertain"},
		{"lower_bounds",14,0,1,1,1381,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Loguniform",0,"loguniform_uncertain"},
		{"luuv_descriptors",7,0,3,0,1384,0,0.,0.,0.,0,0,0,"loguniform_uncertain"},
		{"luuv_lower_bounds",6,0,1,1,1380,0,0.,0.,0.,0,0,0,"loguniform_uncertain"},
		{"luuv_upper_bounds",6,0,2,2,1382,0,0.,0.,0.,0,0,0,"loguniform_uncertain"},
		{"upper_bounds",14,0,2,2,1383,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Loguniform",0,"loguniform_uncertain"}
		},
	kw_224[3] = {
		{"descriptors",15,0,3,0,1479,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Negative_Binomial",0,"negative_binomial_uncertain"},
		{"num_trials",13,0,2,2,1477,0,0.,0.,0.,0,"{negative binomial uncertain success num_trials} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Negative_Binomial",0,"negative_binomial_uncertain"},
		{"prob_per_trial",14,0,1,1,1475,0,0.,0.,0.,0,"{negative binomial uncertain success prob_per_trial} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Negative_Binomial",0,"negative_binomial_uncertain"}
		},
	kw_225[10] = {
		{"descriptors",15,0,5,0,1351,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal",0,"normal_uncertain"},
		{"lower_bounds",14,0,3,0,1347,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal",0,"normal_uncertain"},
		{"means",14,0,1,1,1343,0,0.,0.,0.,0,"{normal uncertain means} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal",0,"normal_uncertain"},
		{"nuv_descriptors",7,0,5,0,1350,0,0.,0.,0.,0,0,0,"normal_uncertain"},
		{"nuv_lower_bounds",6,0,3,0,1346,0,0.,0.,0.,0,0,0,"normal_uncertain"},
		{"nuv_means",6,0,1,1,1342,0,0.,0.,0.,0,0,0,"normal_uncertain"},
		{"nuv_std_deviations",6,0,2,2,1344,0,0.,0.,0.,0,0,0,"normal_uncertain"},
		{"nuv_upper_bounds",6,0,4,0,1348,0,0.,0.,0.,0,0,0,"normal_uncertain"},
		{"std_deviations",14,0,2,2,1345,0,0.,0.,0.,0,"{normal uncertain standard deviations} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal",0,"normal_uncertain"},
		{"upper_bounds",14,0,4,0,1349,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal",0,"normal_uncertain"}
		},
	kw_226[2] = {
		{"descriptors",15,0,2,0,1463,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Poisson",0,"poisson_uncertain"},
		{"lambdas",14,0,1,1,1461,0,0.,0.,0.,0,"{poisson uncertain lambdas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Poisson",0,"poisson_uncertain"}
		},
	kw_227[8] = {
		{"descriptors",15,0,4,0,1395,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Triangular",0,"triangular_uncertain"},
		{"lower_bounds",14,0,2,2,1391,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Triangular",0,"triangular_uncertain"},
		{"modes",14,0,1,1,1389,0,0.,0.,0.,0,"{triangular uncertain modes} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Triangular",0,"triangular_uncertain"},
		{"tuv_descriptors",7,0,4,0,1394,0,0.,0.,0.,0,0,0,"triangular_uncertain"},
		{"tuv_lower_bounds",6,0,2,2,1390,0,0.,0.,0.,0,0,0,"triangular_uncertain"},
		{"tuv_modes",6,0,1,1,1388,0,0.,0.,0.,0,0,0,"triangular_uncertain"},
		{"tuv_upper_bounds",6,0,3,3,1392,0,0.,0.,0.,0,0,0,"triangular_uncertain"},
		{"upper_bounds",14,0,3,3,1393,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Triangular",0,"triangular_uncertain"}
		},
	kw_228[6] = {
		{"descriptors",15,0,3,0,1377,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Uniform",0,"uniform_uncertain"},
		{"lower_bounds",14,0,1,1,1373,0,0.,0.,0.,0,"{Distribution lower bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Uniform",0,"uniform_uncertain"},
		{"upper_bounds",14,0,2,2,1375,0,0.,0.,0.,0,"{Distribution upper bounds} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Uniform",0,"uniform_uncertain"},
		{"uuv_descriptors",7,0,3,0,1376,0,0.,0.,0.,0,0,0,"uniform_uncertain"},
		{"uuv_lower_bounds",6,0,1,1,1372,0,0.,0.,0.,0,0,0,"uniform_uncertain"},
		{"uuv_upper_bounds",6,0,2,2,1374,0,0.,0.,0.,0,0,0,"uniform_uncertain"}
		},
	kw_229[6] = {
		{"alphas",14,0,1,1,1441,0,0.,0.,0.,0,"{weibull uncertain alphas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Weibull",0,"weibull_uncertain"},
		{"betas",14,0,2,2,1443,0,0.,0.,0.,0,"{weibull uncertain betas} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Weibull",0,"weibull_uncertain"},
		{"descriptors",15,0,3,0,1445,0,0.,0.,0.,0,"{Descriptors} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Weibull",0,"weibull_uncertain"},
		{"wuv_alphas",6,0,1,1,1440,0,0.,0.,0.,0,0,0,"weibull_uncertain"},
		{"wuv_betas",6,0,2,2,1442,0,0.,0.,0.,0,0,0,"weibull_uncertain"},
		{"wuv_descriptors",7,0,3,0,1444,0,0.,0.,0.,0,0,0,"weibull_uncertain"}
		},
	kw_230[29] = {
		{"beta_uncertain",0x19,10,12,0,1403,kw_201,0.,0.,0.,0,"{beta uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Beta","Continuous Aleatory Uncertain"},
		{"binomial_uncertain",0x19,3,19,0,1465,kw_202,0.,0.,0.,0,"{binomial uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Binomial","Discrete Aleatory Uncertain"},
		{"continuous_design",0x19,12,2,0,1297,kw_203,0.,0.,0.,0,"{Continuous design variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCDV","Design Variables"},
		{"continuous_state",0x19,8,26,0,1519,kw_204,0.,0.,0.,0,"{Continuous state variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCSV","State Variables"},
		{"discrete_design_range",0x19,8,3,0,1311,kw_205,0.,0.,0.,0,"{Discrete design range variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDRIV","Design Variables"},
		{"discrete_design_set_integer",0x19,4,4,0,1321,kw_206,0.,0.,0.,0,"{Discrete design set of integer variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSIV","Design Variables"},
		{"discrete_design_set_real",0x19,4,5,0,1331,kw_207,0.,0.,0.,0,"{Discrete design set of real variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDDSRV","Design Variables"},
		{"discrete_state_range",0x19,8,27,0,1529,kw_208,0.,0.,0.,0,"{Discrete state range variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSRIV","State Variables"},
		{"discrete_state_set_integer",0x19,4,28,0,1539,kw_209,0.,0.,0.,0,"{Discrete state set of integer variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSIV","State Variables"},
		{"discrete_state_set_real",0x19,4,29,0,1549,kw_210,0.,0.,0.,0,"{Discrete state set of real variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDSSRV","State Variables"},
		{"exponential_uncertain",0x19,4,11,0,1397,kw_211,0.,0.,0.,0,"{exponential uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Exponential","Continuous Aleatory Uncertain"},
		{"frechet_uncertain",0x19,6,15,0,1431,kw_212,0.,0.,0.,0,"{frechet uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Frechet","Continuous Aleatory Uncertain"},
		{"gamma_uncertain",0x19,6,13,0,1415,kw_213,0.,0.,0.,0,"{gamma uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gamma","Continuous Aleatory Uncertain"},
		{"geometric_uncertain",0x19,2,21,0,1481,kw_214,0.,0.,0.,0,"{geometric uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Geometric","Discrete Aleatory Uncertain"},
		{"gumbel_uncertain",0x19,6,14,0,1423,kw_215,0.,0.,0.,0,"{gumbel uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Gumbel","Continuous Aleatory Uncertain"},
		{"histogram_bin_uncertain",0x19,10,17,0,1447,kw_216,0.,0.,0.,0,"{histogram bin uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Bin_Histogram","Continuous Aleatory Uncertain"},
		{"histogram_point_uncertain",0x19,8,23,0,1497,kw_217,0.,0.,0.,0,"{histogram point uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Point_Histogram","Discrete Aleatory Uncertain"},
		{"hypergeometric_uncertain",0x19,4,22,0,1487,kw_218,0.,0.,0.,0,"{hypergeometric uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Hypergeometric","Discrete Aleatory Uncertain"},
		{"id_variables",11,0,1,0,1295,0,0.,0.,0.,0,"{Variables set identifier} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarSetId"},
		{"interval_uncertain",0x19,8,25,0,1509,kw_219,0.,0.,0.,0,"{interval uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCEUV_Interval","Epistemic Uncertain"},
		{"lognormal_uncertain",0x19,10,7,0,1353,kw_222,0.,0.,0.,0,"{lognormal uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Lognormal","Continuous Aleatory Uncertain"},
		{"loguniform_uncertain",0x19,6,9,0,1379,kw_223,0.,0.,0.,0,"{loguniform uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Loguniform","Continuous Aleatory Uncertain"},
		{"negative_binomial_uncertain",0x19,3,20,0,1473,kw_224,0.,0.,0.,0,"{negative binomial uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Negative_Binomial","Discrete Aleatory Uncertain"},
		{"normal_uncertain",0x19,10,6,0,1341,kw_225,0.,0.,0.,0,"{normal uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Normal","Continuous Aleatory Uncertain"},
		{"poisson_uncertain",0x19,2,18,0,1459,kw_226,0.,0.,0.,0,"{poisson uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarDAUV_Poisson","Discrete Aleatory Uncertain"},
		{"triangular_uncertain",0x19,8,10,0,1387,kw_227,0.,0.,0.,0,"{triangular uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Triangular","Continuous Aleatory Uncertain"},
		{"uncertain_correlation_matrix",14,0,24,0,1507,0,0.,0.,0.,0,"{correlations in aleatory uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarAUV_Correlations","Aleatory Uncertain Correlations"},
		{"uniform_uncertain",0x19,6,8,0,1371,kw_228,0.,0.,0.,0,"{uniform uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Uniform","Continuous Aleatory Uncertain"},
		{"weibull_uncertain",0x19,6,16,0,1439,kw_229,0.,0.,0.,0,"{weibull uncertain variables} http://dakota.sandia.gov/licensing/votd/html-ref/VarCommands.html#VarCAUV_Weibull","Continuous Aleatory Uncertain"}
		},
	kw_231[6] = {
		{"interface",0x308,10,5,5,1559,kw_9,0.,0.,0.,0,"{Interface} An interface specifies how function evaluations will be performed in order to map a set of parameters into a set of responses. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/InterfCommands.html"},
		{"method",0x308,75,2,2,59,kw_149,0.,0.,0.,0,"{Method} A method specifies the name and controls of an iterative procedure, e.g., a sensitivity analysis, uncertainty quantification, or optimization method. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/MethodCommands.html"},
		{"model",8,6,3,3,1121,kw_172,0.,0.,0.,0,"{Model} A model consists of a model type and maps specified variables through an interface to generate responses. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/ModelCommands.html"},
		{"responses",0x308,15,6,6,1653,kw_189,0.,0.,0.,0,"{Responses} A responses object specifies the data that can be returned to DAKOTA through the interface after the completion of a function evaluation. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/RespCommands.html"},
		{"strategy",0x108,10,1,1,1,kw_200,0.,0.,0.,0,"{Strategy} The strategy specifies the top level technique which will govern the management of iterators and models in the solution of the problem of interest. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/StratCommands.html"},
		{"variables",0x308,29,4,4,1293,kw_230,0.,0.,0.,0,"{Variables} A variables object specifies the parameter set to be iterated by a particular method. http://www.cs.sandia.gov/DAKOTA/licensing/votd/html-ref/VarCommands.html"}
		};

} // namespace Dakota

KeyWord Dakota_Keyword_Top = {"KeywordTop",0,6,0,0,Dakota::kw_231};
