#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum Type{ 
    savings=0,
    current,
}Type; //0=savings and 1=current
typedef struct AccountInfo{
    int AccountNumber;
    Type AccountType;
    char* Name;
    float Balance;
}AccountInfo; //Structure containing AccountNumber,AccountType,Name,Balance
typedef struct Database{
    AccountInfo Data;
    struct Database*Next;
}Database; //Node to Store Data and Pointer(Next) to Next Element

int main(){
    Database Creator={{99,savings,"boo",50},NULL};
    Database * DP=&Creator; //Main Pointer pointing to First Data
    void display(){
        Database* DB=DP->Next;
        if(DB==NULL){
            printf("\n>No Account in Database\n\n");
            return;
        }
        printf("\nAccount Number\tAccount Type\tName\t\tBalance\n");
        printf("--------------------------------------------------------\n");

        while(DB!=NULL){
            printf("%d\t\t",DB->Data.AccountNumber);
            if(DB->Data.AccountType==0){
                printf("savings");
            }
            else{
                printf("current");
            }
            printf("\t\t%s\t\t%.2f\n",DB->Data.Name,DB->Data.Balance);
            DB=DB->Next;
        }
        printf("\n");
    }

    void CREATE(int accountType,char* Name,float Amount){ //Database Pointer
        Database * DB=DP;  //Temporily Pointer

        int count=100;
        
        while(DB->Next!=NULL && ((DB->Next)->Data.AccountNumber==count)){
            if(DB->Data.AccountType==accountType && (strcmp(DB->Data.Name,Name))==0){
                printf("Invalid: User Already Exists\n\n");
                return;
            }
            count++;
            DB=DB->Next;
        } 
        Database* Node=(Database*) malloc(sizeof(Database));
        Node->Data.AccountNumber=count;
        Node->Data.AccountType=accountType;
        Node->Data.Name = malloc(strlen(Name) + 1); // Allocate memory for Name
        strcpy(Node->Data.Name,Name);
        Node->Data.Balance=Amount;           
        DB->Next=Node;

        printf("\n>Account Created Successfully.\n\n>>A/C No.%d\n>>A/C Holder:%s\n>>A/C Type:",count,Name);
        if(accountType==0){
            printf("Savings\n");
        }
        else{
            printf("Current\n");
        }
        printf(">>Balance: RS%f\n\n",Amount);

    }

    void DELETE(int accountType,char* Name){
    Database* DB=DP; 
    Database* prev = NULL;
    while(DB!=NULL){
        if(strcmp(DB->Data.Name,Name)==0 && DB->Data.AccountType==accountType){
            if(prev == NULL) {
                DP = DB->Next;
            } else {
                prev->Next = DB->Next;
            }
            free(DB->Data.Name); // Free the allocated memory for Name
            free(DB); // Free the memory allocated for the node
            printf("\n>Account Deleted Successfully.\n\n");
            return;
        }
        prev = DB;
        DB=DB->Next;
    }
    printf("\n>Invalid: User does not exist\n\n");
}
    
    void lowBalanceAccounts(){
        Database* DB=DP->Next;
        printf("\n");
        while(DB!=NULL){
            if(DB->Data.Balance<100){
                printf("Account Number: %d, Name: %s\n",DB->Data.AccountNumber,DB->Data.Name);
            }
            DB=DB->Next;
        }
        printf("\n");
    }

    void transaction(int accountNumber,int amount_code){
        Database* DB=DP;
        if(amount_code==1){
            int deposit;
            printf("Enter Amount: ");
            scanf("%d",&deposit);
            while(DB->Data.AccountNumber!=accountNumber && DB->Next!=NULL){
                DB=DB->Next;
            }
            if(DB->Data.AccountNumber==accountNumber){
                DB->Data.Balance=DB->Data.Balance+deposit;
            }
            else{
                printf("\n>Invalid: User doesn't Exists!\n\n");
            }
        }
        else if(amount_code==0){
            int withdraw;
            printf("Enter Amount: ");
            scanf("%d",&withdraw);
            while(DB->Data.AccountNumber!=accountNumber && DB->Next!=NULL){
                DB=DB->Next;
            }
            if(DB->Data.AccountNumber!=accountNumber){
                printf("\n>Invalid: User doesn't Exists!\n\n");
            }
            else if(DB->Data.Balance>withdraw+100 ){
                DB->Data.Balance=DB->Data.Balance-withdraw;
            }
            else{
                printf("\n>The balance is insufficient for the specified withdrawal.\n\n");
            }    
        }
    }
    
    char input[50];
    while(strcmp(input,"EXIT")!=0){
        printf("------------------------------------------------------------------------------------------------->\n");
        printf("1.DISPLAY\n2.CREATE\n3.DELETE\n4.LOW BALANCE ACCOUNT\n5.TRANSACTION\n6.EXIT\n\nEnter your Input (All in Caps): ");
        scanf("%s",input);

        if(strcmp(input,"DISPLAY")==0 || strcmp(input,"1")==0){
            display();
        }
        else if(strcmp(input,"CREATE")==0 || strcmp(input,"2")==0){
            //printf("\n>0:Savings\n>1:Current\n");
            printf("Enter Account type(All in Cap): ");
            char ACT[50];
            int inp=1;
            if(strcmp(ACT,"SAVINGS")==0){
                inp=0;
            }
            scanf("%s",ACT);

            printf("Enter Name: ");
            char NAME[50];
            scanf("%s",NAME);

            printf("Enter Amount: ");
            float AMOUNT;
            scanf("%f",&AMOUNT);

            CREATE(inp,NAME,AMOUNT);
        }
        else if(strcmp(input,"DELETE")==0 || strcmp(input,"3")==0){
            //printf("\n>0:Savings\n>1:Current\n");
            printf("Enter Account type: ");
            char ACT[50];
            int inp=1;
            scanf("%s",ACT);
            if(strcmp(ACT,"SAVINGS")==0){
                inp=0;
            }
            
            printf("Enter Name: ");
            char NAME[50];
            scanf("%s",NAME);

            DELETE(inp,NAME);

        }
        else if(strcmp(input,"LOWBALANCEACCOUNT")==0 || strcmp(input,"4")==0){
            lowBalanceAccounts();
        }
        else if(strcmp(input,"TRANSACTION")==0 || strcmp(input,"5")==0){
            int ACN;
            printf("Enter Account Number: ");
            scanf("%d",&ACN);

            printf("Amount Code:\n1:Deposit\n0:Withdraw\n");

            printf("Enter Ammount Code: ");
            int ACC;
            scanf("%d",&ACC);

            transaction(ACN,ACC);
        }
        else if(strcmp(input,"EXIT")==0 || strcmp(input,"6")==0){
            printf("\n>THANKYOU");
        } 
        else{
            printf(">\nINVALID INPUT");
        }  
    }
}
// DISPLAY 
// DELETE savings Keval
// CREATE savings Manav 200
// CREATE savings Keval 1000
// CREATE current Keval 200
// LOWBALANCE 
// DISPLAY 
// DELETE savings Keval 
// DISPLAY
// CREATE savings Pramod 90
// DISPLAY 
// LOWBALANCE
// CREATE savings Pramod 900
// TRANSACTION 102 20 1 
// LOWBALANCE 
// DISPLAY
// TRANSACTION 102 100 0
// TRANSACTION 101 10 0
// TRANSACTION 103 10 1
// DELETE savings Manav 
// CREATE savings Manav 90 
// LOWBALANCE 
// DISPLAY 
// EXIT