#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int ct=time(NULL);
    clock_t now=clock();
    ct=ct+19800;
    int sec=ct%60;
    int min=((ct-sec)%3600)/60;
    int hour=((ct-min*60-sec)%(3600*24))/(3600);
   // printf("%d",gmtime(ct));
    printf("%.2d:%.2d:%.2d",hour,min,sec);
    clock_t later=clock();

    printf("\n%ld %ld %ld",now,later,(later-now));
}