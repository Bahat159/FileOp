
#include "../src/file_operation.cpp"
#include "../src/file_io_dir_operation.cpp"

int main(int argc, char *argv[]){
    std::cout<<"File I/O Operation Call" <<std::endl;
    std::cout<<"File stat Test"<<std::endl;

    struct stat buf;

    if (argc > 1){
        int returned_value = get_file_stat (argv[1], &buf);
        std::cout<<"get_file_stat returned: "<< returned_value<<std::endl;

        int fd = open_new_file(argv[2], FILE_IO_PERM_CREATE_ONLY);
        int ret_fstat = get_file_fstat(fd, &buf);
        std::cout<<"get_file_fstat returned: "<<ret_fstat<<std::endl;

    } else {
        std::cout<<"Usage: ./test_file_io_dir_stat [ file_name  ]"<<std::endl;
        exit(-1);
    }
    return 0;
}
