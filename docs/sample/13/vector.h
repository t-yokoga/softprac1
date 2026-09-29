#ifndef PL1_DYNAMIC_VECTOR_H
#define PL1_DYNAMIC_VECTOR_H

#include <stddef.h>

typedef struct vector Vector;

/* Successful creation transfers ownership to the caller. */
Vector *vector_create(double x, double y);
Vector *vector_axpy(double alpha, const Vector *a, const Vector *b);
/* On failure, leave *out unchanged. */
int vector_get(const Vector *p, size_t index, double *out);
/* p may be NULL; *p must be NULL or an owned live Vector. */
void vector_destroy(Vector **p);

#endif
