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
open(path, WRITE_ONLY);
open(path, READ_ONLY);
open(path, READ_WRITE);
*/
static void open_new_file(const char *path, int oflag) {
    if (path && oflag != FILE_IO_NULL) {
        int opened_file = open(path, oflag);
        if (opened_file) {
            std::cout<<"File opened successfully" <<std::endl;
        } else if( opened_file == -1) {
            std::cout<<"Error opening file"<<std::endl;
        }
    }
}

static void open_file_with_fd(int fd, const char *path, int oflag) {
    if (fd && path && oflag != FILE_IO_NULL) {
        int open_with_fd = openat(fd, path, oflag);
        if(open_with_fd) {
            std::cout <<"File opened successfully"<<std::endl;
        } else if(open_with_fd == -1) {
            std::cout<<"Error opening file with descriptor"<<std::endl;
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

static off_t seek_file_to_offset(int fd, off_t offset, int whence) {
    off_t seek_pos;
    if(fd && offset != FILE_IO_NULL) {
        seek_pos = lseek(fd, offset, whence);
        if(seek_pos != -1) {
            return -1;
        } else {
            return seek_pos;
        }
    }
    return seek_pos;
}
