#include <stdlib.h>
#include<stdio.h>

typedef struct test{
    int data;
    struct test* nextpointer;
}t;

void append(t* mainpointer,t* nodepointer){
    while(mainpointer->nextpointer!=NULL){
        mainpointer=mainpointer->nextpointer;
    }
    mainpointer->nextpointer=nodepointer;
}

int main(){
    t* mainpointer=(t*)(malloc(sizeof(t)));
    t* temp=mainpointer;
    printf("Enter Data: ");
    scanf("%d",&(mainpointer->data));
    mainpointer->nextpointer=NULL;
    
    for(int i=0;i<3;i++){
        printf("\nEnter %d  data: ",i);
        t* nodepointer=(t*)(malloc(sizeof(t)));
        scanf("%d",&(nodepointer->data));
        nodepointer->nextpointer=NULL;
        append(mainpointer,nodepointer);
    }
    while(mainpointer->nextpointer!=NULL){
        printf("%d ",mainpointer->data);
        mainpointer=mainpointer->nextpointer;
    }
    mainpointer=mainpointer->nextpointer;

}