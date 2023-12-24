#include<stdio.h>
#include<string.h>

void bchecker(char s[],int len){
    int temp[len];
    int repeat=1;
    int lowercase=0;
    int uppercase=0;

    for(int i=0;i<len;i++){
        temp[i]=(int)(s[i]);
        for(int j=0;j<i-1;j++){
            if(temp[j]==temp[i]){
                repeat=0;
            }
        }
        if(temp[i]>=97){
            lowercase=1;
        }
        if(temp[i]<97){
            uppercase=1;
        }
    }
    if(lowercase & uppercase & repeat){
        printf("Yes");
    }
    else{
        printf("No");
    }

}

int main(){
    char s[100];
    scanf("%s",s);

    int len;
    len=strlen(s);
    bchecker(s,len);
}