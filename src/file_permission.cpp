#include "../include/file_io.h"

static void check_file_permission_type(char file_perm) {
    switch (file_perm)
    {
    case FILE_IO_PERM_READ_ONLY:
        std::cout <<"READ_ONLY"<<std::endl;
        break;
    case FILE_IO_PERM_WRITE_ONLY:
        std::cout <<"WRITE_ONLY"<<std::endl;
        break;
    case FILE_IO_PERM_READ_WRITE:
        std::cout <<"READ_WRITE"<<std::endl;
        break;
    case FILE_IO_PERM_CREATE_ONLY:
        std::cout <<"CREATE_ONLY"<<std::endl;
        break;
    default:
        std::cout <<"Unknown file permission type"<<std::endl;
        break;
    }
}

static void check_file_descriptor(char fd) {
    switch (fd)
    {
    case FILE_IO_PERM_READ_ONLY:
        std::cout<<"READ_ONLY File Descriptor: "<<FILE_IO_PERM_READ_ONLY<<std::endl;
        break;
    case FILE_IO_PERM_WRITE_ONLY:
        std::cout<<"WRITE_ONLY File Descriptor: "<<FILE_IO_PERM_WRITE_ONLY<<std::endl;
        break;
    case FILE_IO_PERM_READ_WRITE:
        std::cout<<"READ_WRITE File Descriptor: "<<FILE_IO_PERM_READ_WRITE<<std::endl;
        break;
    case FILE_IO_PERM_CREATE_ONLY:
        std::cout<<"CREATE_ONLY File Descriptor: "<<FILE_IO_PERM_CREATE_ONLY<<std::endl;
        break;
    default:
        std::cout <<"Unknown file descriptor"<<std::endl;
        break;
    }
}
