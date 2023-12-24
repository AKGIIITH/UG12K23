#include<stdio.h>
int Prime(int k){
    int j=2;
    int l=1;
    while(j<k){
        if(k%j==0){
            l=0;
            break;
        }
        else{
            j++;
        }

    }
    if(l==1){
        return k;
    }
    else{
        return 0;
    }

}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=2;i<=n;i++){
        int t;
        t=Prime(i);
        if(t!=0){
            printf("%d",t);
            printf(" ");

        }
        

    }


}