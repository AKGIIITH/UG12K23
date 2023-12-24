#include<stdio.h>
#include<string.h>
int  main(){
    typedef struct Pokemon{
        char name[30];
        int level;
        int power;
    }P;

    P GrassType[3];
    strcpy(GrassType[0].name,"Bulabasour");
    GrassType[0].level=70;
    GrassType[0].power=90;

    strcpy(GrassType[1].name,"Venusaur");
    GrassType[1].level=50;
    GrassType[1].power=80;

    strcpy(GrassType[2].name,"Megasaur");
    GrassType[2].level=60;
    GrassType[2].power=100;

    for(int i=0;i<3;i++){
        printf("%s\t %d\t %d\n",GrassType[i].name,GrassType[i].level,GrassType[i].power);
    }



}