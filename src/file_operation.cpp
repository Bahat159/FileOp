#include <iostream>
#include "file_io.h"


static void create_new_file(const char *path, mode_t mode) {
    /* 
    TODO
    Check if file already exist
    */
    int file_to_create = creat(path,mode);
    if (file_to_create != -1) {
        std::cout<<"["<<path<<"] created successfully with: "<<mode<<" Descriptor"<<std::endl;
    } else {
        std::cout<<"Error creating filename: "<<path<<std::endl;
    }
}

static int close_opened_file(int fd) {
    int closed_fd = close(fd);
    if(closed_fd == 0) {
        return 0;
    } else {
        return -1;
    }
}
