#include "include/ackit_optarg.h"


int main(int argc, char** argv){
    ackit::ackit_optarg *oarg = new ackit::ackit_optarg();
    oarg->ackit_phrase(argc,argv);
    delete oarg;
    return 0;
}
