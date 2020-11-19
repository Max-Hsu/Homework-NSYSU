#include <stdio.h>
#include <stdlib.h>
struct stacka
{
    int value;
    struct stacka * next;
};
struct stacka * head=NULL;
int maze[9][9] =
{
    {2, 2, 2, 2, 2, 2, 2, 2, 2},
    {2, 0, 2, 0, 0, 0, 0, 0, 2},
    {2, 0, 2, 2, 0, 2, 2, 0, 2},
    {2, 0, 2, 0, 0, 2, 0, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 0, 0, 0, 0, 2, 0, 2},
    {2, 2, 2, 2, 2, 2, 2, 0, 2},
    {2, 0, 0, 0, 0, 0, 0, 0, 2},
    {2, 2, 2, 2, 2, 2, 2, 2, 2}
};

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
            printf("%d\n",traveler->value);
            traveler=traveler->next;
        }

        printf("%d\n",traveler->value);
    }
}
void print_maze(){

for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                printf("%d ",maze[i][j]);
            }
            printf("\n");
        }
}
int travel_y()
{
    struct stacka * traveler;
    traveler=head;
    return traveler->value;
}
int travel_x()
{
    struct stacka * traveler;
    traveler=head;
    return traveler->next->value;
}
int search_route(int x,int y)
{
    int a=0;
    if(maze[x+1][y]==0&&maze[x+1][y]!=1)
    {
        maze[x+1][y]=1;
        mypush(x+1);
        mypush(y);
        a++;
        return a;
    }
    if(maze[x-1][y]==0&&maze[x-1][y]!=1)
    {
        maze[x-1][y]=1;
        mypush(x-1);
        mypush(y);
        a++;
        return a;
    }
    if(maze[x][y+1]==0&&maze[x][y+1]!=1)
    {
        maze[x][y+1]=1;
        mypush(x);
        mypush(y+1);
        a++;
        return a;
    }
    if(maze[x][y-1]==0&&maze[x][y-1]!=1)
    {
        maze[x][y-1]=1;
        mypush(x);
        mypush(y-1);
        a++;
        return a;
    }

    return a;
}

int main()
{
    print_maze();
    int mice_x,mice_y;
    mice_x=1;
    mice_y=1;
    mypush(1);
    mypush(1);
    maze[1][1]=1;
    while(travel_x()!=7||travel_y()!=7)
    {
        int as;
        as=search_route(travel_x(),travel_y());
        if(as==0)
        {
            maze[travel_x()][travel_y()]=0;
            mypop();
            mypop();
        }
        //print_maze();
        printf("\n");
    }

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
    return 0;
}
