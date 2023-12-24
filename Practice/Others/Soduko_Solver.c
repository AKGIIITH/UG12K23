#include<stdio.h>
int row_check(int** arr,int number,int row,int order){
    for(int j=0;j<order;j++){
        if(arr[row][j]==number){
            return -1;
        }
    }
    return number;
}
int col_check(int** arr,int number,int col,int order){
    for(int i=0;i<order;i++){
        if(arr[i][col]==number){
        return -1;
    }
    return number;
}
int square_check(int** arr,int number,int order,int row,int col){
    int init=(row/order)*

}
int main(){

}