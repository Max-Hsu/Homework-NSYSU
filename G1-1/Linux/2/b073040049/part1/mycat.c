#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc,char *argv[]){
	if(argc>2){
		printf("Usage: mycat filename\n");
	}
	else{
	pid_t pid;
	pid=fork();
		if(pid==0){
			printf("%s",argv[1]);
			execvp("cat",argv);
			//_exit(0);
			}
	waitpid(pid,NULL,0);
	//exit(0);
	}
return 0;
}
