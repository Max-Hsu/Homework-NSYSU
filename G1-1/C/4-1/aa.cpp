#include <iostream>
#include <stdio.h>


int main()
{   //homework 4-2 using for loop
    for(int x=0; x<10; x++)
    {
        int in_1,in_2,in_3;
        scanf("%d %d %d",&in_1,&in_2,&in_3);
        while(in_1>in_2||in_2>in_3)
        {
            if(in_1>in_2)
            {
                int temp;
                temp=in_1;
                in_1=in_2;
                in_2=temp;
            }
            if(in_2>in_3)
            {
                int temp;
                temp=in_2;
                in_2=in_3;
                in_3=temp;
            }
        }
        if(in_1+in_2>in_3)
        {
            printf("%d %d %d 篶Θà\n",in_1,in_2,in_3);
            if(in_1==in_2&&in_2==in_3)
            {
                printf("%d %d %d 篶Θタà\n",in_1,in_2,in_3);
            }
            else if(in_1==in_2||in_2==in_3||in_1==in_3)
            {
                if((in_1*in_1+in_2*in_2)==(in_3*in_3))
                {
                    printf("%d %d %d  篶Θ单竬àà\n",in_1,in_2,in_3);
                }
                else
                {
                    printf("%d %d %d  篶Θ单竬à\n",in_1,in_2,in_3);
                }
            }
            else if((in_1*in_1+in_2*in_2)==(in_3*in_3))
            {
                printf("%d %d %d  篶Θàà\n",in_1,in_2,in_3);
            }
            else
            {
                printf("%d %d %d  篶Θà\n",in_1,in_2,in_3);
            }
        }
        else
        {
            printf("%d %d %d ぃ篶Θà\n",in_1,in_2,in_3);
        }
    }
    //homework 4-2 using while loop
    int count_while=0;
    while(count_while<10){
        int in_1,in_2,in_3;
        scanf("%d %d %d",&in_1,&in_2,&in_3);
        while(in_1>in_2||in_2>in_3)
        {
            if(in_1>in_2)
            {
                int temp;
                temp=in_1;
                in_1=in_2;
                in_2=temp;
            }
            if(in_2>in_3)
            {
                int temp;
                temp=in_2;
                in_2=in_3;
                in_3=temp;
            }
        }
        if(in_1+in_2>in_3)
        {
            printf("%d %d %d 篶Θà\n",in_1,in_2,in_3);
            if(in_1==in_2&&in_2==in_3)
            {
                printf("%d %d %d 篶Θタà\n",in_1,in_2,in_3);
            }
            else if(in_1==in_2||in_2==in_3||in_1==in_3)
            {
                if((in_1*in_1+in_2*in_2)==(in_3*in_3))
                {
                    printf("%d %d %d 篶Θ单竬àà\n",in_1,in_2,in_3);
                }
                else
                {
                    printf("%d %d %d 篶Θ单竬à\n",in_1,in_2,in_3);
                }
            }
            else if((in_1*in_1+in_2*in_2)==(in_3*in_3))
            {
                printf("%d %d %d 篶Θàà\n",in_1,in_2,in_3);
            }
            else
            {
                printf("%d %d %d 篶Θà\n",in_1,in_2,in_3);
            }
        }
        else
        {
            printf("%d %d %d ぃ篶Θà\n",in_1,in_2,in_3);
        }
        count_while++;
    }
    //homework 4-2 using do-while loop
    int count_do_while=0;
    do
    {
        int in_1,in_2,in_3;
        scanf("%d %d %d",&in_1,&in_2,&in_3);
        while(in_1>in_2||in_2>in_3)
        {
            if(in_1>in_2)
            {
                int temp;
                temp=in_1;
                in_1=in_2;
                in_2=temp;
            }
            if(in_2>in_3)
            {
                int temp;
                temp=in_2;
                in_2=in_3;
                in_3=temp;
            }
        }
        if(in_1+in_2>in_3)
        {
            printf("%d %d %d 篶Θà\n",in_1,in_2,in_3);
            if(in_1==in_2&&in_2==in_3)
            {
                printf("%d %d %d 篶Θタà\n",in_1,in_2,in_3);
            }
            else if(in_1==in_2||in_2==in_3||in_1==in_3)
            {
                if((in_1*in_1+in_2*in_2)==(in_3*in_3))
                {
                    printf("%d %d %d 篶Θ单竬àà\n",in_1,in_2,in_3);
                }
                else
                {
                    printf("%d %d %d 篶Θ单竬à\n",in_1,in_2,in_3);
                }
            }
            else if((in_1*in_1+in_2*in_2)==(in_3*in_3))
            {
                printf("%d %d %d 篶Θàà\n",in_1,in_2,in_3);
            }
            else
            {
                printf("%d %d %d 篶Θà\n",in_1,in_2,in_3);
            }
        }
        else
        {
            printf("%d %d %d ぃ篶Θà\n",in_1,in_2,in_3);
        }
        count_do_while++;
    }while(count_do_while<10);
    //printf("%d %d %d",in_1,in_2,in_3);
    return 0;
}
