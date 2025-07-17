#ifndef VERSION_TRACKER_H
#define VERSION_TRACKER_H

#include <sys/stat.h>

int get_file_mod_time(const char* path, time_t* mod_time);
int files_are_different(const char* path1, const char* path2);

#endif
