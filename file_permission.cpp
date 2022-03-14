#include "file_io.h"

static void check_file_permission_type(char file_perm) {
    switch (file_perm)
    {
    case READ_ONLY:
        std::cout <<"READ_ONLY"<<std::endl;
        break;
    
    default:
        std::cout <<"Unknown file permission type"<<std::endl;
        break;
    }
}
