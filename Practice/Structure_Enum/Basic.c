#include<stdio.h>
#include<string.h>
int main(){

    struct pokemon{
        int HP;
        float Speed;
        char owner[30];
    }Pikachu;

    //pokemon Pikachu;
    Pikachu.HP=50;
    strcpy(Pikachu.owner,"ASH");
    Pikachu.Speed=54.4;

    printf("%s",Pikachu.owner);

    struct pokemon Charizard;
    Charizard.HP=80;
    strcpy(Charizard.owner,"Ayush");
    printf("%s",Charizard.owner);
    printf("%d",Charizard.HP);


}