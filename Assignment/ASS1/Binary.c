#include<stdio.h>

int pow(int a,int b){
    int t=1;                  //a^b
    for(int i=0;i<b;i++){
        t=t*a;
    }
    // printf("%d\n",t);
    return t;
}

int max(int n){
    int x=1,c=1;
    while(x<=n){
        x=pow(2,c);
        c++;
    }
    // printf("%d\n",c);
    return c-2;

}
int main(){

    int n;
    scanf("%d",&n);

    if(n==0){
        printf("%d",0);
    }

    

    while(n>0){
        int d,e;
        d=max(n);
        n=n-pow(2,d);
        e=max(n);
        
        printf("%d",1);
        for(int i=1;i<(d-e);i++){
            printf("%d",0);
        }
    }
        

        
}


