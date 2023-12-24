#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);

    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    int reverse_sum=0;
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=n-1;j>-1;j--){
            while(sum=reverse_sum ){
                sum=sum+a[i];
                reverse_sum=reverse_sum+a[j];
            }
            if(sum=reverse_sum && i==j){
                count++;
            }
            sum=0;
            reverse_sum=0;
        }

    }
    printf("%d ",count);
}