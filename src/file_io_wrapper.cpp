#include "../include/file_io.h"
#include "./file_operation.cpp"

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


static void duplicate_process_file_descriptor (int fd) {
    int current_fd =  duplicate_file_descriptor(fd);
    if(current_fd) {
        std::cout<<"duplicate_file_descriptor for create_new_file returned: "<<current_fd<<std::endl;
    }
}

static void set_and_get_file_fd_properties(int fd, int cmd) {
    int status;
    if (cmd != FILE_IO_E_NULL) {
        switch (cmd)
        {
        case FILE_IO_FCNTL_CMD_DUPLICATE_FD:           
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Duplicate the file descriptor fd returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_DUPLICATE_FD_CLOEXEC:            
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Duplicate the file descriptor returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_GET_FD:          
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Get flags for fd returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_SET_FD:            
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Set the file descriptor flags for fd returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_GET_FILE_STATUS_FLAG:          
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Get file status flags for fd returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_SET_FILE_STATUS_FLAG:      
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Set file status flags to the value returned: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_GET_PROCESS_ID:      
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Get the process ID or process group ID receiving SIGIO and SIGURG: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_SET_PROCESS_ID:         
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Set the process ID or process group ID to receive SIGIO and SIGURG: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_GET_RECORD_LOCK:         
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Get Process Record Lock: "<<status<<std::endl;
            break;
        case FILE_IO_FCNTL_CMD_SET_RECORD_LOCK:         
            status = set_and_get_file_descripor_with_cmd(fd, cmd);
            std::cout<<"Set Process Record Lock: "<<status<<std::endl;
            break;
        default:
            std::cout<<"Unknown file descriptor Flag"<<std::endl;
            break;
        }
    }
}
