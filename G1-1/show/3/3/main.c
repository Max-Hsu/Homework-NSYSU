#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<100;i++){
        srand(i);
        printf("%5d %5d\n",i,rand()%6+1);
    }
    return 0;
}
