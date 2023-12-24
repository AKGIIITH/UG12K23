#include<stdio.h>
#include<string.h>
char* str_rev(char* str){
    int len=strlen(str);

    for(int i=0;i<len;i++){
        len--;
        char temp=str[len];
        str[len]=str[i];
        str[i]=temp;
    }
    return str;
}
int main(){
    char test[]="Ayush Kumar Gupta was here!!!";
    printf("%s",str_rev(test));
}