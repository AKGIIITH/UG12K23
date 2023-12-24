//It is not mandatory that He has to Invest,He can Skip
#include<stdio.h>
int main(){
    int n;          //amount to reach
    scanf("%d",&n);
    
    int mininvestment=n; //When 1-time complete  investment
    int amount=1; //Amount after each day
    for(int investment=1;investment<n;investment++){ //Investment doe nor cross amount to reach
        if(amount%n==0){
            int k;        //value of X
            k=n/amount;
            if(k*investment<mininvestment){
                mininvestment=k*investment;
            }   
        }
        amount++;
        if(amount%n==0){
            int k;        //value of X
            k=n/amount;
            if(k*investment<mininvestment){
                mininvestment=k*investment;
            }   
        }
        amount=2*amount; //Investment=x,Therefore Amount=amount*x;
    }   
    printf("%d",mininvestment);
}