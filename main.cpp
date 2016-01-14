#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <sys/time.h>
#include "mcf.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
// launching point;
//
////////////////////////////////////////////////////////////////////////////////

int main( int argc, char **argv)
{
    struct timeval tv_start, tv_end;
    gettimeofday( &tv_start, (struct timezone*) NULL);


    // (1) run MCF solver;
    MCF mcf;
    // here you should build your network either by reading it from a
    // file (network examples are in /tests) or by populating the
    // mcf object directly from the host application (the one inside
    // which you plan to call MCF solver possibly multiple times);
    mcf.parse_options( argc, argv);
    mcf.build_network_from_file();
    //mcf.build_network_from_host_application();
    mcf.run_mcf_solver();


    // (2) entertain user;
    printf("\n\nFINAL RESULT:");
    if ( mcf.problem_type() == MCMCF_TYPE) {
        printf("\nFinal latency L=%lf", mcf.get_L());
    }
    mcf.print_network_demands( true); // print_only_edges;
    // Note: rounding is not required; you may want or not to use this 
    // in your application; in my case I do it so that one commodity
    // is shipped only via one path (in the context of NoCs I want to 
    // avoid packet (re)ordering at destinations); be aware: randomization
    // "damages" optimality and may violate capacities;
    mcf.do_randomized_rounding();
    mcf.print_routing_paths();


    // (3) clean up
    mcf.free_topology();

    gettimeofday( &tv_end, (struct timezone*) NULL);        
    printf("\nRuntime: %ld sec \n", tv_end.tv_sec - tv_start.tv_sec);

    return 1;
}
