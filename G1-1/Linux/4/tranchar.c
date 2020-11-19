#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define add_space(x) strcat(x," ");
#define alloc(x) (char *)malloc(sizeof(char)*x);
#define FROM    "hsuevaair3317forsmtp@gmail.com"
#define TO      "hsuevaair3317forsmtp@gmail.com"
#define CC      "hsuevaair3317forsmtp@gmail.com"
int main()
{
    char **tranchar;
    struct tm *a;
    time_t x;
    char s[10];
    char sx[100];
    time(&x);
    a=localtime(&x);
    tranchar=(char **)malloc(sizeof(char));

    tranchar[0]=alloc(1);
    strcpy(sx,"Date: ");
    strftime(s, 10, "%a", a);
    strcat(sx,s);
    strcat(sx,", ");
    strftime(s, 10, "%d", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%b", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%G", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%T", a);
    strcat(sx,s);
    add_space(sx);
    strftime(s, 10, "%z", a);
    strcat(sx,s);
    add_space(sx);
    strcat(sx,"\r\n");
    printf("%s",sx);
    tranchar[0]=sx;
    tranchar[1]=alloc(2);

    strcpy(tranchar[1],"To: ");
    strcat(tranchar[1],TO);
    strcat(tranchar[1],"\r\n");

    tranchar[2]=alloc(100);
    strcpy(tranchar[2],"From: ");
    strcat(tranchar[2],FROM);
    strcat(tranchar[2],"\r\n");

    tranchar[3]=alloc(1);
    strcpy(tranchar[3],"Cc: ");
    strcat(tranchar[3],CC);
    strcat(tranchar[3],"\r\n");

    tranchar[4]=alloc(1);
    strcpy(tranchar[4],"Message-ID: abcdefgh\r\n");
    tranchar[5]=alloc(1);
    strcpy(tranchar[5],"Subject: axby");
    //strcat(tranchar[5],tranchar[0]);
    tranchar[6]=alloc(1);
    strcpy(tranchar[6],"hello\r\n");
    tranchar[7]=alloc(1);
    strcpy(tranchar[7],"\r\n");
    tranchar[8]=alloc(1);
    strcpy(tranchar[8],"\r\n");
    tranchar[9]=alloc(1);
    tranchar[9]=NULL;
    //printf("%s",tranchar[5]);
    for(int i=0; i<9; i++)
    {
        printf("%s\n",tranchar[i]);
    }
}
