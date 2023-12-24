#include<stdio.h>

int main(){
    int x;
    scanf("%d",&x);

    for(int i=0;i<x;i++){
        int n;
        scanf("%d",&n);
        int a[n];
        int copy[n];
        for(int i=0;i<n;i++){
            copy[i]=-1;
            scanf("%d",&a[i]);
        }
        int max=0;
        int flag=0;
        for(int j=n-1;j>=0;j--){
            max=0;
            int sum=0;
            if(copy[j]!=-1){
                printf("%d ",copy[j]);
                flag=1;
                
            }
            else{
                int k=j;
                while(k<n){
                    sum=sum+a[k];
                    copy[k]=sum;
                    k=k+a[k];
                    copy[j]=sum;
                }    
            }
            if(sum>max){
                    max=sum;
            }
        }
        if(flag==0){
            printf("%d ",max);
        }
        
    }
}