#include<stdio.h>

int* samerger(int* g,int* f,int len){
    int temp[len];
    int h=0,d=0;
    for(int i=0;i<len;i++){   
        if(g[h]<=f[d]){
            temp[i]=g[h];
            h++;
        }
        else{
            temp[i]=f[d];
            d++;
        }
    }
    return temp;
}

int* mergesort(int a[],int l,int u){
    if(u-l==1){
        int k[1];
        k[0]=a[l];
        return k; 
    }
    else{
        int *k,*s;
        k=mergesort(a,l,u/2);
        s=mergesort(a,u/2+1,u);

        int len=(u-l);
        return samerger(k,s,len);
    }
}

int main(){
    int a[]={2,67,84,34,56,78};
    int*p;
    p=mergesort(a,0,6);
    for(int i=0;i<3;i++){
        printf("%d ",p[i]);
    }
}