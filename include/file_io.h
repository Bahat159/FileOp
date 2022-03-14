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


static void check_file_permission_type(char file_perm) {
    switch (file_perm)
    {
    case READ_ONLY:
        std::cout <<"READ_ONLY"<<std::endl;
        break;
    
    default:
        std::cout <<"Unknown file permission type"<<std::endl;
        break;
    }
}

static void check_file_descriptor(char file_perm) {
    if (file_perm == O_RDONLY){
        std::cout<<"O_RDONLY File Descriptor: "<<READ_ONLY<<std::endl;
    }
}

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

static int close_opened_file(int fd) {
    int closed_fd = close(fd);
    if(closed_fd == 0) {
        return 0;
    } else {
        return -1;
    }
}
