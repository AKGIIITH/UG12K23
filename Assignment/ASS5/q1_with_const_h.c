#include<stdio.h>

int main(){
    int n,h;
    scanf("%d %d",&n,&h);

    char s[100000];
    scanf("%s",s);

    int max=0;
    for(int i=0;i<n;i++){
        int count=0;
        if(s[i]==s[i+1] && s[i]!='%'){
            count=1;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i] && s[j]==s[j+1]){
                    count++;
                    j=j+2;
                    s[j]='%';
                    s[j+1]='%';
                }
            }
            s[i]='%';
            s[i+1]='%';
            if(count>max){
                max=count;
            }
        }
    }
    printf("%d",max);
}