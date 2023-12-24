#include<stdio.h>
int main(){
    int x,y,n;
    scanf("%d %d %d",&n,&x,&y);
    int z;
    if(n>=1){
        printf("%d ",x);
    }
    if(n>=2){
        printf("%d ",y);
    }
    for(int i=2;i<n;i++){
        z=x+y;
        printf("%d ",z);
        x=y;
        y=z;
    }
}