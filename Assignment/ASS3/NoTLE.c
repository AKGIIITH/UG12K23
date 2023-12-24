#include<stdio.h>
int n,m,k; //Global

void arraycleaner(int arr[n+2][m+2]){ //Working which turns each element of array to 0 
    for(int i=0;i<n+2;i++){
        for(int j=0;j<m+2;j++){
            if(i==n-1){
                arr[i][j]=1;
            }
            else{
                arr[i][j]=0;
            }    
        }
    }
}
void minnions(int arr[n+2][m+2]){ //Takes Forbidden Squares
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr[x-1][y-1]=-1;
    }
}

int pathcounter(int arr[n+2][m+2],int x,int y){
    int TP;
    if(arr[x][y]==-1 || x>=n || y>=m || y<0 ||x<0){ //Forbidden Factors
        return 0;
    }
    else if(arr[x][y]!=0){
        return (arr[x][y]);
    }
    else{
        int LD=pathcounter(arr,x+1,y-2);   //LD
        int DR=pathcounter(arr,x+2,y+1);   //DR
        int RD=pathcounter(arr,x+1,y+2);   //RD
        int DL=pathcounter(arr,x+2,y-1);   //DL
        TP=LD+DR+RD+DL;
    }
    if(arr[x][y]==0){
        arr[x][y]=TP%1000000007;
    }
    return(TP%1000000007);
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    int a[n+2][m+2];
    arraycleaner(a);
    minnions(a);

    for(int i=0;i<m;i++){
        int paths=pathcounter(a,n-1,i);
        printf("%d ",paths);
    }
    
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",(a[i][j]));
        }
        printf("\n");
    }
}