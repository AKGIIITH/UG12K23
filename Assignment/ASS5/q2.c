#include<stdio.h>
#include<string.h>

void strrev(char str[]){
    int n=strlen(str);
    for(int i=0;i<n/2;i++){
        char temp;
        temp=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=temp;
    }
}
// void strocat(char str[],char s[]){
//     int n=strlen(str);
//     int sn=strlen(s);
//     for(int i=0;i<sn;i++){
//         str[n+i]=s[i];
//     }
// }


int main(){
    char str[300001];
    scanf("%s",str);

    int M;
    scanf("%d",&M);

    for(int i=0;i<M;i++){
        int q;
        scanf("%d",&q);
        if(q==1){
            strrev(str);
            //printf("%s\n",str);
        }
        else if(q==2){
            int l;
            scanf("%d",&l);
            char s[30001];
            scanf("%s",s);
            if(l==1){
                //strrev(str);

                strcat(s,str);
                strcpy(str,s);

                //strrev(str);
                //printf("%s\n",str);
            }
            else{
                strcat(str,s);
                //printf("%s\n",str);
            }
        }
    }
    printf("%s",str);
}