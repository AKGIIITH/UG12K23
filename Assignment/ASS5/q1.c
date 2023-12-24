#include<stdio.h>
#include<string.h>
int main(){
    int n,h;
    scanf("%d %d",&n,&h);

    char str[100001];
    scanf("%s",str);

    int max_iterations=0;
    char alpha[27]="abcdefghijklmnopqrstuvwxyz";

    int iterations=0;
    for(int i=0;i<26;i++){
        if(iterations>max_iterations){
            max_iterations=iterations;
        }
        iterations=0;

        char check=alpha[i];
        int count=0;
        for(int j=0;j<strlen(str);j++){
            if(count==h){
                iterations++;
                count=0;
            }
            if(str[j]==check){
                count++;
            }
            else{
                count=0;
            }

        }
        if(count==h){
            iterations++;
        }
    }
    if(iterations>max_iterations){
        max_iterations=iterations;
    }
    printf("%d",max_iterations);
}