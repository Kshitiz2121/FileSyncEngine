#include <stdio.h>
#include <string.h>
#include "diff_engine.h"

void diff_lines(char** old_lines, int old_count, char** new_lines, int new_count) {
    int max = old_count > new_count ? old_count : new_count;

    for (int i = 0; i < max; i++) {
        if (i >= old_count) {
            printf("\x1b[32m+ %s\x1b[0m", new_lines[i]);  // Green for addition
        } else if (i >= new_count) {
            printf("\x1b[31m- %s\x1b[0m", old_lines[i]);  // Red for deletion
        } else if (strcmp(old_lines[i], new_lines[i]) != 0) {
            printf("\x1b[33m~ %s\x1b[0m", new_lines[i]);  // Yellow for modification
        }
    }
}
