#include "../include/file_io.h"


/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

static int get_file_stat(const char *pathname, struct stat *buf) {
    int get_stat;
    if (pathname && buf != FILE_IO_DIR_NULL) {
        get_stat = stat(pathname, buf);
        if( get_stat == FILE_IO_DIR_NULL) {
            return get_stat;
        } else {
            return FILE_IO_E_ERROR;
        }
    }
    return get_stat;
}

static int get_file_fstat(int fd, struct stat *buf) {
    int get_fstat;
    if(fd && buf != FILE_IO_DIR_NULL) {
        get_fstat = fstat(fd, buf);
        if(get_fstat == FILE_IO_DIR_NULL) {
            return get_fstat;
        } else {
            return FILE_IO_E_ERROR;
        }
    }
    return get_fstat;
}

static int get_symbolic_link_file_stat(const char *pathname, struct stat *buf) {
    int get_lstat;
    if(pathname && buf != FILE_IO_DIR_NULL) {
        get_lstat = lstat(pathname, buf);
        if(get_lstat == FILE_IO_DIR_NULL) {
            return get_lstat;
        } else {
            return FILE_IO_E_ERROR;
        }
    }
    return get_lstat;
}


static int get_file_statistic_fstatat(int fd, const char *pathname, struct stat *buf, int flag){
    return 0;
}

static int set_file_access_mode(const char *pathname, int mode) {
    int access_mode;
    if(pathname && mode != FILE_IO_E_NULL) {
        access_mode = access(pathname, mode);
        if( access_mode == FILE_IO_E_NULL) {
            return access_mode;
        } else if(access_mode == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return access_mode;
}
