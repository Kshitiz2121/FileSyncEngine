#include <stdio.h>
#include "version_tracker.h"

int get_file_mod_time(const char* path, time_t* mod_time) {
    struct stat attr;
    if (stat(path, &attr) != 0) {
        perror("stat failed");
        return -1;
    }
    *mod_time = attr.st_mtime;
    return 0;
}

int files_are_different(const char* path1, const char* path2) {
    time_t t1, t2;
    if (get_file_mod_time(path1, &t1) || get_file_mod_time(path2, &t2))
        return -1;
    return t1 != t2;
}
