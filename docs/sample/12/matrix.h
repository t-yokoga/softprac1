#ifndef PL1_MATRIX_H
#define PL1_MATRIX_H

#include "vector.h"

typedef struct {
    double v[4];
} Matrix;

Vector gemv(double alpha, Matrix a, Vector x, double beta, Vector y);
void print_matrix(Matrix a);

#endif
