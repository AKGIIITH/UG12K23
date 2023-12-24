#include<stdio.h>
int Pallindrome_Checker(int a[],int p,int q){
    int k=0;
    if(a[p]==a[q] && p<q){
        k=Pallindrome_Checker(a,p+1,q-1);
    }
    else if((a[p]==a[q] && p==q)){
        return 1;
    }
    else if(p>q){
        return 1;
    }
    else{
        return 0;
    }
    

    if(k==1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int a[n];
    int count=0;

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            count=count+Pallindrome_Checker(a,i,j);
            // printf("\n%d %d %d",i,j,count);
        }
    }
    printf("%d",count);
}