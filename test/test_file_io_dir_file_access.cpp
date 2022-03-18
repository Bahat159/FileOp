#include "../src/file_io_operation.cpp"
#include "../src/file_io_dir_operation.cpp"
/// #include "../src/file_io_dir_wrapper.cpp"

int main(int argc, char *argv[]){
    std::cout<<"File I/O Operation Call" <<std::endl;
    std::cout<<"File stat Test"<<std::endl;


    if (argc > 1){
        
        int access_read = set_file_access_mode(argv[1], FILE_IO_ACCESS_MODE_READ);

        if(access_read == FILE_IO_E_NULL) {
            std::cout<<"Access Read okay" <<std::endl;
        }
        std::cout<<"set_file_access_mode returned: "<<access_read<<std::endl;

        int open_to_read = open_new_file(argv[1], FILE_IO_PERM_READ_ONLY);
        if (open_to_read != FILE_IO_E_ERROR){
            std::cout<<"["<<argv[1] <<"] Open for reading"<<std::endl;
        }
        std::cout<<"open_new_file returned: "<<open_to_read<<std::endl;

    } else {
        std::cout<<"Usage: ./test_file_io_dir_stat [ file_name  ]"<<std::endl;
        exit(-1);
    }
    return 0;
}
