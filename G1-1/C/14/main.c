#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node * back;
    int value;
    struct node * next;
};
struct node * head=NULL;
struct node * tail=NULL;
void insert_node(int value)
{
    if(head==NULL&&tail==NULL)
    {
        head=malloc(sizeof(struct node));
        tail=head;
        head->next=NULL;
        head->value=value;
    }
    else
    {
        struct node * newa;
        newa=malloc(sizeof(struct node));
        if(value>head->value)
        {
            newa->next=head;
            newa->value=value;
            newa->back=NULL;
            head->back=newa;
            head=newa;
        }
        else if(value<tail->value)
        {
            tail->next=newa;
            newa->back=tail;
            newa->next=NULL;
            newa->value=value;
            tail=newa;
        }
        else
        {
            struct node * aaa;
            aaa=head;
            while(aaa->value>=value)
            {
                if(aaa->value==value)
                {
                    printf("%d is already in list\n",value);
                    return;
                }
                aaa=aaa->next;
            }
            aaa=aaa->back;
            newa->next=aaa->next;
            aaa->next=newa;
            newa->back=aaa;
            newa->next->back=newa;
            newa->value=value;
        }
    }
}
void print_all()
{
    struct node * aaa;
    aaa=tail;
    printf("List:");
    while(aaa->back!=NULL)
    {
        printf("%d ",aaa->value);
        aaa=aaa->back;

    }
    printf("%d\n",aaa->value);

}
void deletea(int value)
{
    if(value>head->value)
    {
        printf("No %d\n",value);
    }
    else if(value<tail->value)
    {
        printf("No %d\n",value);
    }
    else
    {
        struct node * aaa;
        struct node * bbb;
        aaa=head;
        while(aaa->value>=value)
        {
            if(aaa->value==value)
            {

                //printf("%x %d remove\n",aaa,value);
                aaa=aaa->back;
                //printf("%x\n",aaa);
                aaa->next=aaa->next->next;
                aaa->next->back=aaa;
                //aaa=aaa->next;

                return;
            }
            aaa=aaa->next;
            //printf("%x\n",aaa);
            if(aaa->next==NULL){
                printf("NO %d in list\n",value);
                return;
            }
        }

    }


}

int main()
{
    int input_num;
    FILE * input =fopen("input.txt","r+");
    if(input==-1)
    {
        perror("file");
        return 1;
    }
    fscanf(input,"%d\n",&input_num);
    printf("Insert the original numbers.\n");
    for(int i=0; i<input_num; i++)
    {
        int inputa;
        fscanf(input,"%d ",&inputa);
        insert_node(inputa);
    }


    print_all();
    char task[10];
    int numa;
    while(fscanf(input,"%s %d",task,&numa)!=EOF)
    {
        printf("------------------------------------------------\n");
        printf("%s %d.\n",task,numa);
        if(strcmp(task,"insert")==0)
        {
            insert_node(numa);
            print_all();
        }
        else if(strcmp(task,"delete")==0)
        {
            deletea(numa);
            print_all();
        }
    }
    //checka();
    //printf("\n");
    //print_all_a();
    printf("------------------------------------------------\n");
    printf("Finish total input.\n");
    fclose(input);
    return 0;
}
