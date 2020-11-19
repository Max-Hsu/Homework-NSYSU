#include <stdio.h>
#include <stdlib.h>
int compare(char s1[],char s2[]){
    if(strlen(s1)>strlen(s2)){
        printf("%s\n",s1);
        return 1;
    }
    else{
        printf("%s\n",s2);
        return 0;
    }
}
void Reversea(char s1[]){
    int rrr=strlen(s1);
    char s3[10];
    int aa,bb;
    aa=0;
    bb=rrr-1;
    for(int i=0;i<rrr;i++){
        s3[aa]=s1[bb];
        aa++;
        bb--;
    }
    s3[rrr]='\0';

    printf("%s\n",s3);

}
int main()
{
    char s1[10];
    char s2[10];
    gets(s1);
    gets(s2);
    int ans=compare(s1,s2);
    if(ans){
        Reversea(s1);
    }
    else{
        Reversea(s2);
    }
    return 0;
}
