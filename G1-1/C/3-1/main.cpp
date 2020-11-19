#include <iostream>
#include <stdio.h>


int main()
{
    int money_in;
    printf("Enter the value of monthly salary : ");
    scanf("%d",&money_in);
    printf("\n");
    if(money_in<=30000){
        float x=money_in*13.5;
        printf("Your annual salary is $%d\n",(int)x);
    }
    else if(money_in<=50000){
        printf("Your annual salary is $%d\n",money_in*14);
    }
    else if(money_in<=70000){
        float x=money_in*14.5;
        printf("Your annual salary is $%.0f\n",(int)x);
    }
    else{
        printf("Your annual salary is $%d\n",money_in*16);
    }
    return 0;
}
