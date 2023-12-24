#include<stdio.h>

int pow(int a,int b){
    int t=1;                  //a^b
    for(int i=0;i<b;i++){
        t=t*a;
    }
    return t;
}


int main(){
    int n;
    scanf("%d",&n);

    int y=pow(2,n);

    int a[y];
    a[0]=0;
    a[1]=1;

    int  end=1;
    p=pow(2,1);

    for(int i=2;i<y;i++){
        a[i]=a[end-i]+p;
    }
}