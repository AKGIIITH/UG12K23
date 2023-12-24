#include<stdio.h>
#include<string.h>

int main(){
    char string[2000];
    scanf("%s",string);
    int n=strlen(string);

    char comp[1000];
    strcpy(comp,string);

    char max[1000];
    strcpy(max,string);


    strncat(string,string,n);
    for(int i=0;i<n;i++){
        if((strncmp(&string[i],comp,n))<0){
            strncpy(comp,&string[i],n);
        }
        if((strncmp(&string[i],max,n))>0){
            strncpy(max,&string[i],n);
        }
    }


    printf("%s\n%s",comp,max);

}