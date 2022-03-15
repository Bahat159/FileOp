#include "../include/file_io.h"


static int create_new_file(const char *path, mode_t mode) {
    /* 
    TODO
    Check if file already exist
    */
    int file_to_create = creat(path,mode);
    if (file_to_create != FILE_IO_ERROR) {
        std::cout<<"["<<path<<"] created successfully with: "<<mode<<" Descriptor"<<std::endl;
    } else {
        std::cout<<"Error creating filename: "<<path<<std::endl;
        return file_to_create;
    }
    return file_to_create;
}

/* 
Example usage of oflag
open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
open(path, WRITE_ONLY);
open(path, READ_ONLY);
open(path, READ_WRITE);
*/
static int open_new_file(const char *path, int oflag) {
    int opened_file;
    if (path && oflag != FILE_IO_NULL) {
        opened_file = open(path, oflag);
        if (opened_file) {
            std::cout<<"File opened successfully" <<std::endl;
            return opened_file;
        } else if( opened_file == FILE_IO_ERROR) {
            std::cout<<"Error opening file"<<std::endl;
            return -1;
        }
    }
    return opened_file;
}

static int open_file_with_fd(int fd, const char *path, int oflag) {
    int open_with_fd;
    if (fd && path && oflag != FILE_IO_NULL) {
        open_with_fd = openat(fd, path, oflag);
        if(open_with_fd) {
            std::cout <<"File opened successfully"<<std::endl;
            return open_with_fd;
        } else if(open_with_fd == FILE_IO_ERROR) {
            std::cout<<"Error opening file with descriptor"<<std::endl;
            return -1;
        }
    }
    return open_with_fd;
}

static int close_opened_file(int fd) {
    int closed_fd = close(fd);
    if(closed_fd == FILE_IO_NULL) {
        return 0;
    } else {
        return -1;
    }
}

static off_t seek_file_to_offset(int fd, off_t offset, int whence) {
    off_t seek_pos;
    if(fd && offset != FILE_IO_NULL) {
        seek_pos = lseek(fd, offset, whence);
        if(seek_pos != FILE_IO_ERROR) {
            return -1;
        } else {
            return seek_pos;
        }
    }
    return seek_pos;
}

static ssize_t read_from_file(int fd, void *buf, size_t nbytes) {
    ssize_t bytes_read;
    if(fd && buf && nbytes != FILE_IO_NULL){
        bytes_read = read(fd, buf,  nbytes);
        if (bytes_read > 0) {
            return bytes_read;
        } else if (bytes_read == FILE_IO_NULL) {
            return EOF;
        } else if( bytes_read == FILE_IO_ERROR) {
            return -1;
        }
    }
    return bytes_read;
}
