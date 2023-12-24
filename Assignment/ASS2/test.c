#include<stdio.h>
void Array_Cleaner(int a[][100]){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            a[i][j]=0;    
        }
    }
}

void Rectangle_Printer(int a[][100]){
    for(int j=0;j<10;j++){
        for(int i=0;i<10;i++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
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

        for(l1;l1<=l2;l1++){
            for(b1;b1<=b2;b1++){
                a[b1][l1]=1;  
            }    
        }
    }
    Rectangle_Printer(a);

    int k=Area_Counter(a);
    printf("\n%d",k);

    

}