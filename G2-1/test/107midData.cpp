#include <iostream>

using namespace std;

int main(){
    int c[ ]={20,24,28,32,36};
     int *p;
p=c+2;
 *(p++)=c[0]+5; 
 *(c+1) = *(p+1)+3;
printf("%d %d %d %d \n",c[1],c[2],c[3],c[4]);

}