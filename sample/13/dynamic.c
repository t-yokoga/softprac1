#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: Dynamic count (1..1000)\n");
        return 1;
    }
    char *end;
    errno = 0;
    long count = strtol(argv[1], &end, 10);
    if (argv[1] == end || *end != '\0' || errno == ERANGE ||
        count < 1 || count > 1000) {
        fprintf(stderr, "count must be 1..1000\n");
        return 1;
    }
    size_t n = (size_t)count;
    int *values = NULL;
    if (n > SIZE_MAX / sizeof *values) {
        fprintf(stderr, "size overflow\n");
        return 1;
    }
    values = malloc(n * sizeof *values);
    if (values == NULL) {
        fprintf(stderr, "allocation failed\n");
        return 1;
    }
    long long sum = 0;
    for (size_t i = 0; i < n; ++i) {
        values[i] = (int)i + 1;
        sum += values[i];
    }
    printf("n=%zu sum=%lld mean=%.1f\n", n, sum, (double)sum / n);
    free(values);
    values = NULL;
    return 0;
}
