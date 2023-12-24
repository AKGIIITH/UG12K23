#include<stdio.h>

int main(){
    typedef struct p{
        char name[10];
        int age;
        int ID;
    }biodata;
    
    typedef struct HT{
        biodata data;
        struct HT *addressnext;
    }Node;

    //Storing value
    Node Third={{"Ayush",18,4001},NULL};
    Node Second={{"Loki",40,4069},&Third};
    Node First={{"Silvy",36,9604},&Second};

    Node *List=&First;

    Node T={{"Liquid",100,001},NULL};
    Node S={{"Solid",200,002},&T};
    Node G={{"Gas",300,003},&S};
    Node* State=&G;

    //Size
    // int sze(Node* L){
    //     int s=0;
    //     while(L!=NULL){
    //         s++;
    //         L=((*L).addressnext); //*L.member=L->member
    //         /*We can say that pointer point to member value*/       
    //     }
    //     return s;
    // }
    // printf("%d\n",sze(List));

    //Insert at position
    // void insert(Node*L,int pos,biodata add){
    //     for(int i=0;i<pos-2;i++){
    //         L=L->addressnext;
    //     }
    //     Node temp={add,L->addressnext};
    //     L->addressnext=&temp;
    // }
    // biodata Nsecond={"Kang",67,9008};
    // insert(List,2,Nsecond);

    //Append Element
    // void append(Node*L,Node* appendi){
    //     while((L->addressnext)!=NULL){
    //         L=L->addressnext;
    //     }
    //     L->addressnext=appendi;
    // }
    // Node pappend={{"Kangu",25,0001},NULL};
    // Node *Pointer=&pappend;
    // append(List,Pointer);

    //Concatenate two linked list
    // void concatn(Node*L,Node*A){
    //     while(L->addressnext!=NULL){
    //         L=L->addressnext;
    //     }
    //     L->addressnext=A;
    // }
    // concatn(List,State);

    // void Reverse(Node*L){
    //     Node * p=L;
    //     Node * n=L->addressnext;
    //     L->addressnext=NULL;
    //     L=n;
        
    //     while(L->addressnext!=NULL){
    //         n=L->addressnext;
    //         L->addressnext=p;
    //         p=L;
    //         L=n;
    //     }
    //     L->addressnext=p;
    //     p=L;
    // }
    // Reverse(List);
    
    //Shuffle
    // void shuffle(Node*L,Node*T){
    //     while(T->addressnext!=NULL){
    //         Node * Ltemp=L->addressnext;
    //         Node * Ttemp=T->addressnext;
    //         L->addressnext=T;
    //         T->addressnext=Ltemp;
    //         L=Ltemp;
    //         T=Ttemp;
    //     }
    //     L->addressnext=T;
    // }
    // shuffle(List,State);
    
    //Linked List Insert
    //Use Malloc, Node*D=(Node*) malloc(sizeof(Node));
    //D->Data and D->Next=L->List; return D;
    /*else{
        l->next=insert(p,pos-1,l->next);
        return l;
    }*/


    //Prints Linked List
    void printer(Node* L){
        while(L!=NULL){
            printf("%s\t%d\t%d\n",L->data.name,L->data.age,L->data.ID);
            L=L->addressnext;
        }
    }
    printer(List);
}