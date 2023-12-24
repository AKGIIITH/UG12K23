#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>


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
        printf("ERROR: INVALID ARGUMENT");
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
        printf("ERROR: INVALID ARGUMENT");
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

Matrix* cofactor(Matrix* M,int column){
    Matrix* C=create_matrix(M->num_rows-1,M->num_cols-1);
    for(int i=1;i<M->num_rows;i++){
        for(int j=0;j<M->num_cols-1;j++){
            if(j<column){
                (C->data[i-1])[j]=(M->data[i])[j];
            }
            else{
                (C->data[i-1])[j]=(M->data[i])[j+1];
            }
        }
    }
    return C;
}

long long int determinant(Matrix* M) {
    if(M->num_cols!=M->num_rows){
        printf("ERROR: INVALID ARGUMENT");
        return 0;
    }
    if(M->num_rows==1){
        return (M->data[0][0]);
    }
    
    long long int det=0;
    if(M->num_rows==3 || M->num_rows==2){
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
    
    else{
        long long int tempdet=0;
        for(int i=0;i<M->num_cols;i++){
            if(i%2==0){
                tempdet=tempdet+((M->data[0])[i])*determinant(cofactor(M,i));
            }
            else{
                tempdet=tempdet-((M->data[0])[i])*determinant(cofactor(M,i));
            }   
        }
        return tempdet;
    }
    
}


Matrix* input_matrix(Matrix* M){
    for(int i=0;i<M->num_rows;i++){
        for(int j=0;j<M->num_cols;j++){
            scanf("%lld",&((M->data[i])[j]));
        }
    }
    return M;
}

Matrix* read_matrix_from_file(FILE* file){
    if(file==NULL){
        printf("ERROR: INVALID ARGUMENT");
        return NULL;
    }
    else{
        int num_rows;
        int num_cols;
        fscanf(file,"%d %d",&num_rows,&num_cols);
        Matrix* M=create_matrix(num_rows,num_cols);
        for(int i=0;i<M->num_rows;i++){
            for(int j=0;j<M->num_cols;j++){
                fscanf(file,"%lld ",&((M->data[i])[j]));
            }
        }
        //print_matrix(M);
        //printf("%d %d",num_rows,num_cols); 
        return M;
    }
}

Matrix* write_matrix_to_file(FILE* file,Matrix* M){
    fprintf(file,"%d %d\n",M->num_rows,M->num_cols);
    for(int i=0;i<M->num_rows;i++){
        for(int j=0;j<M->num_cols;j++){
            fprintf(file,"%lld ",((M->data[i])[j]));
        }
        fprintf(file,"\n");
    }
}
