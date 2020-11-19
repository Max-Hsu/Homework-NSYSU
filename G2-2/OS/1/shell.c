#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char ** cut_char_segment(char * input){
    static char * cut[20];
    int cut_index = 0;
    char * temp;
    temp = strtok(input," \n");
    while(temp != NULL){
        //printf("%s\n",temp);
        cut[cut_index] = temp;
        temp = strtok(NULL," \n");
        //printf("%d",cut_index);
        cut_index += 1;
    }
    for(;cut_index<20;cut_index++){
        cut[cut_index] = NULL;
    }
    return cut;
}
int main(void){
    char input[2000];
    char ** split_argv;
    int error_or_exit = 1;
    while(error_or_exit){
        printf("shell->");
        fgets(input,200,stdin);
        split_argv = cut_char_segment(input);
        int status_pipe = 0;
        int status_redirection_input = 0;
        int status_redirection_output = 0;
        int status_background = 0;
        int run_through_index = 0;
        int seperate_index;
        while(split_argv[run_through_index]!=NULL){
            //printf("%s %ld \n",split_argv[run_through_index],strlen(split_argv[run_through_index]));
            if(strncmp(split_argv[run_through_index],"<\0",1)==0 && strlen(split_argv[run_through_index])==1){
                status_redirection_input = 1;
                seperate_index = run_through_index;
            }
            else if(strncmp(split_argv[run_through_index],">\0",1)==0 && strlen(split_argv[run_through_index])==1){
                status_redirection_output = 1;
                seperate_index = run_through_index;
            }
            else if(strncmp(split_argv[run_through_index],"|\0",1)==0 && strlen(split_argv[run_through_index])==1){
                status_pipe = 1;
                seperate_index = run_through_index;
            }
            else if(strncmp(split_argv[run_through_index],"&\0",1)==0 && strlen(split_argv[run_through_index])==1){
                status_background = 1;
            }
            run_through_index += 1;
        }
        //printf("%s\n",input);
        //printf("%d %d %d %d\n",status_pipe , status_redirection_input , status_redirection_output , status_background);
        //printf("%d",run_through_index);
        if(status_background){
            __pid_t pid;
            int status;
            split_argv[run_through_index-1] = NULL;
            if ((pid = fork())<0)
            {
                perror("fork error");
            }
            else if(pid == 0){
                execvp(split_argv[0],split_argv);
            }
        }
        else{ //here means no background
            if(status_pipe||status_redirection_input||status_redirection_output){
                char * split_argv_left[20]={NULL};
                char * split_argv_right[20]={NULL};
                /*
                char * testing_ls[] = {"ls","-l",NULL};
                char * testing_wc[] = {"wc","-l",NULL};
                */
                for(int i = 0 ; i < run_through_index ; i++){
                    if( i < seperate_index){
                        split_argv_left[i] = split_argv[i];
                        //printf("l: %s \n",split_argv_left[i]);
                    }
                    else if( i > seperate_index){
                        split_argv_right[i-seperate_index-1] = split_argv[i];
                        //printf("r: %s \n",split_argv_right[i-seperate_index-1]);
                    }
                    split_argv_left[seperate_index] = NULL;
                    split_argv_right[run_through_index-seperate_index] = NULL;
                }
                if(status_pipe){
                    int fd[2];
                    if(pipe(fd)<0){
                        perror("piping error");
                    }
                    __pid_t pid;
                    __pid_t pid2;
                    int status;
                    if ((pid = fork())<0)
                    {
                        perror("fork error");
                    }
                    else if(pid == 0){  //I am child
                        //close(STDOUT_FILENO);
                        dup2(fd[1],1);
                        close(fd[0]);
                        execvp(split_argv_left[0],split_argv_left);
                    }
                    else{               //I am parent
                        waitpid(pid,&status,0);
                        if(((pid2) = fork())<0){
                            perror("fork error");
                        }
                        else if(pid2 == 0){
                            //close(STDIN_FILENO);
                            close(fd[1]);
                            dup2(fd[0],0);
                            execvp(split_argv_right[0],split_argv_right);
                        }
                        else{
                            close(fd[0]);
                            close(fd[1]);
                            waitpid(pid2,&status,0);
                        }
                        //execvp(testing_wc[0],testing_wc);
                    }
                }
                if(status_redirection_output){
                    __pid_t pid;
                    int status;
                    if((pid = fork())<0){
                        perror("fork error");
                    }
                    else if (pid == 0){
                        
                        FILE * readfile = fopen(split_argv_right[0],"w+");
                        freopen(split_argv_right[0],"w",stdout);
                        execvp(split_argv_left[0],split_argv_left);
                        fclose(readfile);
                        fclose(stdout);
                    }
                    else{
                        wait(&status);
                    }
                }
                if(status_redirection_input){
                    __pid_t pid;
                    int status;
                    if((pid = fork())<0){
                        perror("fork error");
                    }
                    else if (pid == 0){
                        
                        FILE * readfile = fopen(split_argv_right[0],"r");
                        freopen(split_argv_right[0],"r",stdin);
                        execvp(split_argv_left[0],split_argv_left);
                        fclose(readfile);
                        fclose(stdin);
                    }
                    else{
                        wait(&status);
                    }
                }
            }
            else{
                __pid_t pid;
                int status;
                if ((pid = fork())<0)
                {
                    perror("fork error");
                }
                else if(pid == 0){
                    execvp(split_argv[0],split_argv);
                }
                else{
                    wait(&status);
                }
            }
        }
        //printf("at least here\n");
        //error_or_exit = 0;
    }
    
    return 0;
}