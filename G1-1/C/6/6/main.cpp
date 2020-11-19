#include <stdio.h>
#include <math.h>
int main()
{
    int year;
    int month;
    int date;
    printf("Input:");
    scanf("%4d%2d%d",&year,&month,&date);
    if(month==1)
    {
        char s[]="January";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==2)
    {
        char s[]="February";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==3)
    {
        char s[]="March";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==4)
    {
        char s[]="April";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==5)
    {
        char s[]="May";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==6)
    {
        char s[]="June";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==7)
    {
        char s[]="July";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==8)
    {
        char s[]="August";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==9)
    {
        char s[]="September";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==10)
    {
        char s[]="October";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==11)
    {
        char s[]="November";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    else if(month==12)
    {
        char s[]="December";
        printf("%29s",s);
        printf(", %d\n",year);
    }
    printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");


    for(int i=date; i>0; i--)
    {
        printf("     ");
    }

    if(month==1)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==2)
    {
        int days=29;
        if(((year%4==0 && year%100!=0 ) || (year%400 ==0)))
        {
            days=29;
        }
        else
        {
            days=28;
        }
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==3)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==4)
    {
        int days=30;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==5)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==6)
    {
        int days=30;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==7)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==8)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==9)
    {
        int days=30;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==10)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==11)
    {
        int days=30;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }
    else if(month==12)
    {
        int days=31;
        for(int q=1; q<=days; q++)
        {
            for(int w=(4-(int)log10(q)); w>0; w--)
            {
                printf(" ");
            }
            printf("%d",q);
            date++;
            if(date%7==0)
            {
                printf("\n");
                date%=7;
            }
        }
    }

    return 0;
}
