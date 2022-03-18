#include "../include/file_io.h"
#include "../src/file_io_operation.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main(int argc, char *argv[]) {
    std::cout<<"File I/O multiple process pread, pwrite Operation Call" <<std::endl;
 
    char buf1[] = "abcdefghij";
  
    if (argc > 1){
        int fd = create_new_file(argv[1], FILE_IO_MULTIPLE_FLAGS); 
        std::cout<<"create_new_file returned flag: "<<fd<<std::endl;

        ssize_t write_to_multiple_file = pwrite_with_multiple_process(fd, buf1, 10, 1024);
        std::cout<<"pwrite_with_multiple_process bytes written: "<<write_to_multiple_file<<std::endl;

        ssize_t read_with_multiple_process = pread_with_multiple_process(fd, buf1, 10, 0);
        std::cout<<"pread_with_multiple_process bytes: "<<read_with_multiple_process<<std::endl;
 
    }
    
    
    return 0;
}
