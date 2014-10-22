/*  _______________________________________________________________________

    DAKOTA: Design Analysis Kit for Optimization and Terascale Applications
    Copyright 2014 Sandia Corporation.
    This software is distributed under the GNU Lesser General Public License.
    For more information, see the README file in the top Dakota directory.
    _______________________________________________________________________ */

//- Class:        global_defs
//- Description:  Global object initializations and global function
//-               implementations
//- Owner:        Mike Eldred

#include <boost/system/system_error.hpp>
#include "dakota_global_defs.hpp"
#include "ParamResponsePair.hpp"
#include "PRPMultiIndex.hpp"
#include "DakotaGraphics.hpp"
#include "DakotaInterface.hpp"
#include "ParallelLibrary.hpp"
#include "ProblemDescDB.hpp"
#include "ResultsManager.hpp"

// Toggle for MPI debug hold
#define MPI_DEBUG

#if defined(MPI_DEBUG) && defined(MPICH2)
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#endif 


static const char rcsId[]="@(#) $Id: dakota_global_defs.cpp 6716 2010-04-03 18:35:08Z wjbohnh $";


namespace Dakota {

// --------------------------
// Instantiate global objects
// --------------------------

/// by default Dakota exits or calls MPI_Abort on errors
short abort_mode = ABORT_EXITS; 

std::ostream* dakota_cout = &std::cout; ///< DAKOTA stdout initially points to
  ///< std::cout, but may be redirected to a tagged ofstream if there are
  ///< concurrent iterators.
std::ostream* dakota_cerr = &std::cerr; ///< DAKOTA stderr initially points to
  ///< std::cerr, but may be redirected to a tagged ofstream if there are
  ///< concurrent iterators.
PRPCache data_pairs;          ///< contains all parameter/response pairs.

/// Global results database for iterator results
ResultsManager iterator_results_db;


int write_precision = 10;     ///< used in ostream data output functions
                              ///< (restart_util.cpp overrides default value)

MPIManager      dummy_mpi_mgr; ///< dummy MPIManager for ref initialization
ProgramOptions  dummy_prg_opt; ///< dummy ProgramOptions for ref initialization
OutputManager   dummy_out_mgr; ///< dummy OutputManager for ref initialization
ParallelLibrary dummy_lib;     ///< dummy ParallelLibrary for ref initialization
ProblemDescDB   dummy_db;      ///< dummy ProblemDescDB for ref initialization

#ifdef DAKOTA_MODELCENTER
int mc_ptr_int = 0;           ///< global pointer for ModelCenter API
int dc_ptr_int = 0;           ///< global pointer for ModelCenter eval DB
#endif // DAKOTA_MODELCENTER

ProblemDescDB *Dak_pddb;      ///< set by ProblemDescDB, for use in parsing


// -----------------------
// Define global functions
// -----------------------
void abort_handler(int code)
{
  // WEH - uncomment this code if you want signals to generate a corefile.
  //       This is handy for debugging infinite loops ... which can be
  //       difficult to debug within GDB.
  //abort();

  // BMA TODO: do we want to maintain this?
  if (code > 1) // code = 2 (Cntl-C signal), 0 (normal), & -1/1 (abnormal)
    Cout << "Signal Caught!" << std::endl;

  // Clean up
  Cout << std::flush; // flush cout or ofstream redirection
  Cerr << std::flush; // flush cerr or ofstream redirection

  if (Dak_pddb) {
    // cleanup parameters/results files
    InterfaceList &ifaces = Dak_pddb->interface_list();
    for (InterfaceList::iterator It = ifaces.begin(); It != ifaces.end(); ++It)
      It->file_cleanup(); // virtual fn defined for ProcessApplicInterface
    // properly terminate in parallel
    Dak_pddb->parallel_library().abort_helper(code);
  }
  else {
    abort_throw_or_exit(code);
  }
}


void abort_throw_or_exit(int code)
{
  if (abort_mode == ABORT_THROWS) {
    // throw a Boost exception that inherits from std::runtime_error, but
    // embeds the error code (since system_error is C++11 and newer)
    boost::system::error_code ecode(code, boost::system::generic_category());
    throw(boost::system::system_error(ecode, "Dakota aborted"));
  }
  else
    std::exit(code);  // or std::exit(EXIT_FAILURE) from /usr/include/stdlib.h
}


/// Tie various signal handlers to Dakota's abort_handler function
void register_signal_handlers()
{
#if defined(__MINGW32__) || defined(_MSC_VER)
  std::signal(SIGBREAK, Dakota::abort_handler);
#else
  std::signal(SIGKILL, Dakota::abort_handler);
#endif
  std::signal(SIGTERM, Dakota::abort_handler);
  std::signal(SIGINT,  Dakota::abort_handler);
}


/** See details in code for details, depending on MPI implementation in use. */
void mpi_debug_hold() {

#ifdef MPI_DEBUG
  // hold parallel job prior to MPI_Init() in order to attach debugger to
  // master process.  Then step past ParallelLibrary instantiation and attach
  // debugger to other processes.
#ifdef MPICH2
  // To use this approach, set $DAKOTA_DEBUGPIPE to a suitable name,
  // and create $DAKOTA_DEBUGPIPE by executing "mkfifo $DAKOTA_DEBUGPIPE".
  // After invoking "mpirun ... dakota ...", find the processes, invoke
  // a debugger on them, set breakpoints, and execute "echo >$DAKOTA_DEBUGPIPE"
  // to write something to $DAKOTA_DEBUGPIPE, thus releasing dakota from
  // a wait at the open invocation below.
  char *pname; int dfd;
  if ( ( pname = getenv("DAKOTA_DEBUGPIPE") ) &&
       ( dfd = open(pname,O_RDONLY) ) > 0 ) {
    char buf[80];
    read(dfd,buf,sizeof(buf));
    close(dfd);
  }
#else
  // This simple scheme has been observed to fail with MPICH2
  int test;
  std::cin >> test;
#endif // MPICH2
#endif // MPI_DEBUG

}


} // namespace Dakota
