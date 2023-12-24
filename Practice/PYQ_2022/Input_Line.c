#include<stdio.h>
#include<stdlib.h>
int main(){
    // for(int i=0;i<3;i++){
    //     // char* given=(char*)(malloc(256*sizeof(char)));
    //     // scanf("%[^\n]*s",given);
    //     // printf("%s",given);
    //     int count=0;
    //     char* str=(char*)(malloc(sizeof(char)*1e5));
    //     char character;
    //     scanf("%c",&character);
    //     str[count]=character;
    //     count++;
    //     while(character!='\n'){
    //         scanf("%c",&character);
    //         if(character=='\0'){
    //             str[count]='_';
    //         }
    //         else{
    //             str[count]=character;
    //         }  
    //         count++;
    //     }
    //     str[count]='\0';
    //     printf("%s",str);
    // }
    for(int i=0;i<2;i++){
        char* given=(char*)(malloc(256*sizeof(char)));
        scanf("%[^\n]%*c",given);
        printf("%s",given);
    }
}