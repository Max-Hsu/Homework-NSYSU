/*
 * run_command.c :    do the fork, exec stuff, call other functions
 */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include "shell.h"

void run_command(char **myArgv) {
  	pid_t pid;
  	int stat;
  	int run_in_background;

  	/*
   	* Check for background processing.
   	* Do this before fork() as the "&" is removed from the argv array
   	* as a side effect.
   	*/
   	//printf("now 1");
  	run_in_background = is_background(myArgv);
  	int statusa=-1;
    int statusb=-1;

  	switch(pid = fork()) {

    	/* Error. */
    	case -1 :
      		perror("fork");
      		exit(errno);

    	/* Parent. */
    	default :
    	    wait(0);
      		if (!run_in_background) {
        		waitpid(pid,&stat,0);	 Wait for child to terminate.

        		if (WIFEXITED(stat) && WEXITSTATUS(stat)) {
          			fprintf(stderr, "Child %d exited with error status %d: %s\n",
	      				pid, WEXITSTATUS(stat), (char*)strerror(WEXITSTATUS(stat)));

        		} else if (WIFSIGNALED(stat) && WTERMSIG(stat)) {
	  				fprintf (stderr, "Child %d exited due to signal %d: %s\n",
	      				pid, WTERMSIG(stat), (char*)strsignal(WTERMSIG(stat)));
        		}
      		}
            return;
    	/* Child. */
    	case 0 :

    	    printf("1 ");
            statusa=redirect_in(myArgv);
            printf("2 ");
            statusb=redirect_out(myArgv);
      		// Redirect input and update argv.

      		 //Redirect output and update argv.
            printf("3 \n");
            //pipe_and_exec(myArgv);
      		printf("4 ");


            if(statusa==0){
                    printf("no <");
                    execvp(myArgv[0],myArgv);
            }

      		//wait(0);
      		exit(0);
      		exit(errno);
	}
}
