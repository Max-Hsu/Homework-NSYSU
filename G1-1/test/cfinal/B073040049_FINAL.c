#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct PersonalInfo
{
    int ID;
    char name[20];
    int age;
    int gender;
    int birthday[3];
    struct PersonalInfo * left;
    struct PersonalInfo * right;
};
struct PersonalInfo * root;
struct PersonalInfo alllist[100];
void addNew(int ID,char name[],int age,int gender,int birthday[])
{
    //printf("get:%d %s %d %d %d/%d/%d\n",ID,name,age,gender,birthday[0],birthday[1],birthday[2]);
    int i;
    int status;
    struct PersonalInfo * temp_root;
    struct PersonalInfo * going;
    temp_root=root;
    going=temp_root;
    while(temp_root!=NULL)
    {
        if((temp_root->ID)>ID)
        {
            going=temp_root;
            temp_root=temp_root->left;
            status=0;
        }
        else if((temp_root->ID)<ID)
        {
            going=temp_root;
            temp_root=temp_root->right;
            status=1;
        }
    }
    struct PersonalInfo * New;
    New=malloc(sizeof(struct PersonalInfo));
    New->ID=ID;
    strcpy(New->name,name);
    New->age=age;
    New->gender=gender;
    for(i=0; i<3; i++)
    {
        New->birthday[i]=birthday[i];
    }
    New->left=NULL;
    New->right=NULL;
    if(status)
    {
        going->right=New;
    }
    else
    {
        going->left=New;
    }

}
void adder()
{
    int ID;
    char name[20];
    int age;
    int gender;
    int birthday[3];
    int i;
    FILE * test=fopen("data.txt","r+");
    if(test==-1)
    {
        printf("file error\n");
        return ;
    }
    fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2]);
    root=malloc(sizeof(struct PersonalInfo));
    root->ID=ID;
    strcpy(root->name,name);
    root->age=age;
    root->gender=gender;
    for(i=0; i<3; i++)
    {
        root->birthday[i]=birthday[i];
    }
    root->left=NULL;
    root->right=NULL;

    while(fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2])!=EOF)
    {
        //printf("read:%d %s %d %d %d/%d/%d\n",ID,name,age,gender,birthday[0],birthday[1],birthday[2]);
        addNew(ID,name,age,gender,birthday);
    }
}
void test1()
{
    int ID;
    char name[20];
    int age;
    int gender;
    int birthday[3];
    int i;
    FILE * test=fopen("data.txt","a");
    if(test==-1)
    {
        printf("file error\n");
        return ;
    }
    fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2]);
    root=malloc(sizeof(struct PersonalInfo));
    root->ID=ID;
    strcpy(root->name,name);
    root->age=age;
    root->gender=gender;
    for(i=0; i<3; i++)
    {
        root->birthday[i]=birthday[i];
    }
    root->left=NULL;
    root->right=NULL;

    while(fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2])!=EOF)
    {
        //printf("read:%d %s %d %d %d/%d/%d\n",ID,name,age,gender,birthday[0],birthday[1],birthday[2]);
        addNew(ID,name,age,gender,birthday);
    }
    //printf("%d %s %d %d %d/%d/%d\n",ID,name,age,gender,birthday[0],birthday[1],birthday[2]);
    /*
    fclose(test);
    FILE * testa=fopen("data.txt","a");
    if(testa==-1)
    {
        printf("file error\n");
        return ;
    }
    */
    printf("Please input new data\n");
    printf("ID:");
    scanf("%d",&ID);
    printf("Name:");
    scanf("%s",&name);
    printf("Age:");
    scanf("%d",&age);
    printf("Gender:");
    scanf("%d",&gender);
    printf("birthday:");
    scanf("%d %d %d",&birthday[0],&birthday[1],&birthday[2]);
    fprintf(test,"\n%d %s %d %d %d/%d/%d\n",ID,name,age,gender,birthday[0],birthday[1],birthday[2]);
    addNew(ID,name,age,gender,birthday);


    fclose(test);

}
void test2()
{
    int ID;
    scanf("%d",&ID);
    int status=0;
    adder();
    struct PersonalInfo * temp_root;
    struct PersonalInfo * going;
    temp_root=root;
    going=temp_root;
    while(temp_root!=NULL)
    {
        if((temp_root->ID)==ID)
        {
            status=3;
            break;
        }
        else if((temp_root->ID)>ID)
        {
            going=temp_root;
            temp_root=temp_root->left;
            status=0;
        }
        else if((temp_root->ID)<ID)
        {
            going=temp_root;
            temp_root=temp_root->right;
            status=1;
        }
    }
    if(status==3)
    {
        printf("temp %d\n",temp_root->ID);
        if(temp_root->left==NULL)
        {
            temp_root=temp_root->right;
        }
        else if(temp_root->right==NULL)
        {
            temp_root=temp_root->left;
        }
        else
        {
            struct PersonalInfo * q;
            struct PersonalInfo * s;
            q=temp_root;
            s=temp_root->left;
            while(s->right!=NULL)
            {
                q=s;
                s=s->right;
            }
            temp_root->ID=s->ID;
            if(q!=temp_root)
            {
                q->right=s->left;
            }
            else
            {
                q->left=s->left;
            }
            free(s);
        }



    }



}

void test3()
{
    int people_counter=0;
    int ID;
    char name[20];
    int age;
    int gender;
    int birthday[3];
    int i;
    int input;
    int input_choice;
    int input_birthday[3];
    char input_name[20];

    int check_status=0;

    FILE * test=fopen("data.txt","r+");
    if(test==-1)
    {
        printf("file error\n");
        return 1;
    }
    while(fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2])!=EOF)
    {
        alllist[people_counter].ID=ID;
        strcpy(alllist[people_counter].name,name);
        alllist[people_counter].age=age;
        alllist[people_counter].gender=gender;
        for(i=0; i<3; i++)
        {
            alllist[people_counter].birthday[i]=birthday[i];
        }
        alllist[people_counter].left=NULL;
        alllist[people_counter].right=NULL;

        people_counter++;
    }
    fclose(test);
    printf("Please input field to search");
    scanf("%d",&input_choice);
    switch(input_choice)
    {
    case 1:
        printf("please input ID:");
        scanf("%d",&input);
        for(i=0; i<people_counter; i++)
        {
            if(input==alllist[i].ID)
            {
                check_status=1;
                printf("ID:%d\nName:%s\nage:%d\ngender:%d\nbirthday:%d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
            }
        }
        break;
    case 2:
        printf("please input NAME:");
        scanf("%s",input_name);
        for(i=0; i<people_counter; i++)
        {
            if(strcmp(input_name,alllist[i].name)==0)
            {
                check_status=1;
                printf("ID:%d\nName:%s\nage:%d\ngender:%d\nbirthday:%d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
            }
        }
        break;
    case 3:
        printf("please input AGE:");
        scanf("%d",&input);
        for(i=0; i<people_counter; i++)
        {
            if(input==alllist[i].age)
            {
                check_status=1;
                printf("ID:%d\nName:%s\nage:%d\ngender:%d\nbirthday:%d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
            }
        }
        break;
    case 4:
        printf("please input GENDER:");
        scanf("%d",&input);
        for(i=0; i<people_counter; i++)
        {
            if(input==alllist[i].gender)
            {
                check_status=1;
                printf("ID:%d\nName:%s\nage:%d\ngender:%d\nbirthday:%d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
            }
        }
        break;
    case 5:
        printf("please input BIRTHDAY:");

        scanf("%d ",&input_birthday[0]);
        scanf("%d ",&input_birthday[1]);
        scanf("%d",&input_birthday[2]);

        for(i=0; i<people_counter; i++)
        {
            if((input_birthday[0]==alllist[i].birthday[0])&&(input_birthday[1]==alllist[i].birthday[1])&&(input_birthday[2]==alllist[i].birthday[2]))
            {
                check_status=1;
                printf("ID:%d\nName:%s\nage:%d\ngender:%d\nbirthday:%d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
            }
        }
        break;


    }
    if(check_status==0){
        printf("Not found!\n");
    }
}
void test4()
{
    int i;
    int status=0;
    int ID;
    char name[20];
    int age;
    int gender;
    int birthday[3];
    int people_counter=0;
    adder();

    printf("please input modify ID");
    scanf("%d",&ID);
    struct PersonalInfo * temp_root;
    struct PersonalInfo * going;
    temp_root=root;
    going=temp_root;
    while(temp_root!=NULL)
    {
        if((temp_root->ID)==ID)
        {
            status=3;
            break;
        }
        else if((temp_root->ID)>ID)
        {
            going=temp_root;
            temp_root=temp_root->left;
            status=0;
        }
        else if((temp_root->ID)<ID)
        {
            going=temp_root;
            temp_root=temp_root->right;
            status=1;
        }
    }
    if(status==3)
    {
        FILE * test=fopen("data.txt","r+");
        if(test==-1)
        {
            printf("file error\n");
            return 1;
        }
        rewind(test);
        while(fscanf(test,"%d %s %d %d %d/%d/%d\n",&ID,name,&age,&gender,&birthday[0],&birthday[1],&birthday[2])!=EOF)
        {
            alllist[people_counter].ID=ID;
            strcpy(alllist[people_counter].name,name);
            alllist[people_counter].age=age;
            alllist[people_counter].gender=gender;
            for(i=0; i<3; i++)
            {
                alllist[people_counter].birthday[i]=birthday[i];
            }
            alllist[people_counter].left=NULL;
            alllist[people_counter].right=NULL;

            people_counter++;
        }
        fclose(test);
        printf("Please input modify data\n");
        printf("Name:");
        scanf("%s",&name);
        printf("Age:");
        scanf("%d",&age);
        printf("Gender:");
        scanf("%d",&gender);
        printf("birthday:");
        scanf("%d %d %d",&birthday[0],&birthday[1],&birthday[2]);
        temp_root->ID=ID;
        strcpy(temp_root->name,name);
        temp_root->age=age;
        temp_root->gender=gender;
        for(i=0; i<3; i++)
        {
            temp_root->birthday[i]=birthday[i];
        }

        for(i=0; i<people_counter; i++)
        {
            if(ID==alllist[i].ID)
            {
                alllist[i].ID=ID;
                strcpy(alllist[i].name,name);
                alllist[i].age=age;
                alllist[i].gender=gender;
                alllist[i].birthday[0]=birthday[0];
                alllist[i].birthday[1]=birthday[1];
                alllist[i].birthday[2]=birthday[2];
            }
        }

        FILE * Modify=fopen("data.txt","w+");
        for(i=0;i<people_counter;i++){
        fprintf(Modify,"%d %s %d %d %d/%d/%d\n",alllist[i].ID,alllist[i].name,alllist[i].age,alllist[i].gender,alllist[i].birthday[0],alllist[i].birthday[1],alllist[i].birthday[2]);
        }
        fclose(Modify);
    }


}
int main()
{
    int sele=-3;
    while(sele!=5)
    {
        printf("1.add\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("4.modify\n");
        printf("5.exit\n");

        scanf("%d",&sele);
        switch(sele)
        {

        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        case 4:
            test4();
            break;


        }


    }
    return 0;
}
