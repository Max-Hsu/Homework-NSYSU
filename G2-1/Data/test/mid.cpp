#include <iostream>

using namespace std;

int main(){
    int c =-5;
    //cout<<(c>>28);
    //printf("  %d" , (c<<5));
    printf("  %d" , (c>>1));
    c>>=1;
    printf("  %d" , (c>>1));
    c>>=1;
    printf("  %d" , (c>>1));
    c>>=1;
    printf("  %d" , (c>>1));
    c>>=1;
    printf("  %d" , (c>>1));
}