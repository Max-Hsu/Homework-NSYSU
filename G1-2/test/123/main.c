#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    char *x="123\0";
    write(1,x,5);
    printf("%s",x);
    return 0;
}
