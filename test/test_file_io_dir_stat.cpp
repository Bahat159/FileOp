#include "../src/file_operation.cpp"
///#include "../src/file_io_dir_operation.cpp"
#include "../src/file_io_dir_wrapper.cpp"

int main(int argc, char *argv[]){
    std::cout<<"File I/O Operation Call" <<std::endl;
    std::cout<<"File stat Test"<<std::endl;

    struct stat buf;

    if (argc > 1){
        
        get_file_stat_with_mode(argv[1], &buf);
        
        int fd = open_new_file(argv[2], FILE_IO_PERM_CREATE_ONLY);
        int ret_fstat = get_file_fstat(fd, &buf);
        std::cout<<"get_file_fstat returned: "<<ret_fstat<<std::endl;

        int ret_lstat = get_symbolic_link_file_stat(argv[1], &buf);
        std::cout<<"get_symbolic_link_file_stat returned: "<<ret_lstat<<std::endl;

    } else {
        std::cout<<"Usage: ./test_file_io_dir_stat [ file_name  ]"<<std::endl;
        exit(-1);
    }
    return 0;
}
