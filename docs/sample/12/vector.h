#ifndef PL1_VECTOR_H
#define PL1_VECTOR_H

typedef struct {
    double v[2];
} Vector;

Vector axpy(double alpha, Vector a, Vector b);
void print_vector(Vector a);

#endif
