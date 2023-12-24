#include<stdio.h>
typedef struct Linked_List{
    int number;
    struct Linked_List* next;
    int cycle;
}Linked_List;

int main(){
    int n;
    scanf("%d",&n);

    Linked_List* Normal=(Linked_List*) malloc(sizeof(Linked_List));
    Linked_List* Temp=Normal;
    for(int i=0;i<n;i++){
        scanf("%d",&Temp->number);
        Temp->cycle=0;
        Linked_List* Normal=(Linked_List*) malloc(sizeof(Linked_List));
                    
    }

}