#include<stdio.h>
#include<stdlib.h>

typedef struct number{
    float num;
    struct number* next;
}number;

void append(number* numb,number** store){
    if(*store==NULL){
        *store=numb;
    }
    else{
        number* temp=*store;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=numb;
    }
}


int main(){
    number* store=NULL;
    printf("%d",store->next);
    
    // number* numb=(number*) malloc(sizeof(number));
    // float input;
    // scanf("%f",&input);
    // numb->num=input;
    // numb->next=NULL;
    // append(numb,&store);
    // printf("%f",store->num);

}
//q: Why Segmentation Fault?
