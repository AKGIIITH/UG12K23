#include<stdio.h>

int check(int** soduko,int row,int col,int n,int match){
    int valid[n];
    for(int i=0;i<n;i++){
        valid[i]=i+1;
    }
    int row_check=1;
    int col_check=1;
    int block_check=1;

    for(int j=0;j<n;j++){
        if(j==col){
            continue;
        }
        else if(soduko[row][j]==match){
            return 0;
        }
    }
    for(int j=0;j<n;j++){
        if(j==row){
            continue;
        }
        else if(soduko[j][row]==match){
            return 0;
        }
    }
    
}

int** soduko(int** souduko){
    for(int i=0)
} 

int main(){
    int n;
    scanf("%d",&n);
    int** rows=(int**) calloc(n,sizeof(int*));
    for(int i=0;i<n;i++){
        int* cols=(int*) calloc(n,sizeof(int));
        rows[i]=cols;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp;
            scanf("%d",&rows[i][j]);
        }
    }

    int valid[4]={1,2,3,4};

}