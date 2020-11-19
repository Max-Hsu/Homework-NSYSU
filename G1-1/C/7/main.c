#include <stdio.h>
#include <stdlib.h>
#define Anum 65
int check_range(int input)
{
    if(input<=26&&input>=1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void draw_parallelogram(int input)
{
    for(int i=0; i<input; i++)
    {
        for(int j=0; j<i; j++)
        {
            printf(" ");
        }
        for(int k=0; k<input; k++)
        {
            printf("%c ",Anum+k);
        }
        for(int l=input-2; l>=0; l--)
        {
            printf("%c ",Anum+l);
        }
        printf("\n");
    }
}
void draw_diamond(int input)
{
    for(int i=0; i<input; i++)
    {
        for(int j=input-i-1; j>0; j--)
        {
            printf("  ");
        }
        for(int k=0; k<=i; k++)
        {
            printf("%c ",Anum+k);
        }
        for(int l=i-1; l>=0; l--)
        {
            printf("%c ",Anum+l);
        }
        printf("\n");
    }
    for(int p=input-2; p>=0; p--)
    {
        for(int j=input-p-1; j>0; j--)
        {
            printf("  ");
        }
        for(int k=0; k<=p; k++)
        {
            printf("%c ",Anum+k);
        }
        for(int l=p-1; l>=0; l--)
        {
            printf("%c ",Anum+l);
        }
        printf("\n");
    }
}
int main()
{
    int input;
    printf("Please input the number N: ");
    scanf("%d",&input);
    while(check_range(input)==0)
    {
        printf("The number N is out of range. PLease input again!!\n\n");
        printf("Please input the number N: ");
        scanf("%d",&input);
    }
    printf("\n\n");
    draw_parallelogram(input);
    printf("\n\n");
    draw_diamond(input);
    return 0;
}
