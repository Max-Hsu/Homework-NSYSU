#include <stdio.h>
#include <stdlib.h>
int bubble_sort_compare_time;
int bubble_sort_exchange_time;
int selection_sort_compare_time;
int selection_sort_exchange_time;
int insertion_sort_compare_time;
int insertion_sort_exchange_time;

int bubble_sort(int s[],int sizeof_array,int *num_to_proc)
{
    bubble_sort_compare_time=0;
    bubble_sort_exchange_time=0;
    int s_c[3000];
    for(int i=0; i<sizeof_array; i++)
    {
        s_c[i]=s[i];
    }
    for(int i=0; i<sizeof_array-1; i++)
    {
        for(int j=0; j<sizeof_array-1-i; j++)
        {
            bubble_sort_compare_time++;
            if(s_c[j]>s_c[j+1])
            {
                bubble_sort_exchange_time++;
                int temp;
                temp=s_c[j];
                s_c[j]=s_c[j+1];
                s_c[j+1]=temp;
            }
        }
    }
    char bufff[80]={'\0'};
    snprintf(bufff,80,"Bubble Sort%d.txt",sizeof_array);
    FILE *bubble_sort_file=fopen(bufff,"w+");
    fprintf(bubble_sort_file,"Bubble Sort Results:\n");
    for(int i=0; i<sizeof_array; i++)
    {
        fprintf(bubble_sort_file,"%d ",s_c[i]);
        //printf("%d\n",s_c[i]);
    }
    fflush(bubble_sort_file);
    fclose(bubble_sort_file);
    //printf("%d %d\n",bubble_sort_compare_time,bubble_sort_exchange_time);
    return bubble_sort_exchange_time;
}
int selection_sort(int s[],int sizeof_array,int *num_to_proc)
{
    selection_sort_compare_time=0;
    selection_sort_exchange_time=0;
    int s_c[3000];
    for(int i=0; i<sizeof_array; i++)
    {
        s_c[i]=s[i];
    }
    int maxa;
    int maxv=0;
    for(int i=0; i<sizeof_array-1; i++)
    {
        for(int j=0; j<sizeof_array-i-1; j++)
        {
            selection_sort_compare_time++;
            if(s_c[j]>s_c[j+1]&&s_c[j]>maxv)
            {
                maxa=j;
                maxv=s_c[j];
            }
            else if(s_c[j]<s_c[j+1]&&s_c[j+1]>maxv)
            {
                maxa=j+1;
                maxv=s_c[j+1];
            }
        }
        //printf("\n%d\n%d\n",maxa,maxv);
        int temp;
        temp=s_c[sizeof_array-i-1];
        s_c[sizeof_array-i-1]=s_c[maxa];
        s_c[maxa]=temp;
        maxv=0;
        selection_sort_exchange_time++;
        if((sizeof_array-i-1)==maxa)
        {
            selection_sort_exchange_time-=1;
        }
    }
    char bufff[80]={'\0'};
    snprintf(bufff,80,"Selection Sort%d.txt",sizeof_array);
    FILE *Selection_Sort_file=fopen(bufff,"w+");
    fprintf(Selection_Sort_file,"Selection Sort Results:\n");
    for(int i=0; i<sizeof_array; i++)
    {
        fprintf(Selection_Sort_file,"%d ",s_c[i]);
        //printf("%d\n",s_c[i]);
    }
    fflush(Selection_Sort_file);
    fclose(Selection_Sort_file);
    //printf("%d %d\n",selection_sort_compare_time,selection_sort_exchange_time);
    return selection_sort_exchange_time;
}
int insertion_sort(int s[],int sizeof_array,int *num_to_proc)
{
    insertion_sort_compare_time=0;
    insertion_sort_exchange_time=0;
    int s_c[3000];
    for(int i=0; i<sizeof_array; i++)
    {
        s_c[i]=s[i];
    }
    for(int i=1; i<sizeof_array; i++)
    {
        int status=0;
        for(int j=i; j>0; j--)
        {
            insertion_sort_compare_time++;
            if(s_c[j-1]>s_c[j])
            {
                int temp;
                temp=s_c[j];
                s_c[j]=s_c[j-1];
                s_c[j-1]=temp;
                status=1;
            }
            else
            {
                break;
            }
        }
        if(status==1)
        {
            insertion_sort_exchange_time++;
        }
    }
    char bufff[80]={'\0'};
    snprintf(bufff,80,"Insertion Sort%d.txt",sizeof_array);
    FILE *Insertion_Sort_file=fopen(bufff,"w+");
    fprintf(Insertion_Sort_file,"Insertion Sort Results:\n");
    for(int i=0; i<sizeof_array; i++)
    {
        fprintf(Insertion_Sort_file,"%d ",s_c[i]);
        //printf("%d\n",s_c[i]);
    }
    fflush(Insertion_Sort_file);
    fclose(Insertion_Sort_file);
    //printf("%d %d\n",insertion_sort_compare_time,insertion_sort_exchange_time);
    return insertion_sort_exchange_time;
}
int main()
{
    FILE *inputa=fopen("input.txt","r");
    int s1[500],s2[1000],s3[2000];
    for(int i=0; i<500; i++)
    {
        fscanf(inputa,"%d ",&s1[i]);
    }
    //rewind(inputa);
    for(int i=0; i<1000; i++)
    {
        fscanf(inputa,"%d ",&s2[i]);
    }
    //rewind(inputa);
    for(int i=0; i<2000; i++)
    {
        fscanf(inputa,"%d ",&s3[i]);
    }
    fclose(inputa);

    bubble_sort(s1,500,500);
    selection_sort(s1,500,500);
    insertion_sort(s1,500,500);

    printf("Sequence 1\t\tBubble\t\tSelection\t\tInsertion\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Swap times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_exchange_time,selection_sort_exchange_time,insertion_sort_exchange_time);
    printf("Compare times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_compare_time,selection_sort_compare_time,insertion_sort_compare_time);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    bubble_sort(s2,1000,1000);
    selection_sort(s2,1000,1000);
    insertion_sort(s2,1000,1000);

    printf("Sequence 2\t\tBubble\t\tSelection\t\tInsertion\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Swap times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_exchange_time,selection_sort_exchange_time,insertion_sort_exchange_time);
    printf("Compare times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_compare_time,selection_sort_compare_time,insertion_sort_compare_time);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    bubble_sort(s3,2000,2000);
    selection_sort(s3,2000,2000);
    insertion_sort(s3,2000,2000);

    printf("Sequence 3\t\tBubble\t\tSelection\t\tInsertion\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Swap times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_exchange_time,selection_sort_exchange_time,insertion_sort_exchange_time);
    printf("Compare times\t\t%d\t\t%d\t\t\t%d\n",bubble_sort_compare_time,selection_sort_compare_time,insertion_sort_compare_time);
    printf("-----------------------------------------------------------------------------------------------------------------------\n");

    return 0;
}
