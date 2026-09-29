#include "vector.h"
#include <stdio.h>

Vector axpy(double alpha, Vector a, Vector b)
{
    Vector result = {{alpha * a.v[0] + b.v[0],
                      alpha * a.v[1] + b.v[1]}};
    return result;
}

void print_vector(Vector a)
{
    printf("(%.1f, %.1f)\n", a.v[0], a.v[1]);
}
