#include <iostream>
#include "../include/file_io.h"
#include "../src/file_permission.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main() {
    std::cout<<"File I/O Operation Call" <<std::endl;
  
    check_file_permission_type(READ_ONLY);
    check_file_descriptor(READ_ONLY);

    return 0;
}
