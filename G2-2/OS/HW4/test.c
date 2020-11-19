#include <stdio.h>
#include "mm.h"

int main(){
    void * pointerOfMyMalloc;
    int * pointerToInt;
    printf("mymalloc:ok\n");
    pointerOfMyMalloc = mymalloc(501);
    pointerToInt = (int * )pointerOfMyMalloc;
    pointerToInt[0]= 500;
    pointerToInt[10]= 4000;
    printf("myrealloc:ok\n");
    pointerOfMyMalloc = myrealloc(pointerOfMyMalloc,701);
    pointerToInt = (int * )pointerOfMyMalloc;
    printf("%d %d\n",pointerToInt[0],pointerToInt[10]);
    myfree(pointerOfMyMalloc);
    printf("mycalloc:ok\n");
    pointerOfMyMalloc = mycalloc(sizeof(int),100);
    pointerToInt = (int * )pointerOfMyMalloc;
    printf("%d %d\n",pointerToInt[0],pointerToInt[10]);
    myfree(pointerOfMyMalloc);
    printf("bye\n");
}