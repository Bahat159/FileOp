#include "../include/file_io.h"
#include "../src/file_operation.cpp"

static void open_and_read_file(const char *open_file_name, void *buf) {

    int fds = open_new_file(open_file_name, FILE_IO_MULTIPLE_FLAGS);
    std::cout<<"open_new_file Returned value: "<<fds<<std::endl;

    unsigned int n = read_from_file(fds, buf, FILE_IO_BUFSIZE);
    if(n) {
        std::cout<<"read_from_file bytes read: "<<n<<std::endl;
    }

}

static void write_read_file_for_multiple_process(int fd, void *buffer, ssize_t nbytes, off_t pwrite_offset, off_t pread_offset){
    
    ssize_t write_to_multiple_file = pwrite_with_multiple_process(fd, buffer, nbytes, pwrite_offset);
    std::cout<<"pwrite_with_multiple_process bytes written: "<<write_to_multiple_file<<std::endl;
    
    ssize_t read_with_multiple_process = pread_with_multiple_process(fd, buffer, nbytes, pread_offset);
    std::cout<<"pread_with_multiple_process bytes: "<<read_with_multiple_process<<std::endl;
}

static void write_seek_file_for_single_process(int fd, void *buffer0, void *buffer1, off_t offset, size_t nbytes){

    unsigned int write_file = write_to_file(fd, buffer0, nbytes);
    if (write_file != nbytes) {
        std::cout <<"Write to buffer error"<<std::endl;
    } else {
        std::cout<<write_file<<" Bytes written to: "<<fd<<std::endl;
    }
    /// offset can be any given length. 1600
    off_t seek_position = seek_file_to_offset(fd, offset, FILE_IO_SEEK_TO_CURR_VAL);
    std::cout<<"seek_file_to_offset Returned: "<<seek_position<<std::endl;
    if(seek_position != FILE_IO_E_ERROR) {
        std::cout<<"Seeking to current file offset: "<<seek_position<<std::endl;
    }
    
    unsigned int write_file0 = write_to_file(fd, buffer1, nbytes);
    if (write_file0 != nbytes) {
        std::cout <<"Write to buffer error"<<std::endl;
    } else {
        std::cout<<write_file0<<" Bytes written to: "<<fd<<std::endl;
    }
}
