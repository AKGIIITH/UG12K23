#include<stdio.h>
int n;
int storer[1000000];

int icounter(int a[],int index){
    if(storer[index]!=-1){
        return storer[index];
    }
    int sum=0;
    while(index<n){
        sum=sum+a[index];
        storer[index]=sum;
        index=index+a[index];
    }

    
    return sum;
}
int imax(int a[]){
    int max=0;
    for(int i=n-1;i>=0;i--){
        int k;
        k=icounter(a,i);
        if(k>max){
            max=k;
        }
    }
    return max;
}

int main(){
    int x;
    scanf("%d",&x);//No. of time
    for(int i=0;i<x;i++){//Loop times
        scanf("%d",&n);//No. of elemnet
        int a[n];
        for(int j=0;j<n;j++){
            storer[j]=-1;
            scanf("%d",&a[j]);
        }  
        printf("%d" ,imax(a));
    }
}