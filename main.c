#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"
#include "version_tracker.h"
#include "diff_engine.h"
#include "merge_engine.h"

int main() {
    char *base_path = "base.txt";
    char *v1_path = "version1.txt";
    char *v2_path = "version2.txt";

    int base_count, v1_count, v2_count, merged_count;

    char** base = read_file_lines(base_path, &base_count);
    char** v1 = read_file_lines(v1_path, &v1_count);
    char** v2 = read_file_lines(v2_path, &v2_count);

    if (!base || !v1 || !v2) {
        fprintf(stderr, "Error: Failed to load one or more input files.\n");
        return 1;
    }

    printf("\n🟡 Differences between version1 and version2:\n");
    diff_lines(v1, v1_count, v2, v2_count);

    printf("\n🔧 Performing 3-way merge:\n");
    char** merged = merge_files(base, base_count, v1, v1_count, v2, v2_count, &merged_count);
    printf("Merged line count: %d\n", merged_count);

    FILE* fout = fopen("merged_output.txt", "w");
    if (!fout) {
        perror("Failed to open output file");
        return 1;
    }
    for (int i = 0; i < merged_count; i++) {
        fputs(merged[i], fout);
        free(merged[i]);
    }
    fclose(fout);
    free(merged);

    free_lines(base, base_count);
    free_lines(v1, v1_count);
    free_lines(v2, v2_count);

    printf("✅ Merged output saved to 'merged_output.txt'\n");
    return 0;
}
