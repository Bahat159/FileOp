#include "../include/file_io.h"
#include "../src/file_io_wrapper.cpp"


int main(int argc, char *argv[]) {
    std::cout<<"File I/O Operation Call" <<std::endl;

    if (argc > 1){
        int fd = open_new_file(argv[1], FILE_IO_MULTIPLE_FLAGS); 
        std::cout<<"open_new_file file descriptor returned: "<<fd<<std::endl;

        set_and_get_file_fd_properties(fd, FILE_IO_FCNTL_CMD_DUPLICATE_FD);

        int se_ = set_and_get_file_descriptor_with_cmd(fd, FILE_IO_FCNTL_CMD_GET_FD);
        std::cout<<"file access mode: " <<se_<<std::endl;
        int record_l = set_and_get_file_descriptor_with_cmd(fd, FILE_IO_FCNTL_CMD_DUPLICATE_FD, FILE_IO_FCNTL_CMD_GET_FILE_STATUS_FLAG);

        std::cout<<"file access mode: " <<record_l<<std::endl;

    } else {
        std::cout<<"Usage: ./file_io [ create_new_file name ] [ open_and_read_file name] optional"<<std::endl;
        exit(-1);
    }
    return 0;
} 
