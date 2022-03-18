#include "../include/file_io.h"
#include "../src/file_io_operation.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main() {
    std::cout<<"File I/O Lseek operation" <<std::endl;

    char buf[FILE_IO_BUFSIZE];
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    if (argc > 1){
        int fd = create_new_file(argv[1], FILE_IO_MULTIPLE_FLAGS); 
        std::cout<<"create_new_file returned flag: "<<fd<<std::endl;

        unsigned int write_file = write_to_file(fd, buf1, 10);
        if (write_file != 10) {
            std::cout <<"Write to buffer error"<<std::endl;
        } else {
            std::cout<<write_file<<" Bytes written to: "<<fd<<std::endl;
        }
        
        off_t seek_position = seek_file_to_offset(fd, 16384, FILE_IO_SEEK_TO_CURR_VAL);
        std::cout<<"seek_file_to_offset Returned: "<<seek_position<<std::endl;
        if(seek_position != FILE_IO_E_ERROR) {
            std::cout<<"Seeking to current file offset: "<<seek_position<<std::endl;
        }
        
        unsigned int write_file0 = write_to_file(fd, buf2, 10);
        if (write_file0 != 10) {
            std::cout <<"Write to buffer error"<<std::endl;
        } else {
            std::cout<<write_file0<<" Bytes written to: "<<fd<<std::endl;
        }

    } else {
        std::cout<<"Usage: ./file_io [ file_name ]"<<std::endl;
        exit(-1);
    }
}
