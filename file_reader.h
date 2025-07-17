#ifndef FILE_READER_H
#define FILE_READER_H

char** read_file_lines(const char* filepath, int* line_count);
void free_lines(char** lines, int line_count);

#endif
