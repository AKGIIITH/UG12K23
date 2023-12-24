# q1.c

## Assumptions:
### Type is used for savings and current where 0 means savings and 1 means current.

### My AccountInfo Structure contains:
### Account Type of enum.
### Account Number.
### Name of Pointer String.
### Balance of Float Type.

### Database is a Linked List:
#### With Data of AccountInfo Structure,
#### And Pointer of LinkedList* type.

### Most of the functions have same name, as mentioned in document:
### display,CREATE,DELETE,lowBalalanceAccounts,transaction.
### It have Menu-Driven Program with mentioned inputs.
> DP=Permanent Pointer to Database.
> DB=Database pointer to be used in Function.


> I  made program execution more readable to user using Printing some Objects.

> In CREATE and DELETE, I took AccountType as int instead of conversion to Enum, for easiness of user to input data. MEANS USER CAN EVEN ENTER INTEGER FOR ACCESSING.
### for Which I printed the input format data beforehand.

### I also took an additional data instead of NULL, but It can be replaced easily with null,with few modifications. I did so because I wanted an Input to test Other Functions on, Otherwise I need to have some more conditions, which will make program lengthy.

### Moreover, I considered Ideal input Only as Person might enter negative value in deposit, So i havent considered any additional conditions on inputs.

# q2.c
## Assumptions:
## Append is defined Function for Input of Numbers of different dimension
### Complete Function is built inside main function.
### No Input has been assigned for majority of function.
### They take input from main function directly considering it is one function use at a time case.

### Also defined mod function ehich prints modulus of complex number.
### since We are using maths.h header file we need to use following command to run the file.
> gcc q2.c -lm


# q3.c
## Assumptions:
### My appendunique function do direct append, depends on fact that numbers are non- decreasing, It compares with previous number.
### I have linked list that contains Colour number and pointer pointing to next colour number.


















































































