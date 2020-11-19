#include <stdio.h>
#include <stdlib.h>
void myswap(int *x,int *y){
int *temp;
temp=*y;
*y=*x;
*x=temp;
}

int mysubtotal(int x,int y)
{
    if(x==y)
    {
        return x;
    }
    else
        {
        return x+mysubtotal(x+1,y);
        }
}
int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)!=EOF){
    if(x>y){
       myswap(&x,&y);
    }
    printf("%d到%d的總和為:%d\n",x,y,mysubtotal(x,y));
    }
    return 0;
}
