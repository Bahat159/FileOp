#include "../include/file_io.h"


/*
Author: Busari Habibullaah
Year: March, 2022
Copyright: SandCroft Software
Project Type: Open-source 
*/

static int get_file_stat(const char *pathname, struct stat *buf) {
    int get_stat;
    if (pathname && buf != FILE_IO_DIR_NULL) {
        get_stat = stat(pathname, buf);
        if( get_stat == FILE_IO_DIR_NULL) {
            return get_stat;
        } else {
            return FILE_IO_E_ERROR;
        }
    }
    return get_stat;
}


