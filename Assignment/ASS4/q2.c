#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct number{
    float num;
    struct number* next;
}number; //Number is a node that contains a number and address to next Number Node

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
    char* cmd;
    while(strcmp("-1",cmd)!=0){
        printf("\n>-1 and Y to Exit the Program.\n");
        printf(" >Command opeerator: add,sub,dot,cosine to perform function\tEnter Complexity of no.\n >Type Nos:\n>>");
        
        
        int n;
        scanf("%s %d",cmd,&n);
        //

        printf(">>");
        number* store=NULL; 
        for(int i=0;i<n;i++){
            number* numb=(number*) malloc(sizeof(number));
            float input;
            scanf("%f",&input);
            numb->num=input;
            numb->next=NULL;
            append(numb,&store);
        }
        printf(">>");

        number* store2=NULL; 
        for(int i=0;i<n;i++){
            number* numb2=(number*) malloc(sizeof(number));
            float input;
            scanf("%f",&input);
            numb2->num=input;
            numb2->next=NULL;
            append(numb2,&store2);
        }

        void add(){
            for(int i=0;i<n;i++){
                float n1=store->num;
                float n2=store2->num;
                printf("%.2f ",n1+n2);
                store=store->next;
                store2=store2->next;
            }
        }

        void sub(){
            for(int i=0;i<n;i++){
                float n1=store->num;
                float n2=store2->num;
                printf("%.2f ",n1-n2);
                store=store->next;
                store2=store2->next;
            }
        }

        float sum=0;
        void dot(){
            number* temp1=store;
            number* temp2=store2;

            for(int i=0;i<n;i++){
                float n1=temp1->num;
                float n2=temp2->num;
                sum=sum+(n1*n2);
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }

        float mod(number* str){
            float sum=0;
            for(int i=0;i<n;i++){
                float n1=str->num;
                sum=sum+((n1)*(n1));
                str=str->next;    
            }
            sum=abs(sqrt(sum));
            return sum;
        }
        
        void cosine(){
            dot();
            float temp=mod(store);
            float temp2=mod(store2);
            sum=sum/temp;
            sum=sum/temp2;
            printf("%f",sum);
        }
        
        if(strcmp("add",cmd)==0){
            printf("Result:");
            add();
            printf("\n");
        }
        else if(strcmp("sub",cmd)==0){
            printf("Result:");
            sub();
        }
        else if(strcmp("dot",cmd)==0){
            printf("Result:");
            dot();
            printf("%f",sum);
            printf("\n");
        }
        else if(strcmp("cosine",cmd)==0){
            printf("Result:");
            cosine();
            printf("\n");
        }
        else{
            printf("Exiting...");
            printf("\n");
        }
    }
}
// ADD 5
// 1 2 3 4 5 
// 1 1 1 1 1
// SUB 5
// 1 2 3 4 5 
// 1 1 1 1 1 
// DOT 3
// 2 3 4 
// 1 -1 -1 
// COSINE 4    
// 1 1 1 1 
// 2 2 2 2
// -1