#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    
    long long int k=1;
    int z=0,o=0;
    for(int i=0;i<n;i++){
        long long int x;
        scanf("%lld",&x);

        if(x==0){
            z=z+1;
        }
        else if(x==1){
            o=o+1;
        }
        else{
            if(k%x==0){
                k=k/x;
            }
            else{
                k=k*x;
            }
        }
    }

    if(z%2!=0){
        printf("%d",0);
    }
    else if(o%2!=0){
        printf("%d",1);
    }
    else{
        printf("%lld",k);
    }

}