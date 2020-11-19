#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *a=fopen("Output.txt","r+");
    FILE *b=fopen("Output1.txt","r+");
    int win=0,lose=0,draw=0;
    for(int i=0;i<5000;i++){
            int aa,bb;

        fscanf(a,"%d ",&aa);
        fscanf(b,"%d ",&bb);
        if(aa>bb){
            win++;
        }
        else if(aa==bb){
            draw++;
        }
        else{
            lose++;
        }
    }
    printf("%d %d %d",win,lose,draw);
    fclose(a);
    fclose(b);
    return 0;
}
