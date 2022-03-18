#include "../include/file_io.h"
#include "../src/file_io_permission.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main() {
    std::cout<<"File I/O Operation Call" <<std::endl;
  
    check_file_descriptor(CREATE_ONLY);

    return 0;
}
