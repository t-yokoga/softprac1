#include "vector.h"
#include <stdio.h>

int main(void)
{
    Vector *x = NULL;
    Vector *y = NULL;
    Vector *result = NULL;
    int status = 1;
    double first, second;

    x = vector_create(1.0, 2.0);
    if (x == NULL) {
        fputs("allocation failed\n", stderr);
        goto cleanup;
    }
    y = vector_create(3.0, 4.0);
    if (y == NULL) {
        fputs("allocation failed\n", stderr);
        goto cleanup;
    }
    result = vector_axpy(2.0, x, y);
    if (result == NULL) {
        fputs("allocation failed\n", stderr);
        goto cleanup;
    }
    if (!vector_get(result, 0, &first) ||
        !vector_get(result, 1, &second)) {
        fputs("invalid access\n", stderr);
        goto cleanup;
    }
    printf("result=%.1f %.1f\n", first, second);
    status = 0;

cleanup:
    vector_destroy(&result);
    vector_destroy(&y);
    vector_destroy(&x);
    return status;
}
