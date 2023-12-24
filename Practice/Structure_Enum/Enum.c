#include<stdio.h>

typedef enum Weekday {
    Sunday = 5, 
    Monday = 3, 
    Tuesday, 
    Wednesday = 2, 
    Thursday, 
    Friday, 
    Saturday
} Weekday;

//Enum is basically a  tool to define variabls with consecutive integers value
//But can be called with its tag only i.e. enum name newvarname= varmember;

enum Colour{
    Red,
    Yellow,
    Green,
};



int main() {
    // Weekday today = Saturday;;
    // printf("Day %d\n",today);
    // printf("Size of enum variable = %ld bytes", 
    //         sizeof(today));	
    enum Colour C;
    printf("%d",Red);
    if(C==0){
        printf("%d",Red);

    }

    

    return 0 ;
}