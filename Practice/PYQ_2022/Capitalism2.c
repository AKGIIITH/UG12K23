#include <stdio.h>
#define true 1
#define false 0

int main()
{
    int t; //number of testcases
    scanf("%d", &t);
    for (int l=0; l<t; l++)
    {
        int flag = 1;
        int count = 0;
        
        while(flag)
        {   
            char temp;
            scanf("%c", &temp);
            if(temp > 64 && temp < 91) //temp is capital
            {
                count++;
            }
            else if (temp == '\n'&& count!=0)
            {
                flag = 0;
            }
        }
        printf("%d\n", count);
    }

}
