#include"matrix.h"

int main(int argc, char* argv[]) {
    int num_rows=2;// row size will be provided as the first arg
    int num_cols=2;// col size will be provided as the second arg
    // remaining row size * column size args will be the entries 
    // of the matrix in row major order

    Matrix* m = create_matrix(num_rows,num_cols);
    
    for(int i=0;i<num_rows;i++){
        for(int j=0;j<num_cols;j++){
            (m->data[i])[j]=1;
        }
    }
    print_matrix(m);
    return 0;

}