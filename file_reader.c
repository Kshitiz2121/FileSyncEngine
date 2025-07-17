#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_reader.h"

char** read_file_lines(const char* filepath, int* line_count) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char** lines = NULL;
    char buffer[1024];
    *line_count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        lines = realloc(lines, sizeof(char*) * (*line_count + 1));
        lines[*line_count] = strdup(buffer);
        (*line_count)++;
    }

    fclose(file);
    return lines;
}

void free_lines(char** lines, int line_count) {
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
}
