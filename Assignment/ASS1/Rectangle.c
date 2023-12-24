#include<stdio.h>
int main(){
    int l,b;
    scanf("%d %d",&l,&b);

    if(l==1 && b==1){
       printf("o");
    }

    else if(l==1 && b>1){
        printf("o\n");
        for(int i=0;i<(b-2);i++){
            printf("|\n");
        }
        printf("o");
    }

    else if(l>1 && b==1){
        printf("o");
        for(int i=0;i<(l-2);i++){
            printf("-");
        }
        printf("o");
        
    }

    else{
        printf("o");
        for(int i=0;i<(l-2);i++){
            printf("-");
        }
        printf("o\n");

        for(int i=0;i<(b-2);i++){
            printf("|");
            for(int i=0;i<(l-2);i++){
                printf(" ");
            }
            printf("|\n");
            
        }

        printf("o");
        for(int i=0;i<(l-2);i++){
            printf("-");
        }
        printf("o");

        return 0;
    }


}