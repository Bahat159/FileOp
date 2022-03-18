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
            return FILE_IO_DIR_ERROR;
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
            return FILE_IO_DIR_ERROR;
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
            return FILE_IO_DIR_ERROR;
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
        if( access_mode == FILE_IO_DIR_NULL) {
            return access_mode;
        } else if(access_mode == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return access_mode;
}


static int get_file_access_mode(int fd, const char *pathname, int mode, int flag) {
    int access_faccesssat;
    if (fd && pathname && mode && flag != FILE_IO_E_NULL) {
        access_faccesssat = faccessat(fd, pathname, mode, flag);
        if (access_faccesssat == FILE_IO_DIR_NULL) {
            return access_faccesssat;
        } else if (access_faccesssat == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return access_faccesssat;
}

static int change_file_access_permission_mode (const char *pathname, mode_t mode) {
    int change_chmod;
    if (pathname && mode != FILE_IO_E_NULL) {
        change_chmod = chmod(pathname, mode);
        if(change_chmod == FILE_IO_DIR_NULL) {
            return change_chmod;
        } else if (change_chmod == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_chmod;
}


static int change_open_file_access_permission_mode(int fd, mode_t mode) {
    int change_fchmod;
    if(fd && mode != FILE_IO_E_NULL) {
        change_fchmod = fchmod(fd, mode);
        if (change_fchmod == FILE_IO_DIR_NULL) {
            return change_fchmod;
        } else if (change_fchmod == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_fchmod;
}

static int change_file_user_group_id(const char *pathname, uid_t owner, gid_t group) {
    int change_file_user_group_id;
    if (pathname && owner && group != FILE_IO_E_NULL) {
        change_file_user_group_id = chown(pathname, owner, group);
        if(change_file_user_group_id == FILE_IO_DIR_NULL) {
            return change_file_user_group_id;
        } else if (change_file_user_group_id == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_file_user_group_id;
}

static int change_opened_file_user_group_id(int fd, uid_t owner, gid_t group) {
    int change_open_file_usr_grp_id;
    if(fd && owner &&group != FILE_IO_E_NULL){
        change_open_file_usr_grp_id = fchown(fd, owner, group);
        if (change_open_file_usr_grp_id == FILE_IO_DIR_NULL) {
            return change_open_file_usr_grp_id;
        } else if (change_open_file_usr_grp_id == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_open_file_usr_grp_id;
}


static int change_open_file_sym_user_group_id(int fd, const char *pathname, uid_t owner, gid_t group, int flag) {
    int change_sym_link_file_id;
    if(flag && fd != FILE_IO_DIR_NULL) {
        change_sym_link_file_id = fchownat(fd, pathname, owner, group, flag);
        if(change_sym_link_file_id == FILE_IO_DIR_NULL) {
            return change_sym_link_file_id;
        } else if (change_sym_link_file_id == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_sym_link_file_id;
}

static int change_file_sym_user_group_id_lchown(const char *pathname, uid_t owner, gid_t group) {
    int change_sym_link;
    if (pathname && owner && group != FILE_IO_DIR_NULL) {
        change_sym_link = lchown(pathname, owner, group);
        if(change_sym_link == FILE_IO_DIR_NULL) {
            return change_sym_link;
        } else if (change_sym_link == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return change_sym_link;
}


static int truncate_file_data(const char *pathname, off_t length) {
    int truncate_data;
    if(pathname && length != FILE_IO_DIR_NULL) {
        truncate_data = truncate(pathname, length);
        if (truncate_data == FILE_IO_DIR_NULL) {
            return truncate_data;
        } else if (truncate_data == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return truncate_data;
}

static int truncate_open_file_data(int fd, off_t length) {
    int truncate_open_data;
    if(fd && length != FILE_IO_DIR_NULL) {
        truncate_open_data = ftruncate(fd, length);
        if (truncate_open_data == FILE_IO_DIR_NULL) {
            return truncate_open_data;
        } else if (truncate_open_data == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return truncate_open_data;
}


static int link_to_existing_file(const char *existing_file_path, const char *new_file_path) {
    int link_new_file;
    if (existing_file_path && new_file_path != FILE_IO_DIR_NULL) {
        link_new_file = link(existing_file_path, new_file_path);
        if (link_new_file == FILE_IO_DIR_NULL) {
            return link_new_file;
        } else if (link_new_file == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return link_new_file;
}


static int link_to_existing_opened_file(int efd, const char *existing_file_path, int nfd, const char *new_file_path, int flag) {
    int link_opened_file;
    if (efd && flag && nfd != FILE_IO_DIR_NULL) {
        link_opened_file = linkat(efd, existing_file_path, nfd, new_file_path, flag);
        if (link_opened_file == FILE_IO_DIR_NULL) {
            return link_opened_file;
        } else if (link_opened_file == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return link_opened_file;
}

static int unlink_file_path(const char *pathname) {
    int unlink_file;
    if (pathname != FILE_IO_DIR_NULL) {
        unlink_file = unlink(pathname);
        if (unlink_file == FILE_IO_DIR_NULL) {
            return unlink_file;
        } else if (unlink_file == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return unlink_file;
}

static int unlink_sym_file_path(int fd, const char *pathname, int flag) {
    int unlink_sym_file;
    if (fd && flag != FILE_IO_DIR_ERROR) {
        unlink_sym_file = unlinkat(fd, pathname, flag);
        if (unlink_sym_file == FILE_IO_DIR_NULL) {
            return unlink_sym_file;
        } else if (unlink_sym_file == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return unlink_sym_file;
}

static int remove_file(const char *pathname) {
    int remove_file_or_dir;
    if (pathname != FILE_IO_DIR_NULL) {
        remove_file_or_dir = remove(pathname);
        if (remove_file_or_dir == FILE_IO_DIR_NULL) {
            return remove_file_or_dir;
        } else if (remove_file_or_dir == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return remove_file_or_dir;
}


static int rename_file(const char *oldname, const char *newname) {
    int rename_file_or_dir;
    if (oldname && newname != FILE_IO_DIR_NULL) {
        rename_file_or_dir = rename(oldname, newname);
        if (rename_file_or_dir == FILE_IO_DIR_NULL) {
            return rename_file_or_dir;
        } else if (rename_file_or_dir == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return rename_file_or_dir;
}

static int rename_sym_file(int oldfd, const char *oldname, int newfd, const char *newname) {
    int rename_sym_file_or_dir;
    if (oldfd && newfd != FILE_IO_DIR_NULL) {
        rename_sym_file_or_dir = renameat(oldfd, oldname, newfd, newname);
        if (rename_sym_file_or_dir == FILE_IO_DIR_NULL) {
            return rename_sym_file_or_dir;
        } else if (rename_sym_file_or_dir == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return rename_sym_file_or_dir;
}

static int create_symlink(const char *actualpath, const char *sympath) {
    int create_symbolic_link;
    if (actualpath && sympath != FILE_IO_DIR_NULL) {
        create_symbolic_link = symlink(actualpath, sympath);
        if (create_symbolic_link == FILE_IO_DIR_NULL) {
            return create_symbolic_link;
        } else if (create_symbolic_link == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    } return create_symbolic_link;
}

static int create_opened_symbolic_link(const char *actualpath, int fd, const char *sympath) {
    int create_opened_sym_link;
    if (fd && actualpath != FILE_IO_DIR_NULL) {
        create_opened_sym_link = symlinkat(actualpath, fd, sympath);
        if (create_opened_sym_link == FILE_IO_DIR_NULL) {
            return create_opened_sym_link;
        } else if (create_opened_sym_link == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return create_opened_sym_link;
}

static ssize_t read_sym_link(const char* pathname, char *buf, size_t bufsize) {
    unsigned int read_symbolic_link;
    if (pathname && buf != FILE_IO_DIR_NULL) {
        read_symbolic_link = readlink(pathname, buf, bufsize);
        if (read_symbolic_link == FILE_IO_DIR_NULL) {
            return read_symbolic_link;
        } else if (read_symbolic_link == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return read_symbolic_link;
}

static ssize_t read_sym_linkat(int fd, const char* pathname, char *buf, size_t bufsize) {
    unsigned int read_opened_sym_link;
    if (fd && pathname && buf && bufsize != FILE_IO_DIR_NULL) {
        read_opened_sym_link = readlinkat(fd, pathname, buf, bufsize);
        if (read_opened_sym_link == FILE_IO_DIR_NULL) {
            return read_opened_sym_link;
        } else if (read_opened_sym_link == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return read_opened_sym_link;
}

static int create_new_directory(const char *pathname, mode_t mode) {
    int create_dir;
    if (pathname && mode != FILE_IO_DIR_NULL) {
        create_dir = mkdir(pathname, mode);
        if (create_dir == FILE_IO_DIR_NULL) {
            return create_dir;
        } else if (create_dir == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return create_dir;
}

static int create_and_open_new_directory(int fd, const char *pathname, mode_t mode) {
    int create_and_open_dir;
    if (fd && pathname && mode != FILE_IO_DIR_NULL) {
        create_and_open_dir = mkdirat(fd, pathname, mode);
        if (create_and_open_dir == FILE_IO_DIR_NULL) {
            return create_and_open_dir;
        } else if (create_and_open_dir == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return create_and_open_dir;
}


static int remove_dir(const char *pathname) {
    int remove_directory;
    if (pathname != FILE_IO_DIR_NULL) {
        remove_directory = rmdir(pathname);
        if (remove_directory == FILE_IO_DIR_NULL) {
            return remove_directory;
        } else if (remove_directory == FILE_IO_DIR_ERROR) {
            return FILE_IO_DIR_ERROR;
        }
    }
    return remove_directory;
}
