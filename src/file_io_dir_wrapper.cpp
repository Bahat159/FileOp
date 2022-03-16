#include "../include/file_io.h"
#include "../src/file_io_dir_operation.cpp"

static void get_file_stat_with_mode(const char *pathname, struct stat *buf) {
    int get_stat_mode = get_file_stat(pathname, buf);
    std::cout<<"get_file_stat returned: "<< get_stat_mode<<std::endl;

    if (FILE_IO_TYPE_IS_REG(buf->st_mode)) {
        std::cout<<"File Type is REGULAR "<<std::endl;
    } else if (FILE_IO_TYPE_IS_DIR(buf->st_mode)) {
        std::cout<<"File Type is DIRECTORY "<<std::endl;
    } else if (FILE_IO_TYPE_IS_SP_CHAR(buf->st_mode)) {
        std::cout<<"File Type is SPECIAL CHARACTER "<<std::endl;
    } else if (FILE_IO_TYPE_IS_SP_BLK(buf->st_mode)) {
        std::cout<<"File Type is SPECIAL BLOCK "<<std::endl;
    } else if (FILE_IO_TYPE_IS_FIFO(buf->st_mode)) {
        std::cout<<"File Type is FIFO "<<std::endl;
    } else if (FILE_IO_TYPE_IS_SYM_LINK(buf->st_mode)) {
        std::cout<<"File Type is SYMBOLIC LINK "<<std::endl;
    } else if (FILE_IO_TYPE_IS_SOCKET(buf->st_mode)) {
        std::cout<<"File Type is SOCKET "<<std::endl;
    } else {
        std::cout<<"Unknown file type"<<std::endl;
    }
}
