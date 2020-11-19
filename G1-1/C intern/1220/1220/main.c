#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node * back;
    int value;
    struct node * next;
};
struct node * head=NULL;
struct node * tail=NULL;
int checkaa=0;
int anss[1000]={0};
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
        newa->next=head;
        newa->value=value;
        newa->back=NULL;
        head->back=newa;
        head=newa;
    }
}
void print_all()
{
    struct node * aaa;
    aaa=tail;
    while(aaa->back!=NULL)
    {
        printf("%d ",aaa->value);
        aaa=aaa->back;
        checkaa++;
    }
    printf("%d ",aaa->value);
    checkaa++;

}
void checka()
{
    for(int a=0; a<checkaa; a++)
    {
        for(int b=0; b<checkaa; b++)
        {
            struct node * aaa;
            struct node * bbb;
            aaa=head;
            bbb=head;
            for(int i=0; i<a; i++)
            {
                aaa=aaa->next;
            }
            for(int i=0; i<b; i++)
            {
                bbb=bbb->next;
            }
            if(a!=b){
                if(aaa!=NULL&&bbb!=NULL){
                if(aaa->value==bbb->value){
                    bbb->back->next=bbb->next;
                    bbb->next->back=bbb->back;
                    //printf("%x\n",aaa);
                    //printf("%x\n",bbb);
                }
                }
            }
        }
    }
}


void print_all_a()
{
    struct node * aaa;
    aaa=tail;
    while(aaa->back!=NULL)
    {
        if(anss[aaa->value]==0){
        printf("%d ",aaa->value);
        anss[aaa->value]++;
        aaa=aaa->back;
        checkaa++;

        }
    }
    if(anss[aaa->value]==0){
    printf("%d ",aaa->value);
    }

    checkaa++;

}
int main()
{
    for(int i=0;i<1000;i++){
        anss[i]=0;
    }

    int value;
    while(scanf("%d",&value)!=EOF)
    {
        insert_node(value);
    }
    print_all();
    //checka();
    printf("\n");
    print_all_a();


    return 0;
}
