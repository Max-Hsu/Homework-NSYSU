#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    FILE *test =fopen("hello.txt","w+");
    for(int i=0;i<100;i++){
        fprintf(test,"%d ",rand()%100+1);
    }
    fclose(test);
    FILE *testa =fopen("hello.txt","r+");
    int ans[101]={0};
    for(int i=0;i<100;i++){
        int a;
        fscanf(testa,"%d ",&a);
        ans[a]++;
    }
    for(int i=1;i<101;i++){
        for(int q=0;q<ans[i];q++){
            printf("%d ",i);
        }
    }
    fclose(test);
    return 0;
}
