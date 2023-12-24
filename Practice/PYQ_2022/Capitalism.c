#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// char* gets(){
//     char character;
//     int count=0;
//     scanf("%c",&character);
//     character=getchar();
//     char* line=(char*)malloc(256* sizeof(char));
//     while(character!='\n'){
//         if(character=='\0'){
//             line[count]=' ';
//         }
//         else{
//         line[count]=character;
//         }
//         count++;
//     }
//     return line;
// }
char* gets(){
    // for(int i=0;i<3;i++){
        // char* given=(char*)(malloc(256*sizeof(char)));
        // scanf("%[^\n]*s",given);
        // printf("%s",given);
        int count=0;
        char* str=(char*)(malloc(sizeof(char)*1e5));
        char character;
        scanf("%c",&character);
        str[count]=character;
        count++;
        while(character!='\n'){
            scanf("%c",&character);
            if(character=='\0'){
                str[count]='_';
            }
            else{
                str[count]=character;
            }  
            count++;
        }
        str[count]='\0';
        //printf("%s",str);
        return str;
    //}
}
int main(){
    int n;
    scanf("%d",&n);

    char capital[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";

    char* given;
    given=gets();
    for(int i=0;i<n;i++){
        int count=0;
        // scanf("%s",given);
        //scanf("%[^\n]s", given);
        // while(given[strlen(given)]!='\n'){
        //     char* temp=(char*) malloc(256*(sizeof(char)));
        //     scanf("%s",temp);
        //     strcat(given,temp);
        // }
        given=gets();
        int len=strlen(given);
        for(int j=0;j<len;j++){
            for(int k=0;k<26;k++){
                if(capital[k]==given[j]){
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
}