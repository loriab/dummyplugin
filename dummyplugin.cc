#include <libplugin/plugin.h>
#include <psi4-dec.h>
#include <libparallel/parallel.h>
#include <liboptions/liboptions.h>
#include <libmints/mints.h>
#include <libpsio/psio.hpp>

INIT_PLUGIN

using namespace boost;

namespace psi{ namespace dummyplugin {

extern "C" 
int read_options(std::string name, Options& options)
{
    if (name == "DUMMYPLUGIN"|| options.read_globals()) {
        /*- The amount of information printed to the output file -*/
        options.add_int("PRINT", 1);
    }

    return true;
}

extern "C" 
PsiReturnType dummyplugin(Options& options)
{
    int print = options.get_int("PRINT");

    /* Your code goes here */

    return Success;
}

}} // End namespaces

