#include<stdio.h>
#include<string.h>
int main(){
    int quote=0;
    int n;
    scanf("%d",&n);
    char str[n];
    scanf("%s",str);

    for(int i=0;i<n;i++){
        if(quote%2==0){
            if(str[i]==','){
                str[i]='*';
            }
        }
        if(str[i]=='"'){
            quote++;
        }
    }
    printf("%s",str);
}