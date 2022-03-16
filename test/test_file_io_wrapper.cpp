#include "../include/file_io.h"
#include "../src/file_io_wrapper.cpp"

/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

int main(int argc, char *argv[]) {
    std::cout<<"File I/O Operation Call" <<std::endl;
    
    
    char buf[FILE_IO_BUFSIZE];
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";
    off_t pread_offset = 0;
    off_t pwrite_offset = 1024;


    if (argc > 1){
        int fd = create_new_file(argv[1], FILE_IO_MULTIPLE_FLAGS); 
        std::cout<<"create_new_file returned flag: "<<fd<<std::endl;
        
        open_and_read_file(argv[2], buf);
        write_seek_file_for_single_process(fd, buf1, buf2, 16384, 10);
        write_read_file_for_multiple_process(fd, buf1, 10, pwrite_offset, pread_offset);
        

    } else {
        std::cout<<"Usage: ./file_io [ create_new_file name ] [ open_and_read_file name] optional"<<std::endl;
        exit(-1);
    }


    return 0;
}

