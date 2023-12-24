#include <stdio.h>

int* inc(int *a){
    for(int i=0;i<3;i++){
        a[i]++;
    }
    return a;
}
 
int main()
{
    int arr[3]={1,2,3};
    int (*p)[3];
    p=inc(arr);

    for(int i=0;i<3;i++){
        printf("%d ",*(*p+i));
    }
 
}
