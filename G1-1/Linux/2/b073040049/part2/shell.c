/*
 * shell.c  : test harness for parse routine
 */

#define LONGLINE 255
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "parse.c"
#include "builtin.c"
#include "run_command.c"
#include "is_background.c"
#include <unistd.h>
#include "redirect_in.c"
#include "redirect_out.c"
#include "pipe_command.c"
#include "pipe_present.c"
int main()
{
    char line[LONGLINE];
    int i;
    char **myArgv;
    fputs("myshell -> ", stdout);
    while (fgets(line, LONGLINE, stdin))
    {
        /* Create argv array based on commandline. */
        if (myArgv = parse(line))
        {
            if (is_builtin(myArgv[0]))
            {
		//printf("hello\n");
                do_builtin(myArgv);
            }
            //If command is recognized as a builtin, do it.
            else
            {
                //printf("running command  ");

                run_command(myArgv);
                //wait(0);
            }
            /* Free argv array. */
            free_argv(myArgv);
        }
        fputs("myshell -> ", stdout);
    }
    exit(0);
}