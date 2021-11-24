//ackit www.returnonerror.com

#ifndef _ackit_optarg
#define _ackit_optarg

#include <unistd.h>
#include <string>
#include <getopt.h>

extern int opterr;

namespace ackit{

    #define ACKIT_LOG       0b0000000000000001 //
    #define ACKIT_FORMAT    0b0000000000000010 //
    #define ACKIT_DELPATH   0b0000000000000100 //
    #define ACKIT_GPGPATH   0b0000000000001000 //
    #define ACKIT_COPYPATH  0b0000000000010000 //
    #define ACKIT_PPHRASE   0b0000000000100000 //
    #define ACKIT_REC       0b0000000001000000 //
    #define ACKIT_SDEL      0b0000000010000000 //
    #define ACKIT_EEACH     0b0000000100000000 //
    #define ACKIT_EALL      0b0000001000000000 //
    #define ACKIT_CLOC      0b0000010000000000 //
    #define ACKIT_UFILE     0b0000100000000000 //
    #define ACKIT_UAFILE    0b0001000000000000 //

    #define ackit_ackitflags(a, b) a |= b

    class ackit_optarg{
        public:
            ackit_optarg( std::string = "-rl:f:d:e:E:L:u:U:p:h");
            int ackit_phrase( int, char**);
        private:
            std::string options,logfile,fileformat,sdeletepath,gpgpath,copypath,pathphrase,unlink;
            unsigned short flags;
    };
}

#endif /* _ackit_optarg */
