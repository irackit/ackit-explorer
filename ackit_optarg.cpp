
#include "include/ackit_optarg.h"

namespace ackit{

    ackit_optarg::ackit_optarg( std::string options ){
        this->options = options;
        opterr = 0;
        this->flags = 0;
    }

    int ackit_optarg::ackit_phrase( int argc, char** argv){
        int c{};
        while((c = getopt( argc,argv,this->options.c_str())) != -1){
            switch(c){
                case 'r':
                    ackit_ackitflags(this->flags, ACKIT_REC);
                break;
                case 'l':
                    this->logfile = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_LOG );
                break;
                case 'f':
                    this->fileformat = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_FORMAT);
                break;
                case 'd':
                    this->sdeletepath = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_SDEL);
                break;
                case 'e':
                    this->gpgpath = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_EEACH);
                break;
                case 'E':
                    this->gpgpath = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_EALL);
                break;
                case 'L':
                    this->copypath = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_CLOC);
                break;
                case 'u':
                    this->unlink = (int)optarg;
                    ackit_ackitflags(this->flags, ACKIT_UFILE);
                break;
                case 'U':
                    this->unlink = (int)optarg;
                    ackit_ackitflags(this->flags, ACKIT_UAFILE);
                break;
                case 'p':
                    this->pathphrase = (std::string)optarg;
                    ackit_ackitflags(this->flags, ACKIT_PPHRASE);
                break;
                case 'h':
                    std::cout<<"ackitree.exe"<<std::right<<std::endl;
                    std::cout<<std::setw(10)<<"-l <logfile.txt>"<<std::endl;
                    std::cout<<std::setw(10)<<std::left<<"-f search for file format type"<<std::endl;
                break;
                case '?':
                    if(optopt == 'l'){
                        std::cout<<"option "<<(char)optopt<<" requires log filename argument"<<std::endl;
                    }
                    else if(optopt == 'f'){
                        std::cout<<"option "<<(char)optopt<<" requires file format"<<std::endl;
                    }
                    else if(optopt == 'd'){
                        std::cout<<"option "<<(char)optopt<<" requires path to sdelete"<<std::endl;
                    }
                    else if(optopt == 'e'){
                        std::cout<<"option "<<(char)optopt<<" requires path to gpg"<<std::endl;
                    }
                    else if(optopt == 'E'){
                        std::cout<<"option "<<(char)optopt<<" requires e set to gpg path and -L for encrypted location"<<std::endl;
                    }
                    else if(optopt == 'L'){
                        std::cout<<"option "<<(char)optopt<<" requires file copy location"<<std::endl;
                    }
                    else if(optopt == 'p'){
                        std::cout<<"option "<<(char)optopt<<" requires a passphrase for encryption"<<std::endl;
                    }
                    else if(optopt == 'u'){
                        std::cout<<"option "<<(char)optopt<<" requires 1: unlink found files, 2:unlink after encryption"<<std::endl;
                    }
                    else{
                        std::cout<<"unknown operation"<<std::endl;
                    }
                break;
                default:
                    return 'unknown operation, try -h';
                    return 1;
            }   
        }
    }

}
