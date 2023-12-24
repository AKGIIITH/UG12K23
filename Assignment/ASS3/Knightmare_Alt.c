#include<stdio.h>
int n,m,k,path; //Global

void arraycleaner(int arr[n][m]){ //Working which turns each element of array to 0 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=0;
        }
    }
}
void minnions(int arr[n][m]){ //Takes Forbidden Squares
    for(int i=0;i<k;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr[x-1][y-1]=-1;
    }
}
void pathcounter(int arr[n][m],int x,int y){
    if(arr[x][y]==-1 || x>=n || y>=m || y<0){ //Forbidden Factors
        
    }
    else if(x==n-1){
        path++;
    }
    else{
       
        pathcounter(arr,x+2,y-1);   //DL
        pathcounter(arr,x+2,y+1);   //DR
        pathcounter(arr,x+1,y-2);   //LD
        pathcounter(arr,x+1,y+2);   //RD
        
    }
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    int a[n][m];
    arraycleaner(a);
    minnions(a);

    int noofpath[m];
    for(int i=0;i<m;i++){
        path=0;
        pathcounter(a,0,i);  //1,i
        noofpath[i]=path;
    }

    for(int i=0;i<m;i++){
        printf("%d ",noofpath[i]%1000000007);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",(a[i][j]));
        }
        printf("\n");
    }
    /*4 5 3
    2 2
    3 3
    4 4 */
}