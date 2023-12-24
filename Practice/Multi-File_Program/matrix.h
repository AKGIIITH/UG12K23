#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int        num_rows;
    int        num_cols;
    float**     data;
} Matrix;

Matrix* create_matrix(int r, int c);

void destroy_matrix(Matrix* m);

Matrix* add_matrix(Matrix* A, Matrix* B);

Matrix* mult_matrix(Matrix* A, Matrix* B);

Matrix* scalar_mult_matrix(float s, Matrix* M);

void print_matrix(Matrix* m);
