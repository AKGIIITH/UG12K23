#include<stdio.h>
int g;
int clockwise(int a[][g],int n){               //i0 [j0 j1 j2...jn-1]
    int k=a[0][0];                             //i1 [j0 j1 j2...jn-1]
    for(int j=0;j<n;j++){                      //i2 [j0 j1 j2...jn-1]       
        for(int i=0;i<n;i++){
            if(j==0 && i<n-1){  
                a[i][0]=a[i+1][0];             //in-1 [j0 j1 j2...jn-1]
            }

            else if(i==n-1 && j<n-1){
                a[i][j]=a[i][j+1];
            }
        }
    }
    for(int j=n-1;j>-1;j--){       
        for(int i=n-1;i>-1;i--){
            if(j==n-1 && i>0){     
                a[i][j]=a[i-1][j];
            }
            else if(i==0 && j>1){
                a[i][j]=a[i][j-1];    
            }
        }
    }
    a[0][1]=k;
}

int anticlockwise(int a[][g],int n){                 //i0 [j0 j1 j2...jn-1]
    int k=a[0][0];                                   //i1 [j0 j1 j2...jn-1]
    for(int j=0;j<n;j++){                            // :  :  :  
        for(int i=0;i<n;i++){                        //in-1 [j0 j1 j2...jn-1]
            if(i==0 && j<n-1){  
                a[i][j]=a[i][j+1];
            }

            else if(j==n-1 && i<n-1){
                a[i][j]=a[i+1][j];
            }
        }
    }
    for(int j=n-1;j>-1;j--){       
        for(int i=n-1;i>-1;i--){
            if(i==n-1 && j>0){     
                a[i][j]=a[i][j-1];
            }
            else if(j==0 && i>1){
                a[i][j]=a[i-1][j];    
            }
        }
    }
    a[1][0]=k;
}

int main(){
    int n;
    scanf("%d",&n);
    g=n;

    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int  k;
    scanf("%d",&k);
    if(k==1){
        clockwise(a,n);}
    else if(k==0){
        anticlockwise(a,n);}
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}