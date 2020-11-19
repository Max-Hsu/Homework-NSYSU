#include "B073040049.h"
int main()
{
    FILE *input=fopen("input.txt","r+");
    if(input==-1)
    {
        perror("file");
        exit(1);
    }
    int num_of_file;
    int array_file[10000]= {0};
    fscanf(input,"%d\n",&num_of_file);
    for(int i=0; i<num_of_file; i++)
    {
        fscanf(input,"%d ",&array_file[i]);
    }
    mysort(array_file,num_of_file);
    printf("Sort Finished\n");
    printf("Please input your target:");
    int target;
    while(scanf("%d",&target)!=EOF)
    {
        int ans=myBinarySearch(array_file,target,0,3500-1);
        if(ans==-1)
        {
            printf("target not found.\n");
        }
        else
        {
            printf("target found at index %d.\n",ans);
        }
        printf("Please input your target:");
    }
    return 0;
}
