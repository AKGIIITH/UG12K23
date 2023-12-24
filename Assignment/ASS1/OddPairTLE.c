#include<stdio.h>

int pow(int a,int b){
    int t=1;                  
    for(int i=0;i<b;i++){
        t=t*a;
    }
    // printf("%d\n",t);
    return t;
}
int main(){
    int n;
    scanf("%d",&n);

    int sum=0;

    int a[n];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int k=a[j+1];
                a[j+1]=a[j];
                a[j]=k;
            }
        }
    }
    for(int i=0;i<n;i++){
        sum=sum+(pow(-1,i))*(a[i]);
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",a[i]);
    // }
    if(sum>=0){
        printf("%d",sum);
    }
    else{
        printf("%d",-sum);
    }
}