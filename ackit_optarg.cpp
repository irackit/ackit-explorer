
#include "include/ackit_optarg.h"

namespace ackit{

    ackit_optarg::ackit_optarg( std::string options ){
        this->options = options;
        opterr = 0;
        this->flags = 0;
    }

    int ackit_optarg::ackit_phrase( int argc, char** argv){
        int c{};
        if( argc <= 1){
            std::cout<<"see -h for options"<<std::endl;
            return 0;
        }
        while((c = getopt( argc,argv,this->options.c_str())) != -1){
            switch(c){
                case 'r':
                    ackit_ackitflags(this->flags, ACKIT_REC);
                break;
                case 'l':
                    this->logfile = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_LOG );
                break;
                case 'f':
                    this->fileformat = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_FORMAT);
                break;
                case 'd':
                    this->sdeletepath = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_SDEL);
                break;
                case 'e':
                    this->gpgpath = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_EEACH);
                break;
                case 'E':
                    this->gpgpath = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_EALL);
                break;
                case 'L':
                    this->copypath = static_cast<std::string>(optarg);
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
                    this->path = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags,ACKIT_PATH);
                case 'P':
                    this->pathphrase = static_cast<std::string>(optarg);
                    ackit_ackitflags(this->flags, ACKIT_PPHRASE);
                break;
                case 'h':
                    std::cout<<"\nackitree\n"
                        "\t-p path to search.\n" 
                        "\t-r recrusive directory search\n"
                        "\t-l name,location of log file\n"
                        "\t-f search for file format, etc *.txt\n"
                        "\t-d path to sdelete, download from sysinternals\n"
                        "\t-e path to gpg encryption program GnuGP\n"
                        "\t-E encrypt all files in provided path. Must provide -L\n"
                        "\t-L path to save encrypted file\n"
                        "\t-u unlink files found during search path\n"
                        "\t-U unlink files after encryption\n"
                        "\t-p passphrase for encryption"
                    <<std::endl;
                break;
                case '?':
                    if(optopt == 'l'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires log filename argument"<<std::endl;
                    }
                    else if(optopt == 'f'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires file format"<<std::endl;
                    }
                    else if(optopt == 'd'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires path to sdelete"<<std::endl;
                    }
                    else if(optopt == 'e'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires path to gpg"<<std::endl;
                    }
                    else if(optopt == 'E'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires e set to gpg path and -L for encrypted location"<<std::endl;
                    }
                    else if(optopt == 'L'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires file copy location"<<std::endl;
                    }
                    else if(optopt == 'P'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires a passphrase for encryption"<<std::endl;
                    }
                    else if(optopt == 'p'){
                        std::cout<<"option "<<static_cast<char>(optopt)<<" requires a path etc /path/to/file"<<std::endl;
                    }
                    else if(optopt == 'u' || optopt == 'U'){}
                    else{
                        std::cout<<"unknown operation: -"<<static_cast<char>(optopt)<<", -h for help"<<std::endl;
                    }
                break;
                    std::cout<<"did you mean -h?"<<std::endl;
                break;
                default:
                    std::cout<<"unknown operation, try -h"<<std::endl;
                    return 0;
            } 
        }
        return 1;
    }

}
