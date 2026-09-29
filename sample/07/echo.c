#include <stdio.h>
int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF) {
        if (putchar(ch) == EOF) {
            fprintf(stderr, "output error\n");
            return 1;
        }
    }
    if (ferror(stdin)) {
        fprintf(stderr, "input error\n");
        return 1;
    }
    return 0;
}
