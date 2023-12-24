#include<stdio.h>

int main(){

    int n=10;
    int a[10]={1,3,4,23,45,67,77,87,98,100};


    int l=0,r=n-1;
    int x=3;//To Find

    int flag=1;

    while(l<=r){
        int m=(l+r)/2;
        if(a[m]==x){
            printf("%d %s",m,"Yes");
            l=r+1;
            flag=0;
        }
        else if(a[m]>x){
            r=m-1;
        }
        else if(a[m]<x){
            l=m+1;
        }    
    }
    if(flag==1){
        printf("No");
    }

}