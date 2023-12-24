#include<stdio.h>
int n;
int storer[1000000];

int icounter(int a[],int index){
    int temp=index;
    if(storer[index]!=-1){
        return storer[index];
    }
    int sum=a[index];
    while(index<n){
        index=index+a[index];
        if(index<n){
            sum=sum+a[index];
        }
    }
    storer[temp]=sum;
    return sum;
}
int imax(int a[]){
    int max=0;
    for(int i=0;i<n;i++){
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
    scanf("%d",&x);
    int ans[x];
    for(int i=0;i<x;i++){
        scanf("%d",&n);
        int a[n];
        for(int j=0;j<n;j++){
            storer[j]=-1;
            scanf("%d",&a[j]);
        }
        ans[i]=imax(a);
    }
    for(int i=0;i<x;i++){
        printf("%d\n",ans[i]);
    }
}