#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);

    int c=1;
    int b1=0;
    int b2=0;
    int b3=0;

    int j=0;
    while(n>0 && j<9){
        int r;
        r=n%2;
        n=n/2;
        
        for(int i=1;i<c;i++){
            r=r*10;
        }
        
        
        c++;
        j++;

        b1=b1+r;
    }

    j=0;
    c=1;
    while(n>0 && j<9){
        int r;
        r=n%2;
        n=n/2;
        
        for(int i=1;i<c;i++){
            r=r*10;
        }
        c++;
        j++;

        b2=b2+r;
    }


    j=0;
    c=1;
    while(n>0 && j<9){
        int r;
        r=n%2;
        n=n/2;
        
        for(int i=1;i<c;i++){
            r=r*10;
        }
        c++;
        j++;

        b3=b3+r;
    }

    printf("%.9d%.9d%.9d",b3,b2,b1);
}