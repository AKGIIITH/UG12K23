#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int a[n+1];
    a[0]=1;

    for(int i=1;i<n+1;i++){
        scanf("%d",&a[i]);
    }

    int count=1;
    int store=count;
    //printf("%d->",a[0]);
    for(int i=1;i<n+1;i++){
        if(a[i]==count){
            printf("%d",a[i]);
            for(int j=a[i];j<n+1;){
                printf("->%d",a[j]);
                if(a[j]==count){
                    j=n+2;
                }
                else{
                    j=a[j];
                }
               
                
            }
            printf("\n");
            count++;
        }

    }

}