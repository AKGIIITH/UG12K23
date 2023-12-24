#include<stdio.h>
typedef struct data{
    char name[10];
    int age;
}d;

typedef struct node{
    d details;
    struct node* address;
}n;

void printlist(n* List){
    while((*List).address!=NULL){
        printf("%s\t%d\n",(*List).details.name,(*List).details.age);
        List=(*List).address;
    }
    printf("%s\t%d\n",(*List).details.name,(*List).details.age);
}
int size(n*List){
    int s=1;
    while((*List).address!=NULL){
        s++;
        List=(*List).address;
    }
    return s;
}
void append(n* List,n* anode){
    while(List->address!=NULL){
        List=List->address;
    }
    List->address=anode;
}
void insert(n*List, int pos ,n* anode){
    pos=pos-2;
    while(pos>0){
        List=List->address;
        pos--;
    }
    n*temp=List->address;
    List->address=anode;
    anode->address=temp;

}
void concatenate(n*List,n*List2){
    while(List->address!=NULL){
        List=List->address;
    }
    List->address=List2;
}
void reverse(n*List){
    n* arr[];
    int i=1;
    while(List->address!=NULL){
        arr[i]=List;
        \

        ''
    }

    n*temp=List->address;
    List->address=NULL;
}

int main(){
    n node3={{"Ayush",18},NULL};
    n node2={{"Kang",35},&node3};
    n node1={{"Loki",30},&node2};
    n* List1=&node1;

    n cnode3={{"Guard",1000},NULL};
    n cnode2={{"Silvey",35},&cnode3};
    n cnode1={{"Mobius",30},&cnode2};
    n* List2=&cnode1;

    n a={{"Added",0},NULL};
    n* anode=&a;
    // append(List1,anode);
    // insert(List1,2,anode);
    concatenate(List1,List2);







    printlist(List1);
    //printf("\n%d",size(List1));









}