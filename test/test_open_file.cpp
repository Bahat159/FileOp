#include "file_io.h"
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
   
    create_new_file(file_name, MULTIPLE_FLAGS);
    open_new_file(file_name, READ_WRITE);

    return 0;
}
