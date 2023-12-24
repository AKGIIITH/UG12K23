#include<stdio.h>
#include<string.h>

void strcpyf(char a[],char b[]){
    int i=0;
    while(b[i]!='\0'){
        a[i]=b[i];
        i++;
    }
}

int main(){
    //Pointers always take 8 bits, so string pointer does not give no. of char
    char *p = "abcd\0hsh";
    char s[] = "aouoj\0ayush\0";
    printf("%ld %ld\n", sizeof(p), sizeof(s));
    printf("%ld %ld\n", strlen(p), strlen(s));

    //Testing strcpyf
    // char a[6]="ayush";
    // char b[6]={'g','r','e','e','n','\0'};
    // strcpyf(a,b);
    printf("%s\n %s",p,s);
}

