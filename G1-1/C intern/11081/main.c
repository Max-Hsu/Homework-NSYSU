#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int total;
int R(int mina,int maxa){
    return rand()%maxa+mina;
}
void CAL(){
    int a=R(1,15);
    if(a==10){
        printf("%d \n",total);
    }
    else{
        total+=a;
        CAL();
    }
}
int main()
{
    total=0;
    srand(time(NULL));
    CAL();
    return 0;
}
