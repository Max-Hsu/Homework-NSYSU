#include <iostream>
#include <stdio.h>


int main()
{
    int input_1,input_2,input_3,input_4;
    scanf("%d %d %d %d",&input_1,&input_2,&input_3,&input_4);
    printf("Num1: %d\nNum2: %d\nNum3: %d\nNum4: %d\n",input_1,input_2,input_3,input_4);
    printf("%d + %d - %d * %d = %d\n",input_1,input_2,input_3,input_4,input_1+input_2-input_3*input_4);
    printf("%d + %d * %d - %d = %d\n",input_1,input_2,input_3,input_4,input_1+input_2*input_3-input_4);
    printf("%d - %d + %d * %d = %d\n",input_1,input_2,input_3,input_4,input_1-input_2+input_3*input_4);
    printf("%d - %d * %d + %d = %d\n",input_1,input_2,input_3,input_4,input_1-input_2*input_3+input_4);
    printf("%d * %d + %d - %d = %d\n",input_1,input_2,input_3,input_4,input_1*input_2+input_3-input_4);
    printf("%d * %d - %d + %d = %d\n",input_1,input_2,input_3,input_4,input_1*input_2-input_3+input_4);
    return 0;
}
