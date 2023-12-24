#include<stdio.h>
int main(){
    int a,b;
    scanf("%d\n%d",&a,&b);

    int c=0;
    int i=0;
    int arr[32];

    while(a>0 || b>0 ||c>0){
        int x,y;
        x=a%10;
        a=a/10;
        y=b%10;
        b=b/10;

        int s;
        s=x^y^c;
        c=(x&y&c)%10;
        arr[i++]=s;

    }
    arr[i]=1;
    for(int j=i;j>-1;j--){
        printf("%d",arr[j]);
    }


}