#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n); 

    int a[n+1];
    a[0]=1;
    for(int i=1;i<n+1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n+1;i++){

        if(a[i]!=-1){
            int temp=a[i];
            for(int j=i;j<n+1;){
                if(a[j]==-1){
                    j=n+2;
                    if(temp!=1){
                        printf("->%d",temp);
                    }
                    // else{
                    //     printf("%d",temp);

                    // }
                }
                else{
                    if(a[i]==a[j]){
                        printf("%d",a[i]);
                    }
                    else{
                    printf("->%d",a[j]);
                    }
                    int temp=a[j];
                    a[j]=-1;
                    j=temp;
                    
                }
            }
            printf("\n");
        }

    }
}
