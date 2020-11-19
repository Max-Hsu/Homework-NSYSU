#include <iostream>
#include <stdio.h>


int main()
{
    float temp;
    char type;
    printf("Enter the Temperature : ");
    scanf("%f%c",&temp,&type);
    printf("\n");
    if(type=='c'||type=='C'){
        printf("Fahrenheit : %fF",temp*9/5+32);
    }
    else if(type=='f'||type=='F'){
        printf("Celsius : %fC",(temp-32)*5/9);
    }
    else{
        printf("Error!!");
    }
    return 0;
}
