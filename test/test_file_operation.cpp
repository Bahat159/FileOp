#include "../include/file_io.h"
#include "../src/file_io_operation.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main() {
    std::cout<<"FileOp I/O Call" <<std::endl;

    const char *create_file_name= "create_file_name";
    const char *open_file_name= "open_file_name";
    
    int fd = create_new_file(create_file_name, FILE_IO_PERM_READ_WRITE); 
    int fds = open_new_file(open_file_name, FILE_IO_PERM_CREATE_ONLY);
    std::cout<<"open_new_file Returned value: "<<fds<<std::endl;
    
    
    off_t seek_position = seek_file_to_offset(fds, 0, SEEK_TO_CURR_VAL);
    std::cout<<"seek_file_to_offset Returned: "<<seek_position<<std::endl;
    if(seek_position != -1) {
        std::cout<<"Seeking to current file offset"<<std::endl;
        std::cout<<seek_position<<std::endl;
    }
    return 0;
}
