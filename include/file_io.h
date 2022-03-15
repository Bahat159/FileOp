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

#ifndef FILE_IO_PERM
#define FILE_IO_PERM

#define READ_ONLY           O_RDONLY
#define WRITE_ONLY          O_WRONLY    
#define READ_WRITE          O_RDWR      
#define EXECUTE_ONLY        O_EXEC   
#define SEARCH_ONLY         O_SEARCH    
#define APPEND_ONLY         O_APPEND    
#define CLOSE_EXECTUE       O_CLOEXEC   
#define CREATE_ONLY         O_CREAT     
#define DIRECTORY_ONLY      O_DIRECTORY 
#define CHECK_FILE_EXIST    O_EXCL      
#define NOCTTY_ONLY         O_NOCTTY    
#define NO_FOLLOW           O_NOFOLLOW  
#define NON_BLOCKING        O_NONBLOCK  
#define SYNC_ONLY           O_SYNC      
#define TRUNCATE_ONLY       O_TRUNC     
#define INIT_TTY            O_TTY_INIT  
#define DESYNC_ONLY         O_DSYNC     
#define RESYNC_ONLY         O_RSYNC     

#endif

#ifndef FILE_IO_NULL
#define FILE_IO_NULL    '\0'
#endif

#ifndef FILE_IO_MULTIPLE_FLAGS
#define MULTIPLE_FLAGS (READ_WRITE | O_CREAT | O_TRUNC)
#endif

#ifndef FILE_IO_SEEK_POS
#define SEEK_TO_BEGINNING       SEEK_SET
#define SEEK_TO_CURR_VAL        SEEK_CUR
#define SEEK_TO_EOF             SEEK_END
#endif

static int close_opened_file(int fd);
static void check_file_descriptor(char fd);
static void check_file_permission_type(char file_perm);
static int create_new_file(const char *path, mode_t mode);
static int open_new_file(const char *path, int oflag);
static int open_file_with_fd(int fd, const char *path, int oflag);
static off_t seek_file_to_offset(int fd, off_t offset, int whence);
