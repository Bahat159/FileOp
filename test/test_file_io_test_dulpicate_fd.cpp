#include "../include/file_io.h"
#include "../src/file_io_wrapper.cpp"

int main(int argc, char *argv[]) {
    std::cout<<"File I/O Operation Call" <<std::endl;

    if (argc > 1){
        int fd = create_new_file(argv[1], FILE_IO_MULTIPLE_FLAGS); 
        std::cout<<"create_new_file file descriptor returned: "<<fd<<std::endl;

        duplicate_process_file_descriptor (fd);

    } else {
        std::cout<<"Usage: ./file_io [ create_new_file name ] [ open_and_read_file name] optional"<<std::endl;
        exit(-1);
    }
    return 0;
}
