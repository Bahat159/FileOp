#include <iostream>
#include <fcntl.h>  
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/


/* File Access Permission Flag  */

#ifndef FILE_IO_PERM_
#define FILE_IO_PERM_READ_ONLY           O_RDONLY
#define FILE_IO_PERM_WRITE_ONLY          O_WRONLY    
#define FILE_IO_PERM_READ_WRITE          O_RDWR      
#define FILE_IO_PERM_EXECUTE_ONLY        O_EXEC   
#define FILE_IO_PERM_SEARCH_ONLY         O_SEARCH    
#define FILE_IO_PERM_APPEND_ONLY         O_APPEND    
#define FILE_IO_PERM_CLOSE_EXECTUE       O_CLOEXEC   
#define FILE_IO_PERM_CREATE_ONLY         O_CREAT     
#define FILE_IO_PERM_DIRECTORY_ONLY      O_DIRECTORY 
#define FILE_IO_PERM_CHECK_FILE_EXIST    O_EXCL      
#define FILE_IO_PERM_NOCTTY_ONLY         O_NOCTTY    
#define FILE_IO_PERM_NO_FOLLOW           O_NOFOLLOW  
#define FILE_IO_PERM_NON_BLOCKING        O_NONBLOCK  
#define FILE_IO_PERM_SYNC_ONLY           O_SYNC      
#define FILE_IO_PERM_TRUNCATE_ONLY       O_TRUNC     
#define FILE_IO_PERM_INIT_TTY            O_TTY_INIT  
#define FILE_IO_PERM_DESYNC_ONLY         O_DSYNC     
#define FILE_IO_PERM_RESYNC_ONLY         O_RSYNC     
#endif

#ifndef FILE_IO_
#define FILE_IO_E_NULL                  '\0'
#define FILE_IO_E_ERROR                 -1
#define FILE_IO_E_EOF                   EOF
#define FILE_IO_DIR_NULL                0
#define FILE_IO_DIR_ERROR               -1
#endif

#ifndef FILE_IO_MULTIPLE_FLAGS
#define FILE_IO_MULTIPLE_FLAGS        (FILE_IO_PERM_READ_WRITE | FILE_IO_PERM_CREATE_ONLY | FILE_IO_PERM_TRUNCATE_ONLY)
#endif

#ifndef FILE_IO_SEEK_
#define FILE_IO_SEEK_TO_BEGINNING      SEEK_SET
#define FILE_IO_SEEK_TO_CURR_VAL       SEEK_CUR
#define FILE_IO_SEEK_TO_EOF            SEEK_END
#endif

#ifndef FILE_IO_BUFSIZE
#define FILE_IO_BUFSIZE                4096
#endif

#ifndef FILE_IO_FCNTL_CMD_
#define FILE_IO_FCNTL_CMD_DUPLICATE_FD                   F_DUPFD         
#define FILE_IO_FCNTL_CMD_DUPLICATE_FD_CLOEXEC           F_DUPFD_CLOEXEC 
#define FILE_IO_FCNTL_CMD_GET_FD                         F_GETFD     
#define FILE_IO_FCNTL_CMD_SET_FD                         F_SETFD     
#define FILE_IO_FCNTL_CMD_GET_FILE_STATUS_FLAG           F_GETFL    
#define FILE_IO_FCNTL_CMD_SET_FILE_STATUS_FLAG           F_SETFL    
#define FILE_IO_FCNTL_CMD_GET_PROCESS_ID                 F_GETOWN    
#define FILE_IO_FCNTL_CMD_SET_PROCESS_ID                 F_SETOWN
#define FILE_IO_FCNTL_CMD_GET_RECORD_LOCK                F_GETLK
#define FILE_IO_FCNTL_CMD_SET_RECORD_LOCK                F_SETLK
#endif


/* File Type */

#ifndef FILE_IO_TYPE_
#define FILE_IO_TYPE_IS_REG(mode)            S_ISREG(mode)
#define FILE_IO_TYPE_IS_DIR(mode)            S_ISDIR(mode)
#define FILE_IO_TYPE_IS_SP_CHAR(mode)        S_ISCHR(mode)
#define FILE_IO_TYPE_IS_SP_BLK(mode)         S_ISBLK(mode)
#define FILE_IO_TYPE_IS_FIFO(mode)           S_ISFIFO(mode)
#define FILE_IO_TYPE_IS_SYM_LINK(mode)       S_ISLNK(mode)
#define FILE_IO_TYPE_IS_SOCKET(mode)         S_ISSOCK(mode)   
#endif

/* File Object Type */

#ifndef FILE_IO_OBJ_TYPE_
#define FILE_IO_OBJ_TYPE_MSG_Q(mode)        S_TYPEISMQ(mode)
#define FILE_IO_OBJ_TYPE_SEM(mode)          S_TYPEISSEM(mode)
#define FILE_IO_OBJ_TYPE_SH_MEM(mode)       S_TYPEISSHM(mode)
#endif

/* File Access Permission mode */

#ifndef FILE_IO_ACCESS_PERM_
#define FILE_IO_ACCESS_PERM_USR_RD      S_IRUSR
#define FILE_IO_ACCESS_PERM_USR_WR      S_IWUSR
#define FILE_IO_ACCESS_PERM_USR_EX      S_IXUSR
#define FILE_IO_ACCESS_PERM_GRP_RD      S_IRGRP
#define FILE_IO_ACCESS_PERM_GRP_WR      S_IWGRP
#define FILE_IO_ACCESS_PERM_GRP_EX      S_IXGRP
#define FILE_IO_ACCESS_PERM_OTH_RD      S_IROTH
#define FILE_IO_ACCESS_PERM_OTH_WR      S_IWOTH
#define FILE_IO_ACCESS_PERM_OTH_EX      S_IXOTH
#define FILE_IO_ACCESS_PERM_USR_ID      S_ISUID     // set-user-ID on execution
#define FILE_IO_ACCESS_PERM_GRP_ID      S_ISGID     // set-group-ID on execution
#define FILE_IO_ACCESS_PERM_SAV_TX      S_ISVTX     // saved-text (sticky bit)
#endif

/* File Access Mode */
#ifndef FILE_IO_ACCESS_MODE_
#define FILE_IO_ACCESS_MODE_READ        R_OK
#define FILE_IO_ACCESS_MODE_WRITE       W_OK
#define FILE_IO_ACCESS_MODE_EXC         X_OK
#endif


/* File_io operation */
static int close_opened_file(int fd);
static void check_file_descriptor(char fd);
static void check_file_permission_type(char file_perm);
static int create_new_file(const char *path, mode_t mode);
static int open_new_file(const char *path, int oflag);
static int open_file_with_fd(int fd, const char *path, int oflag);
static off_t seek_file_to_offset(int fd, off_t offset, int whence);
static ssize_t read_from_file(int fd, void *buf, size_t nbytes);
static ssize_t write_to_file(int fd, const void *buf, size_t nbytes);
static ssize_t pread_with_multiple_process(int fd, void *buf, size_t nbytes, off_t offset);
static ssize_t pwrite_with_multiple_process(int fd, const void *buf, size_t nbytes, off_t offset);
static int duplicate_file_descriptor(int fd);
static int duplicate_file_descriptor(int old_fd, int new_fd);
static int fdatasync_file_data(int fd);
static int fsync_disk_io_buffercache_or_pagecache(int fd);
static int set_and_get_file_descriptor_with_cmd(int fd, int cmd, int arg);

/* File_io test wrapper */
static void open_and_read_file(const char *open_file_name, void *buf);
static void write_read_file_for_multiple_process(int fd, void *buffer, ssize_t nbytes, off_t pwrite_offset, off_t pread_offset);
static void write_seek_file_for_single_process(int fd, void *buffer0, void *buffer1, off_t offset, size_t nbytes);
static void duplicate_process_file_descriptor (int fd);
static void set_and_get_file_fd_properties(int fd, int cmd);


/* File_io Dir operation */
static int get_file_stat(const char *pathname, struct stat *buf);
static int get_file_fstat(int fd, struct stat *buf);
static int get_symbolic_link_file_stat(const char *pathname, struct stat *buf);
static int get_file_statistic_fstatat(int fd, const char *pathname, struct stat *buf, int flag);
static int set_file_access_mode(const char *pathname, int mode);
static int get_file_access_mode(int fd, const char *pathname, int mode, int flag);
static int change_open_file_access_permission_mode(int fd, mode_t mode);
static int change_file_access_permission_mode (const char *pathname, mode_t mode);
static int change_file_user_group_id(const char *pathname, uid_t owner, gid_t group);
static int change_opened_file_user_group_id(int fd, uid_t owner, gid_t group);
static int change_open_file_sym_user_group_id(int fd, const char *pathname, uid_t owner, gid_t group, int flag);
static int change_file_sym_user_group_id_lchown(const char *pathname, uid_t owner, gid_t group);
static int truncate_open_file_data(int fd, off_t length);
static int truncate_file_data(const char *pathname, off_t length);
static int link_to_existing_file(const char *existing_file_path, const char *new_file_path);
static int link_to_existing_opened_file(int efd, const char *existing_file_path, int nfd, const char *new_file_path, int flag);
static int unlink_file_path(const char *pathname);
static int unlink_sym_file_path(int fd, const char *pathname, int flag);
static int remove_file(const char *pathname);
static int rename_file(const char *oldname, const char *newname);
static int rename_sym_file(int oldfd, const char *oldname, int newfd, const char *newname);
static int create_symlink(const char *actualpath, const char *sympath);
static int create_opened_symbolic_link(const char *actualpath, int fd, const char *sympath);
static ssize_t read_sym_link(const char* pathname, char *buf, size_t bufsize);
static ssize_t read_sym_linkat(int fd, const char* pathname, char *buf, size_t bufsize);
static int create_new_directory(const char *pathname, mode_t mode);
static int create_and_open_new_directory(int fd, const char *pathname, mode_t mode);
static int remove_dir(const char *pathname);
static DIR *open_directory(const char *pathname);
static DIR *open_directory_with_fd(int fd);
struct dirent *read_directory_file(DIR *dp);
static void rewind_directory(DIR *dp);
static int close_directory(DIR *dp);
static long report_current_location_in_directory(DIR *dp);
static void seek_into_directory(DIR *dp, long location);

/* File_io Dir wrapper */
static void get_file_stat_with_mode(const char *pathname, struct stat *buf);


