#include <stdio.h>
#include <stdlib.h>
#define Anum 65
#define anum 97
#define Znum 90
#define znum 122
int main()
{
    FILE *input=fopen("input1.txt","w");
    srand(1);
    if(!input)
    {
        printf("error while opening file input1.txt\n");
        return 1;
    }
    for(int i=0; i<1000; i++)
    {
        int now_i=(rand()%52)+Anum;
        if(now_i>90)
        {
            now_i+=6;
        }
        char now_c=(char)now_i;
        fprintf(input,"%c\n",now_c);
    }
    fclose(input);
    input=fopen("input1.txt","r");
    if(!input)
    {
        printf("error while opening file input1.txt\n");
        return 1;
    }
    char findchar;
    printf("請輸入要尋找的字元:");
    scanf("%c",&findchar);
    int find_char_num=(int)findchar;
    int counter;
    while(find_char_num!=42)
    {
        if(((find_char_num>=Anum)&&(find_char_num<=Znum))||((find_char_num>=anum)&&(find_char_num<=znum)))
        {
            counter=0;
            char text;
            while(fscanf(input,"%c\n",&text)!=EOF)
            {
                if((text==findchar)||(text==(findchar-32)))
                {
                    counter++;
                }
            }
            printf("字元'%c'一共找到:%d\n\n\n",findchar,counter);
        }
        else{
            printf("輸入錯誤，再試一次。\n\n");
        }
            printf("請輸入要尋找的字元:");
            scanf(" %c",&findchar);
            find_char_num=(int)findchar;
            rewind(input);

    }
    printf("結束尋找。\n\n");

    fclose(input);
}
