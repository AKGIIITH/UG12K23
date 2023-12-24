#include<stdio.h>
int main(){

    //Pointer to Pointer  (& is must)
    // int *ptr;
    // int **qtr;
    // int a=10;
    // ptr=&a;
    // qtr=&ptr;
    // printf("%d %d ",*ptr,**qtr);

    //Array of pointer
    // int a[4]={10,11,12,13};
    // int b[4]={20,21,22,23};
    // int *ptr[4];
    // for(int i=0;i<2;i++){
    //     ptr[i]=&a[i];
    // }
    // ptr[2]=&b[1];
    // int** qtr;       //Pointer to Pointer
    // qtr=&ptr[2];
    // for(int i=0;i<3;i++){
    //     printf("%d ",*ptr[i]);
    // }
    // printf("%d ",**qtr);


  
  
  
  
    // int a[5]={1,2,3,4,5};
    // int (*ptr)[2]; //Pointer to 1D Array
    // ptr=a;

    // printf("%d ",*(*(ptr)+2));




    //Pointer to 2D Array
    int b[3][4]={{1,2,3,4},
                  {5,6,7,8},
                {8,10,11,12}
                };

    int (*p)[3][4];
    p=b;
    printf("\n%d %d %d %d ",***(p+1),*(**p+1),**(*p+1),(p+1));

}
