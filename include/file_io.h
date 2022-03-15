#include <iostream>
#include <fcntl.h>  
#include <unistd.h>

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/


/* File permission */

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



/* File_io test wrapper */
static void open_and_read_file(const char *open_file_name, void *buf);
static void write_read_file_for_multiple_process(int fd, void *buffer, ssize_t nbytes, off_t pwrite_offset, off_t pread_offset);
static void write_seek_file_for_single_process(int fd, void *buffer0, void *buffer1, off_t offset, size_t nbytes);
