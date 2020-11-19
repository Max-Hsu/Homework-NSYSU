#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	int fd[2];
	char x[100000];
	pid_t pid;
	pipe(fd);
	pid=fork();

	if(pid==0){
	close(1);
	dup2(fd[1],1);
	close(fd[0]);
	execlp("ls","ls","-l",NULL);
	}	


	else if(pid>0){
	close(0);
	dup2(fd[0],0);
	close(fd[1]);
	read(fd[0],x,100000);
	printf("%s",x);
	}

}
