#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(char* argv[]){
    printf("Enter Input: ");
    double k;
    //scanf("%d",&k);
    //printf("%d %d",k,argv[1]);

    char*ptr;

    k=strtod(argv[1],&ptr);
    printf("\n%lf",500-k);
}