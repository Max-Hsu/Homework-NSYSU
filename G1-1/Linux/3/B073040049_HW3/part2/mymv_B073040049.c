#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main( int argc, char* argv[] ) {
    struct stat buff;
    char *a;
    a=(char *)malloc(1000*sizeof(char));
    getcwd(a,1000);
    char *b;
    b=(char *)malloc(1000*sizeof(char));
    getcwd(b,1000);
    strcat(b,"/");
    strcat(b,argv[2]);
    stat(b,&buff);
    //argv[2]=dir?
    if(S_ISDIR(buff.st_mode)){
    //printf("is dir");
    strcat(a,"/");
    strcat(a,argv[1]);
    strcat(b,"/");
    strcat(b,argv[1]);
    //printf("%s\n",a);
    //printf("%s\n",b);
    int fd_old,fd_new;
    fd_new=open(b,O_WRONLY | O_CREAT | O_TRUNC);
    fd_old=open(a,O_RDONLY);
    char buf[100];
    int readin;
    while((readin=read(fd_old,buf,100))>0){
        write(fd_new,buf,readin);
    }
    close(fd_new);
    close(fd_old);
    remove(a);
    }
    else{
    if(open(b,O_RDONLY)>0){
        printf("mymv: overwrite '%s' ? ",argv[2]);
        char inputa;
        scanf("%c",&inputa);
        if(inputa=='Y'||inputa=='y'){
        }
        else if(inputa=='N'||inputa=='n'){
            exit(0);
        }
        else{
            printf("wrong input\n");
            exit(0);
        }
    }
    strcat(a,"/");
    strcat(a,argv[1]);
    rename(a,b);
    }

	return 0;
}
