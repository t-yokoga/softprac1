#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1][0] == '\0') {
        fprintf(stderr, "usage: ReadText filename\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    int ch;
    int failed = 0;
    while ((ch = fgetc(fp)) != EOF) {
        if (putchar(ch) == EOF) { failed = 1; break; }
    }
    if (ferror(fp)) { failed = 1; }
    if (fclose(fp) == EOF) { failed = 1; }
    if (fflush(stdout) == EOF) { failed = 1; }
    if (failed) {
        fprintf(stderr, "I/O error\n");
        return 1;
    }
    return 0;
}
