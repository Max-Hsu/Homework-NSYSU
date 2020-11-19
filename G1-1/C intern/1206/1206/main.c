#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STDA 5
#define MAXLEN 20
typedef struct Student{
char id[6];
char name[MAXLEN];
float score;
}Student;
Student all[STDA];
void inputa(Student *in)
{
    for(int i=0;i<5;i++){
        printf("Please input NO. %d student's ID: ",i+1);
        int id;
        scanf("%d",&id);
        char buf[6];
        snprintf(buf,6,"%d",id);
        strcpy(all[i].id,buf);
        printf("Please input NO. %d student's Name: ",i+1);
        char namebuf[MAXLEN];
        scanf("%s",namebuf);
        strcpy(all[i].name,namebuf);
        printf("Please input NO. %d student's Score: ",i+1);
        float sc;
        scanf("%f",&sc);
        all[i].score=sc;
    }

}
void outputa(Student *in){
    for(int i=0;i<5;i++){
        printf("student %d\n",i+1);
        int id=atoi(all[i].id);
        printf("ID:%d\n",id);
        printf("Name: ");
        printf("%s\n",all[i].name);
        printf("Score: ");
        printf("%f\n",all[i].score);
        printf("\n\n");
    }
}
int number1(Student *in){
    int max=0,max_n=0;
    for(int i=0;i<5;i++){
        float sc=all[i].score;
        if(max<sc){
            max=sc;
            max_n=i;
        }
    }
    printf("%s get No.1 in this exam\n",all[max_n].name);
}
void Fail(Student * in){
    printf("Fail students:\n");
        for(int i=0;i<5;i++){
        float sc=all[i].score;
        if(sc<60){
                printf("%s\n",all[i].name);
        }
    }
}
int main()
{

    inputa(all);
    outputa(all);
    number1(all);
    Fail(all);
    return 0;
}
