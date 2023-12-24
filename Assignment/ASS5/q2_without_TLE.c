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
void strocat(char str[],char s[]){
    int n=strlen(str);
    int sn=strlen(s);
    for(int i=0;i<=sn;i++){
        str[n+i]=s[i];
    }
    //str[sn]='\0';
}


int main(){
    char str[100001]; //Main String
    scanf("%s",str);

    int M;   //No. of Iterations
    scanf("%d",&M); 

    int index_front=0;
    char front[300001];

    int index_end=0;
    char end[200001];
    
    int reverse_constant=1;
    // int noofreverse=0;
    for(int i=0;i<M;i++){
        int q=0;
        scanf("%d",&q);

        if(q==1){
            if(reverse_constant==1){
                reverse_constant=2;
            }
            else{
                reverse_constant=1;
            }
            // noofreverse++;
        }
        
        else if(q==2){
            int l;
            scanf("%d",&l);

            l=l*reverse_constant;

            char s;
            scanf(" %c",&s);

            if(l==2){
                end[index_end]=s;
                index_end++;
                end[index_end]='\0';
            }
            else{
                front[index_front]=s;
                index_front++;
                front[index_front]='\0';
            }
        }
    }

    // printf("%s\n",front);
    // printf("%s\n",str);
    // printf("%s\n",end);
    strrev(front);
    strocat(front,str);
    strocat(front,end);
    if(reverse_constant==2){
        strrev(front);
    }
    printf("%s",front);
}