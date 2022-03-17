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


static int get_file_access_faccesssat(int fd, const char *pathname, int mode, int flag) {
    int access_faccesssat;
    if (fd && pathname && mode && flag != FILE_IO_E_NULL) {
        access_faccesssat = faccessat(fd, pathname, mode, flag);
        if (access_faccesssat == FILE_IO_E_ERROR) {
            return access_faccesssat;
        } else if (access_faccesssat == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return access_faccesssat;
}

static int change_file_access_permission_mode (const char *pathname, mode_t mode) {
    int change_chmod;
    if (pathname && mode != FILE_IO_E_NULL) {
        change_chmod = chmod(pathname, mode);
        if(change_chmod == FILE_IO_E_NULL) {
            return change_chmod;
        } else if (change_chmod == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return change_chmod;
}


static int change_open_file_access_permission_mode(int fd, mode_t mode) {
    int change_fchmod;
    if(fd && mode != FILE_IO_E_NULL) {
        change_fchmod = fchmod(fd, mode);
        if (change_fchmod == FILE_IO_E_NULL) {
            return change_fchmod;
        } else if (change_fchmod == FILE_IO_E_ERROR) {
            return FILE_IO_E_ERROR;
        }
    }
    return change_fchmod;
}
