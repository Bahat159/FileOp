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

/* 
Example usage of oflag
open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
*/
static void open_new_file(const char *path, int oflag, ...) {
    if (path && oflag != NULL) {
        int opened_file = open(path, oflag, ...);
        if (opened_file) {
            std::cout<<"File opened successfully" <<std::end;
        } else if( opened_file == -1) {
            std::cout<<"Error opening file"<<std::endl;
        }
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
