#include <stdio.h>
#include <stdlib.h>
void rollDice(int Result[],int seed,int n)
{
    srand(seed);
    int i;
    for(i=0; i<n; i++)
    {
        Result[i]=rand()%6+1;
    }
}
void rollTwoDice(int Result[],int seed,int n)
{
    int dice1_for_Q3[30000]= {0};
    int dice2_for_Q3[30000]= {0};
    rollDice(dice1_for_Q3,seed,n);
    rollDice(dice2_for_Q3,seed+1,n);
    int i;
    for(i=0; i<n; i++)
    {
        Result[dice1_for_Q3[i]+dice2_for_Q3[i]]++;
    }
    for(i=1; i<=12; i++)
    {
        int left=Result[i]%100;
        if(left<50)
        {
            Result[i]-=left;
        }
        else
        {
            Result[i]+=(100-left);
        }
    }
}
void rollDiceCompetition(int seed,int n)
{
    int wina,losea,drawa;
    wina=0;
    losea=0;
    drawa=0;
    int dice_comp_A[30000]= {0};
    int dice_comp_B[30000]= {0};


    rollDice(dice_comp_A,seed,n);
    rollDice(dice_comp_B,seed+1,n);

    int i;
    for(i=0; i<n; i++)
    {

        if(dice_comp_A[i]>dice_comp_B[i])
        {
            wina++;
        }
        else if(dice_comp_A[i]==dice_comp_B[i])
        {
            drawa++;
        }
        else
        {
            losea++;
        }
    }
    printf("\nQ4.\n");
    printf("A win %d times.\n",wina);
    printf("A lose %d times.\n",losea);
    printf("Match Draw:%d\n",drawa);
}
int main()
{
    int random_seed,roll_size;
    int dice_array[50000]= {0};
    int dice_counter[7]= {0};
    printf("Please Input Your Seed:");
    scanf("%d",&random_seed);
    srand(random_seed);
    FILE *Output=fopen("Output.txt","w+");
    int i;
    for(i=0; i<5000; i++)
    {
        fprintf(Output,"%d ",rand()%6+1);
    }
    fclose(Output);
    printf("Please Input Size:");
    scanf("%d",&roll_size);

    printf("\nQ2.\n");

    rollDice(dice_array,random_seed,roll_size);
    for(i=0; i<roll_size; i++)
    {
        dice_counter[dice_array[i]]++;
    }
    for(i=1; i<=6; i++)
    {
        int left=dice_counter[i]%100;
        if(left<50)
        {
            dice_counter[i]-=left;
        }
        else
        {
            dice_counter[i]+=(100-left);
        }
    }
    for(i=1; i<=6; i++)
    {
        printf("%d ",i);
        int j;
        for(j=0; j<dice_counter[i]; j+=100)
        {
            printf("*");
        }
        printf("\n");
    }


    printf("\nQ3.\n");
    int dice_counter_for_Q3[13]= {0};
    rollTwoDice(dice_counter_for_Q3,random_seed,roll_size);


    for(i=1; i<=12; i++)
    {
        printf("%2d ",i);
        int j;
        for(j=0; j<dice_counter_for_Q3[i]; j+=100)
        {
            printf("*");
        }
        printf("\n");
    }
    rollDiceCompetition(random_seed,roll_size);
    return 0;
}
