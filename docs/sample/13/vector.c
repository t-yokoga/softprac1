#include "vector.h"
#include <stdlib.h>

struct vector {
    double v[2];
};

Vector *vector_create(double x, double y)
{
    Vector *p = malloc(sizeof *p);
    if (p == NULL) {
        return NULL;
    }
    *p = (Vector){.v = {x, y}};
    return p;
}

Vector *vector_axpy(double alpha, const Vector *a, const Vector *b)
{
    if (a == NULL || b == NULL) {
        return NULL;
    }
    return vector_create(alpha * a->v[0] + b->v[0],
                         alpha * a->v[1] + b->v[1]);
}

int vector_get(const Vector *p, size_t index, double *out)
{
    if (p == NULL || index >= 2 || out == NULL) {
        return 0;
    }
    *out = p->v[index];
    return 1;
}

void vector_destroy(Vector **p)
{
    if (p != NULL) {
        free(*p);
        *p = NULL;
    }
}
