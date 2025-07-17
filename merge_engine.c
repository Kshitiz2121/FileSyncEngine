#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "merge_engine.h"

char** merge_files(char** base, int base_lines, char** v1, int v1_lines, char** v2, int v2_lines, int* out_lines) {
    int max = base_lines > v1_lines ? base_lines : v1_lines;
    max = max > v2_lines ? max : v2_lines;
    char** merged = NULL;
    *out_lines = 0;

    for (int i = 0; i < max; i++) {
        char* b = i < base_lines ? base[i] : "";
        char* a = i < v1_lines ? v1[i] : "";
        char* c = i < v2_lines ? v2[i] : "";

        if (strcmp(a, c) == 0) {
            merged = realloc(merged, sizeof(char*) * (*out_lines + 1));
            merged[*out_lines] = strdup(a);
            (*out_lines)++;
        } else {
            merged = realloc(merged, sizeof(char*) * (*out_lines + 5));
            merged[(*out_lines)++] = strdup("<<<<<<< Version A\n");
            merged[(*out_lines)++] = strdup(a);
            merged[(*out_lines)++] = strdup("=======\n");
            merged[(*out_lines)++] = strdup(c);
            merged[(*out_lines)++] = strdup(">>>>>>> Version B\n");
        }
    }

    return merged;
}
