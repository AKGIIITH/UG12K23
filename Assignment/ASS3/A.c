#include<stdio.h>
int arr[1000];
int find(int a,int k,int l);
int main(){
    int n;
    int q;
    scanf("%d",&q);
    int brr[q];
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<q;j++){
        scanf("%d",&brr[j]);
        find(brr[j],0,n-1);
    }
    
}
int find(int a,int k,int l){
    int b=(k+l)/2;
    
    if(a>arr[l]){
        printf("%d ",l+1);
    }
    else if(a<=arr[k]){
        printf("%d ",k);
    }
    else if(arr[b]<=a){
        find(a,b+1,l);
    }
    else {
        find(a,k,b-1);
    }
}