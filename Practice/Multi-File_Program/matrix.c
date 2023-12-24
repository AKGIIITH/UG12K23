#include "matrix.h"

Matrix* create_matrix(int r, int c) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (float**) calloc(r, sizeof(float*));
    for (int i =0; i < r; i++) {
        m->data[i] = (float*) calloc(c, sizeof(float));
    }
    return m;
}
/* m points to pointer data which points to data[i] that contain value of ith row that contains
array of size c, Elements of C[j] is value of (i,j).*/

void destroy_matrix(Matrix* m) {
    for(int i=0;i<m->num_rows;i++){
        free(m->data[i]);
    }
    free(m->data);
    free(m);
    
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
    if(A->num_rows==B->num_rows && A->num_cols==B->num_cols){
        Matrix* C=create_matrix(A->num_rows,A->num_cols);
        for(int i=0;i<A->num_rows;i++){
            for(int j=0;j<A->num_cols;j++){
                (C->data[i])[j]=(A->data[i])[j]+(B->data[i])[j];
            }
        }
        return C;
    }
    else{
        return NULL;
    }
   
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
    if(A->num_rows==B->num_cols){
        Matrix* C=create_matrix(A->num_rows,A->num_cols);
        for(int j=0;j<A->num_rows;j++){
            for(int i=0;i<A->num_cols;i++){
                (C->data[i])[j]=(C->data[i])[j]+(A->data[i])[j]*(B->data[j])[i];
            }
        }
        return C;
    }
    else{
        return NULL;
    }  
}

Matrix* scalar_mult_matrix(float s, Matrix* M) {
    Matrix* C=create_matrix(M->num_rows,M->num_cols);
    for(int i=0;i<M->num_rows;i++){
            for(int j=0;j<M->num_cols;j++){
                (C->data[i])[j]=((M->data[i])[j])*s;
            }
        }
    return C;    
}

void print_matrix(Matrix* m) {
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%f\t", m->data[i][j]);
        }
        printf("\n");
    }
}
