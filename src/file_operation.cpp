#include "../include/file_io.h"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

static int create_new_file(const char *path, mode_t mode) {
    /* 
    TODO
    Check if file already exist
    */
    int file_to_create = creat(path,mode);
    if (file_to_create != FILE_IO_E_ERROR) {
        std::cout<<"["<<path<<"] created successfully with file mode: "<<mode<<std::endl;
    } else if (file_to_create == FILE_IO_E_ERROR) {
        return FILE_IO_E_ERROR;
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
    if (path && oflag != FILE_IO_E_NULL) {
        opened_file = open(path, oflag);
        if (opened_file) {
            std::cout<<"File opened successfully" <<std::endl;
            return opened_file;
        } else if( opened_file == FILE_IO_E_ERROR) {
            std::cout<<"Error opening file"<<std::endl;
            return FILE_IO_E_ERROR;
        }
    }
    return opened_file;
}

static int open_file_with_fd(int fd, const char *path, int oflag) {
    int open_with_fd;
    if (fd && path && oflag != FILE_IO_E_NULL) {
        open_with_fd = openat(fd, path, oflag);
        if(open_with_fd) {
            std::cout <<"File opened successfully"<<std::endl;
            return open_with_fd;
        } else if(open_with_fd == FILE_IO_E_ERROR) {
            std::cout<<"Error opening file with descriptor"<<std::endl;
            return FILE_IO_E_ERROR;
        }
    }
    return open_with_fd;
}

static int close_opened_file(int fd) {
    int closed_fd = close(fd);
    if(closed_fd == FILE_IO_E_NULL) {
        return FILE_IO_E_NULL;
    } else {
        return FILE_IO_E_ERROR;
    }
}

static off_t seek_file_to_offset(int fd, off_t offset, int whence) {
    off_t seek_pos;
    if(fd && offset != FILE_IO_E_NULL) {
        seek_pos = lseek(fd, offset, whence);
        if(seek_pos != FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        } else {
            return seek_pos;
        }
    }
    return seek_pos;
}

static ssize_t read_from_file(int fd, void *buf, size_t nbytes) {
    ssize_t bytes_read;
    if(fd && buf && nbytes != FILE_IO_E_NULL){
        bytes_read = read(fd, buf,  nbytes);
        if (bytes_read > FILE_IO_E_NULL) {
            return bytes_read;
        } else if (bytes_read == FILE_IO_E_NULL) {
            return EOF;
        } else if( bytes_read == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return bytes_read;
}

static ssize_t write_to_file(int fd, const void *buf, size_t nbytes) {
    ssize_t bytes_written;
    if(fd && buf && nbytes != FILE_IO_E_NULL) {
        bytes_written = write(fd, buf, nbytes);
        if (bytes_written > FILE_IO_E_NULL) {
            return bytes_written;
        } else if (bytes_written == FILE_IO_E_NULL) {
            return FILE_IO_E_ERROR;
        } else if (bytes_written == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return bytes_written;
}


/* 
    Multiple process
    to seek and perform I/O atomically: pread and pwrite.
*/

static ssize_t pread_with_multiple_process(int fd, void *buf, size_t nbytes, off_t offset) {
    ssize_t pread_to_multiple_process;
    if(fd && buf && nbytes && offset != FILE_IO_E_NULL) {
        pread_to_multiple_process =  pread(fd, buf, nbytes, offset);
        if(pread_to_multiple_process > FILE_IO_E_NULL) {
            return pread_to_multiple_process;
        } else if (pread_to_multiple_process == FILE_IO_E_NULL) {
            return FILE_IO_E_EOF;
        } else if( pread_to_multiple_process == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return pread_to_multiple_process;
}

static ssize_t pwrite_with_multiple_process(int fd, const void *buf, size_t nbytes, off_t offset) {
    ssize_t pwrite_to_multiple_process;
    if(fd && buf && nbytes && offset != FILE_IO_E_NULL) {
        pwrite_to_multiple_process = pwrite(fd, buf, nbytes, offset);
        if(pwrite_to_multiple_process > FILE_IO_E_NULL) {
            return pwrite_to_multiple_process;
        } else if (pwrite_to_multiple_process == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return pwrite_to_multiple_process;
}
