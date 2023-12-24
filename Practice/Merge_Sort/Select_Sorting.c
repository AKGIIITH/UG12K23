#include<stdio.h>

int ssort(int a[],int n){
    for(int i=0;i<n;i++){
        int temp=a[i];
        for(int j=i;j<n;j++){
            if(a[j]<temp){
                int t;
                t=temp;
                temp=a[j];
                a[j]=t;
            }
            a[i]=temp;
        }
    }

    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }

}
int main(){
    // Selection Sort
    int b[5]={1,5,3,4,6};
    int n;
    n=sizeof(b)/sizeof(b[0]);
    ssort(b,n);
    // a[5]=ssort(a);
    // for(int i=0;i<5;i++){
    //     printf("%d",a[i]);
    // }
    

}