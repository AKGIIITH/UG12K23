#include<stdio.h>
int main(){
    int investment=0;
    int n;
    scanf("%d",&n);

    while(n>0){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=n-1;
            investment++;
        }
    }

    printf("%d",investment);
}