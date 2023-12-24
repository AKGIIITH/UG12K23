#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int num_rows;
    int num_cols;
    long long int** data;
} Matrix;


Matrix* create_matrix(int r, int c) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int**) calloc(r, sizeof(long long int*));

    for (int i =0; i < r; i++) {
        m->data[i] = (long long int*) calloc(c, sizeof(long long int));
        for(int j=0;j<c;j++){ //Cleaning the Arrays to while making to work smoothly
            (m->data[i])[j]=0;
        }
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
    if(A->num_cols==B->num_rows){
        Matrix* C=create_matrix(A->num_rows,B->num_cols);
        for(int i=0;i<A->num_rows;i++){
            for(int j=0;j<B->num_cols;j++){
                for(int k=0;k<A->num_cols;k++){
                (C->data[i])[j]=(C->data[i])[j]+(A->data[i])[k]*(B->data[k])[i];
                }
            }
        }
        return C;
    }
    else{
        return NULL;
    }  
}

Matrix* scalar_mult_matrix(long long int s, Matrix* M) {
    Matrix* C=create_matrix(M->num_rows,M->num_cols);
    for(int i=0;i<M->num_rows;i++){
        for(int j=0;j<M->num_cols;j++){
                (C->data[i])[j]=((M->data[i])[j])*s;
            }
        }
    return C;    
}

void print_matrix(Matrix* m) {
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* transpose_matrix(Matrix* A) {
    Matrix* c=create_matrix(A->num_cols,A->num_rows);
    for(int i=0;i<A->num_rows;i++){
        for(int j=0;j<A->num_cols;j++){
            (c->data[j])[i]=(A->data[i])[j];
        }
    }
    return c;
}

long long int determinant(Matrix* M) {
    long long int det=0;
    for(int j=0;j<M->num_cols;j++){
        long long int tempdet=1;
        for(int i=0;i<M->num_rows;i++){
            tempdet=tempdet*((M->data[i])[(j+i)%(M->num_cols)]);
        }
        det=det+tempdet;
    }
    for(int j=0;j<M->num_cols;j++){
        long long int tempdet=1;
        for(int i=0;i<M->num_rows;i++){
            if(j-i<0){
                tempdet=tempdet*((M->data[i])[(j-i+M->num_cols)%(M->num_cols)]);
            }
            else{
                tempdet=tempdet*((M->data[i])[(j-i)%(M->num_cols)]);
            }
            
        }
        det=det-tempdet;
    }
    return det;
}

int main(int argc, char* argv[]) {
    int num_rows=3;// row size will be provided as the first arg
    int num_cols=3;// col size will be provided as the second arg
    // remaining row size * column size args will be the entries 
    // of the matrix in row major order

    Matrix* a = create_matrix(num_rows,num_cols);
    Matrix* b = create_matrix(2,4);

    
    for(int i=0;i<num_rows;i++){
        for(int j=0;j<num_cols;j++){
            int n;
            scanf("%d",&n);
            (a->data[i])[j]=n;
        }
    }
    print_matrix(a);
    // for(int i=0;i<num_rows;i++){
    //     for(int j=0;j<num_cols;j++){
    //         (b->data[i])[j]=3;
    //     }
    // }
    // print_matrix(b);

    long long int c;
    c=determinant(a);
    printf("%lld",c);
   // print_matrix(c);
    return 0;

}