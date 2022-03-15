#include "file_io.h"
#include "file_permission.cpp"
#include "file_operation.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main() {
    std::cout<<"File I/O Operation Call" <<std::endl;

    const char *file_name= "JustinTime";

    check_file_permission_type(READ_WRITE);
    check_file_descriptor(CREATE_ONLY);
    /*
    create_new_file(file_name, MULTIPLE_FLAGS);
    open_new_file(file_name, MULTIPLE_FLAGS);
    */
   off_t seek_position = seek_file_to_offset(READ_ONLY, 0, SEEK_TO_CURR_VAL);
   if(seek_position != -1) {
       std::cout<<"Seeking to current file offset"<<std::endl;
       std::cout<<seek_position<<std::endl;
   }
    
    

    return 0;
}
