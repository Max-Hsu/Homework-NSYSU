#include <iostream>
#include <stdio.h>


int main()
{
    float input_1,input_2,input_3;
    scanf("%f %f %f",&input_1,&input_2,&input_3);
    printf("長: %f\n寬: %f\n高: %f\n",input_1,input_2,input_3);
    printf("周長: %f\n",(input_1+input_2+input_3)*4);
    printf("表面積: %f\n",((input_1*input_2)+(input_3*input_1)+(input_2*input_3))*2);
    printf("體積: %f\n",input_1*input_2*input_3);

    return 0;
}
