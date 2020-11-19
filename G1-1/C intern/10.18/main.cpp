#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    for(int q=0; q<x; q++)
    {
        int w=x-q;
        for(w=x-q; w>0; w--)
        {
            printf(" ");
        }
        printf("*");
        for(int r=0; r<q-1; r++)
        {
            printf(" ");

        }
        for(int e=q; e>0; e--)
        {
            if(q==(x-1)&&e==q){
                printf("%d",x);
                if((x/10)>=1){e-=1;}
            }

            else{
            printf(" ");
            }
        }
        if(q!=0)
        {
            printf("*");
        }
        printf("\n");
    }

    for(int q=x-2; q>0; q--)
    {
        int w=x-q;
        for(w=x-q; w>0; w--)
        {
            printf(" ");
        }
        printf("*");
        for(int r=0; r<q-1; r++)
        {
            printf(" ");
        }
        for(int e=q; e>0; e--)
        {
            printf(" ");
        }
        if(q!=0)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int p=0;p<x;p++){
        printf(" ");
    }
                printf("*");
    return 0;
}
