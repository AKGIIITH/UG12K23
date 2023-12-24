#include<stdio.h>

int zero(){
    return 0;
}
int one(){
    return 1;
}
int p(int t){
    printf("%d",t);
}
int main(){
    int n;
    scanf("%d\n",&n);

    int k;
    k=n;

    int t=zero();

    for(int i=zero();i<k;i=i+one()){
        int x;
        scanf("%d",&x);
        t=t^x;
    }

    p(t);
}
        
    
    
    