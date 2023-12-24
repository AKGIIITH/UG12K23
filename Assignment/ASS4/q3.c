#include<stdio.h>
#include<stdlib.h>

typedef struct colour{
    int colourno;
    struct colour* next;
}colour;

void appenduniquely(colour* maincolour,colour* nodecolour){
    while(maincolour->next!=NULL){
        maincolour=maincolour->next;
    }
    if(maincolour->colourno!=nodecolour->colourno){
        maincolour->next=nodecolour;
    }
}

int main(){
    int n;  
    printf("Enter the number of colors in the list: ");
    scanf("%d",&n);

    printf("\nEnter the Colors: ");
    colour* maincolour=(colour*)(malloc(sizeof(colour)));
    scanf("%d",&(maincolour->colourno));
    maincolour->next=NULL;
    
    for(int i=1;i<n;i++){        
        colour* nodecolour=(colour *)malloc(sizeof(colour));
        scanf("%d",&(nodecolour->colourno));
        nodecolour->next=NULL;

        appenduniquely(maincolour,nodecolour);   
    }
    
    printf("\nModified Linked List: ");
    while(maincolour->next!=NULL){
        printf("%d->",maincolour->colourno);
        maincolour=maincolour->next;
    }
    printf("%d",maincolour->colourno);
    
    //gdb
    //assert statement
    //g++ -fsanitize=address -fsanitize=undefined -Wall -Wpedantic -Wundef q3.c
    //11
// 3 3 3 7 7 8 9 10 11 11 11
}