#include <stdio.h>
#include <string.h>
int main(void)
{
    char line[32];
    printf("Text: ");
    fflush(stdout);
    if (fgets(line, sizeof line, stdin) == NULL) {
        fprintf(stderr, "No line read.\n");
        return 1;
    }
    size_t n = strlen(line);
    if (n > 0 && line[n - 1] == '\n') {
        line[--n] = '\0';
    } else {
        int ch;
        int extra = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            extra = 1;
        }
        if (extra) {
            fprintf(stderr, "Line too long.\n");
            return 1;
        }
    }
    if (ferror(stdin)) {
        fprintf(stderr, "input error\n");
        return 1;
    }
    printf("length=%zu text=%s\n", n, line);
    return 0;
}
