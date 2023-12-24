#include<stdio.h>
void Array_Cleaner(int a[][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            a[i][j]=0;    
        }
    }
}

int Area_Counter(int a[][100]){
    int t=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            t=t+a[i][j];    
        }
    }
    return t;
}

int main(){
    int a[100][100];
    Array_Cleaner(a);

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int l1,l2,b1,b2;
        scanf("%d %d %d %d",&l1,&l2,&b1,&b2);

        for(int k=l1;k<l2;k++){
            for(int m=b1;m<b2;m++){
                a[m][k]=1;  
            }    
        }
    }

    int t=Area_Counter(a);
    printf("%d",t);

}