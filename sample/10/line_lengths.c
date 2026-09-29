#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1][0] == '\0') {
        fprintf(stderr, "usage: LineLengths filename\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) { perror("fopen"); return 1; }
    char line[32];
    int failed = 0;
    while (fgets(line, sizeof line, fp) != NULL) {
        size_t length = strlen(line);
        if (length > 0 && line[length - 1] == '\n') {
            line[--length] = '\0';
        } else if (length == sizeof line - 1) {
            int ch = fgetc(fp);
            if (ch != '\n' && ch != EOF) {
                fprintf(stderr, "line too long\n");
                failed = 1;
                break;
            }
        }
        if (printf("%zu\n", length) < 0) { failed = 1; break; }
    }
    if (ferror(fp)) { failed = 1; }
    if (fclose(fp) == EOF) { failed = 1; }
    if (fflush(stdout) == EOF) { failed = 1; }
    if (failed) { fprintf(stderr, "read or output error\n"); return 1; }
    return 0;
}
