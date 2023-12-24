#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);

    int up[100];
    int down[100];
    int Area=0;

    for(int k=0;k<100;k++){
        up[k]=0;
        down[k]=100;
    }

    for(int i=0;i<n;i++){
        int l1,l2,b1,b2;
        scanf("%d %d %d %d",&l1,&l2,&b1,&b2);

        for(int j=b1;j<b2;j++){
            if(l1>up[j] && up[j]!=0){
                Area=Area-(l1-up[j]);
            }
            if(l2<down[j] && down[j]!=100){
                Area=Area-(down[j]-l2);
            }
            if(l2>up[j]){
                up[j]=l2;
            }
            if(l1<down[j]){
                down[j]=l1;
            }
            
        }
    }
    
    for(int i=0;i<100;i++){
        if(up[i]-down[i]>0){
           Area=Area+(up[i]-down[i]);
        }
    }
    printf("%d",Area);
}