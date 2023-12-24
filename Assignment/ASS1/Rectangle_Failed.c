#include<stdio.h>
int main(){
    int l,b;
    scanf("%d %d",&l,&b);

    int i=0;
    int j=0;

    while(i<l){
        while(j<b){
            if((i==0 &&j==0) || (i==0 && j==l) || (i==b && j==0) || (i==l && j==b)){
                printf("o");
            }

            else if(i==0 || i==b){
                printf("-");
            }

            else if(j==0 || j==l){
                printf("|");
            }
            j++;
            else
            printf("\n")
        }
        printf("")
        i++;
    }
}