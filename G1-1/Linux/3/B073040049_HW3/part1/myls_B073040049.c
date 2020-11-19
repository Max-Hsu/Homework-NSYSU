#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

void list_directory( char *dir_path,int flags );
char **alldict;
int alldict_counter=0;
int now_alldict=0;
int main( int argc, char* argv[] )
{

    alldict=(char**)malloc(100000);
    char *a;
    a=(char *)malloc(1000*sizeof(char));
    getcwd(a,1000);
    int flags=0;
    if(argc>1)
    {
        if(strcmp(argv[1],"-FR")==0||strcmp(argv[1],"-RF")==0||strcmp(argv[1],"-fr")==0||strcmp(argv[1],"-rf")==0)
        {
            flags=1;
            //printf("WOW");
        }
        else if(strcmp(argv[1],"-R")==0||strcmp(argv[1],"-r")==0)
        {
            flags=2;

        }
        else if(strcmp(argv[1],"-F")==0||strcmp(argv[1],"-f")==0)
        {
            flags=3;

        }
        else
        {
            strcat(a,"/");
            strcat(a,argv[1]);
            printf("%s : \n",a);
        }
    }
    list_directory(a,flags);
    return 0;
}

void list_directory( char *dir_path,int flags )
{
    struct stat buf;
    DIR *dirp;
    struct dirent *dent;
    dirp=opendir(dir_path);
    if (dirp==NULL)
    {
        printf("%s",dir_path);
        perror("error");
        exit(1);
    }
    else
    {
        while (dent = readdir(dirp))
        {

            if(strcmp(dent->d_name,".")==0||strcmp(dent->d_name,"..")==0)
            {
            }
            else
            {
                if(dent->d_type==4)
                {
                    char *b;
                    b=(char *)malloc(1000*sizeof(char));
                    char *c;
                    c=(char *)malloc(1000*sizeof(char));
                    getcwd(b,1000);
                    //printf("now path %s \n",b);
                    //printf("call path %s \n",dir_path);
                    if(strcmp(b,dir_path)==0)
                    {
                        strcat(b,"/");
                        strcat(b,dent->d_name);
                        alldict[alldict_counter]=b;
                        //printf("%d    %s",alldict_counter,alldict[alldict_counter]);
                        alldict_counter++;
                    }

                    else
                    {
                        strcpy(c,dir_path);
                        strcat(c,"/");
                        strcat(c,dent->d_name);
                        alldict[alldict_counter]=c;
                        //printf("%d    %s",alldict_counter,alldict[alldict_counter]);
                        alldict_counter++;
                    }
                }
                if(flags==1||flags==3)
                {
                    printf("%s", dent->d_name);

                    if(dent->d_type==4)
                    {
                        printf("/\n");
                    }
                    if(dent->d_type==8)
                    {

                        printf("*\n");
                    }
                }
                else
                {
                    printf("%s\n", dent->d_name);
                }
            }
        }
        closedir(dirp);
        //printf("%d",alldict_counter);
        if(flags==1||flags==2)
        {
            while(now_alldict<alldict_counter)
            {
                printf("%s\n",alldict[now_alldict]);

                now_alldict++;
                list_directory(alldict[now_alldict-1],flags);

            }
        }
    }
}
