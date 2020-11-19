#include <iostream>
#include <time.h>
using namespace std;
void checka();
int cond=0;
void showcard(int,int);
void showusercard();
void showpccard(int);
int user_haved;
int pc_haved;
int pc_want;
int user[6][2]= {0};
int pc[6][2]= {0};
int user_true[6][2]= {0};
int pc_true[6][2]= {0};
int total[12][2]= {0};
int rands(int x)
{
    return rand()%x+1;
}
int iscontinue()
{
    char www;
    printf("do you want to continue??");
    scanf(" %s",&www);
    if(www=='y')
    {
        return 0;
    }
    else
    {
        return 1;

    }
}
void initialGame()
{
    for(int i=0; i<6; i++)
    {
        user[i][1]=rands(4);
        user[i][0]=rands(13);
        pc[i][1]=rands(4);
        pc[i][0]=rands(13);
    }
    for(int i=0; i<6; i++)
    {
        total[i][1]=user[i][1];
        total[i][0]=user[i][0];
    }

    for(int i=0; i<6; i++)
    {
        total[i+6][1]=pc[i][1];
        total[i+6][0]=pc[i][0];
    }
    checka();
    for(int i=0; i<6; i++)
    {
        if(user[i][0]>=10)
        {
            user_true[i][0]=10;
        }
        else
        {
            user_true[i][0]=user[i][0];
        }
    }
    for(int i=0; i<6; i++)
    {
        if(pc[i][0]>=10)
        {
            pc_true[i][0]=10;
        }
        else
        {
            pc_true[i][0]=pc[i][0];
        }
    }


}
int comparrd()
{
    int user=0;
    int pc=0;
    for(int i=0; i<user_haved; i++)
    {
        user+=user_true[i][0];
    }
    for(int i=0; i<pc_haved; i++)
    {
        pc+=pc_true[i][0];
    }
    printf("\n\n%d %d\n\n",user,pc);
    if(user>pc)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int userpoint()
{
    int e=0;
    for(int i=0; i<user_haved; i++)
    {
        e+=user_true[i][0];
    }
    return e;
}
int user_turn()
{
    char c;
    int quit=0;
    printf("User:");
    showusercard();
    printf("\n");
    printf("Pc:");
    showpccard(1);
    printf("\n");
    while((user_haved<5)&&(!quit))
    {
        printf("Add a card?(Y/N)");
        scanf(" %c",&c);
        if(c=='y')
        {
            user_haved++;
            printf("User:");
            showusercard();
            printf("\n");
            if(userpoint()>21)
            {
                printf("Pc:");
                showpccard(pc_haved);
                printf("\n");
                printf("I WIN\n");
                cond=1;
                return 0;
            }
        }
        else
        {
            quit=1;
        }

    }

    return 1;
}
int pc_turn() {
    int pc=0;
    for(int i=0; i<pc_haved; i++)
    {
        pc+=pc_true[i][0];
    }
    if(pc<19){
        pc_haved++;
        pc_turn();
    }

}
void showusercard()
{
    for(int i=0; i<user_haved; i++)
    {
        showcard(user[i][0],user[i][1]);
    }
}
void showpccard(int want)
{
    for(int i=0; i<want; i++)
    {
        showcard(pc[i][0],pc[i][1]);
    }
}
void showcard(int x,int y)
{
    char suit[5]= {' ','s','h','d','c'};
    printf("%c",suit[y]);
    switch(x)
    {
    case 1:
        printf("A");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        printf("%1d",x);
        break;
    case 10:
        printf("T");
        break;
    case 11:
        printf("J");
        break;
    case 12:
        printf("Q");
        break;
    case 13:
        printf("K");
        break;
    }
}
void checka()
{
    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(i!=j)
            {
                if((total[i][0]==total[j][0])&&(total[i][1]==total[j][1]))
                {
                    if(i>5)
                    {
                        total[i][0]=rands(13);
                        total[i][1]=rands(4);
                        pc[i-6][0]=total[i][0];
                        pc[i-6][1]=total[i][1];
                        checka();
                    }
                    else
                    {
                        total[i][0]=rands(13);
                        total[i][1]=rands(4);
                        user[i][0]=total[i][0];
                        user[i][1]=total[i][1];
                        checka();
                    }

                }
            }
        }
    }
}
int main()
{
    srand(time(NULL));

    int quit=0;
    while(!quit)
    {
        cond=0;
        initialGame();
        user_haved=2;
        pc_haved=2;
        /*
        for(int i=0; i<6; i++)
        {
            printf("user:%d %d\n",user[i][1],user[i][0]);
            printf("pc:%d %d\n",pc[i][1],pc[i][0]);
        }
        */
        if(user_turn())
        {
            pc_turn;
        }
        int aaa;
        aaa = comparrd();
        if(cond==0){
        printf("User:");
        showusercard();
        printf("\n");
        printf("Pc:");
        showpccard(pc_haved);
        printf("\n");
        if(aaa)

            printf("i win\n");
        else
            printf("you win\n");
        }
        quit=iscontinue();
    }


    return 0;
}
