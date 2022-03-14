#include "file_io.h"

static void check_file_permission_type(char file_perm) {
    switch (file_perm)
    {
    case READ_ONLY:
        std::cout <<"READ_ONLY"<<std::endl;
        break;
    case WRITE_ONLY:
        std::cout <<"WRITE_ONLY"<<std::endl;
        break;
    case READ_WRITE:
        std::cout <<"READ_WRITE"<<std::endl;
        break;
    case CREATE_ONLY:
        std::cout <<"CREATE_ONLY"<<std::endl;
        break;
    default:
        std::cout <<"Unknown file permission type"<<std::endl;
        break;
    }
}

static void check_file_descriptor(char file_perm) {
    if (file_perm == O_RDONLY){
        std::cout<<"O_RDONLY File Descriptor: "<<READ_ONLY<<std::endl;
    }
}
