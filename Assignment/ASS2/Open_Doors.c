#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    if(n==1){
        printf("%d ",1);
    }
    else{
        for(long long int i=1;i*i<=n;i++){
            if(i*i<=n){
                printf("%lld ",i*i);
            }
        }
    }    
}   
 
