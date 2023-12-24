#include<stdio.h>
#include<string.h>

int cd(char a,char b){
    int x;
    x=a-b;
    if(x>0){
        return x;
    }
    else{
        return -x;
    }
}
int main(){
    int c,trgt; //Input no. of Character and cd value to receach
    scanf("%d %d",&c,&trgt);

    char str[c+1]; //Input string of c charcter
    scanf("%s",str); //Takes Input until  \0 comes but can work on c string


    int store[c+1]; //Array to store changes in trgt cd value

    for(int i=0;i<c;i++){
         if(cd('a',str[i])<=trgt){ //Changing to 'a',if we can...
            store[i]=trgt;         //Change=store[i]-store[i+1]
            trgt=trgt-cd('a',str[i]);
            str[i]='a';   
        }
        else{
            store[i]=trgt;
            str[i]=(str[i]-trgt);
                trgt=0;      
        }
    }    
    store[c]=trgt;
    
    if(trgt>0){
        for(int i=c-1;i>=0;i--){
            if((store[i]-store[i+1])<13 && trgt!=0){
                trgt=trgt+2*(store[i]-store[i+1]);
                        
                if(cd('z',str[i])<=trgt){
                    trgt=trgt-cd('z',str[i]); //+(store[i]-store[i+1]
                    str[i]='z';
                            }
                else{
                    char x=(char)((int)str[i]+trgt);
                    str[i]=x;
                    trgt=0;
                }
            }
        }
    }
    
    if(trgt==0){
        printf("%s",str);
    }
    else{
        printf("-1");
    }
}
