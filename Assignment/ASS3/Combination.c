#include<stdio.h>
#include<string.h>

void swap(char s[],int i,int f){
    char temp;
    temp=s[i];
    s[i]=s[f];
    s[f]=temp;
}
void sort(char s[], int init, int len) {
    for (int i = init; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (s[i] > s[j]) {
                swap(s, i, j);
            }
        }
    }
} 
// void sort(char s[],int init,int len){
//     for(int i=init;i<len-1;i++){
//         if(s[i]>s[i+1]){
//             swap(s,i+1,i);
//         }
//     }
//     if(init<len-1){
//         sort(s,init,len-1);
//     }
// }
int factorial(int n){
    int sum=1;
    for(int i=1;i<=n;i++){
        sum=sum*i;
    }
    return sum;
}
void combination(char s[],int init,int len){
    if(init==len-2){
        printf("%s\n",s);
        if(s[init]!=s[len-1]){
            swap(s,init,len-1);
            printf("%s\n",s);
            swap(s,init,len-1);
        }   
    }
    else{
        combination(s,init+1,len);
        for(int i=init+1;i<len;i++){
            if(s[i]!=s[init] && (s[i-1]!=s[i])){
                swap(s,i,init);
                sort(s,init+1,len);
                combination(s,init+1,len);
                sort(s,init,len);
            }
        }
    }
}
int count(char s[],int len){
    int total=factorial(len);
    int a[len];
    for(int i=0;i<len;i++){
        a[i]=(int)s[i];
    }
    
    for(int i=0;i<len;){
        int count=0;
        for(int j=i;j<len;j++){
            if(a[i]==a[j]){
                count++;
            }
        }
        total=total/(factorial(count));
        i=i+count;
    }
    return total;
}

int main(){
    char s[8];
    scanf("%s",s);

    int len=strlen(s);
    
    
    if(len==1){
        printf("%d\n",count(s,len));
        printf("%s",s);   
    }
    else{
        sort(s,0,len);
        printf("%d\n",count(s,len));
        combination(s,0,len); 
    }     
}