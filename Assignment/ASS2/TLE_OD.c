#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j=j+i+1){
            if(a[j]==0){
                a[j]=1;
            }
            else  if(a[j]==1){
                a[j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]==1){
            printf("%d ",i+1);
        }
    }
}