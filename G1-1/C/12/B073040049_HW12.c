#include <stdio.h>
#include <stdlib.h>
struct stacka
{
    int value;
    struct stacka * next;
};
struct stacka * head=NULL;
void mypush(int input_num)
{
    if(head==NULL)
    {
        head=(struct stacka*)malloc(sizeof(struct stacka));
        head->value=input_num;
        head->next=NULL;
    }
    else
    {
        struct stacka * newa;
        newa=(struct stacka*)malloc(sizeof(struct stacka));
        newa->next=head;
        newa->value=input_num;
        head=newa;
    }
}
int mypop()
{
    if(head==NULL)
    {
        return -1;
    }
    else
    {
        struct stacka * pointa;
        int pop_a;
        pointa=head;
        pop_a=pointa->value;
        head=pointa->next;
        free(pointa);
        return pop_a;
    }
}
void travel()
{
    struct stacka * traveler;
    traveler=head;
    if(traveler!=NULL)
    {
        while(traveler->next!=NULL)
        {
            printf("*          *\n");
            printf("*  %5d   *\n",traveler->value);
            printf("*          *\n");
            printf("************\n");
            traveler=traveler->next;
        }

        printf("*          *\n");
        printf("*  %5d   *\n",traveler->value);
        printf("*          *\n");
        printf("************\n");
    }
}
int main()
{
    int stata;
    printf("Please input the instruction:");
    while(scanf("%d",&stata)!=EOF)
    {
        if(stata==1)
        {
            int input_num;
            printf("Please input the number:");
            scanf(" %d",&input_num);
            printf("push %d into stack.\n",input_num);
            mypush(input_num);
            travel();
        }
        else if(stata==2)
        {
            int pop_a=mypop();
            if(pop_a==-1)
            {
                printf("Error:there is no stack\n");
            }
            else
            {
                printf("pop %d into stack.\n",pop_a);
            }
            travel();
        }
        printf("Please input the instruction:");
    }

    return 0;
}
