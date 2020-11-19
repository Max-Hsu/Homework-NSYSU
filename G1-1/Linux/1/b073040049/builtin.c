/*
 * builtin.c : check for shell built-in commands
 * structure of file is
 * 1. definition of builtin functions
 * 2. lookup-table
 * 3. definition of is_builtin and do_builtin
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"




/****************************************************************************/
/* builtin function definitions                                             */
/****************************************************************************/
void exitquit(char **argv)
{
    exit(0);
}
/* "echo" command.  Does not print final <CR> if "-n" encountered. */
static void bi_echo(char **argv)
{
    /* Fill in code. */
    if(strcmp("-n",argv[1])==0)
    {
        int num2=atoi(argv[2]);
        puts(argv[num2+2]);
    }
    else
    {
        int coou=1;
        while(argv[coou]!=NULL)
        {
            printf("%s\t",argv[coou]);
            coou++;
        }
        printf("\n");
    }
}
/* Fill in code. */




/****************************************************************************/
/* lookup table                                                             */
/****************************************************************************/

static struct cmd
{
    char * keyword;				/* When this field is argv[0] ... */
    void (* do_it)(char **);	/* ... this function is executed. */
} inbuilts[] =
{
    /* Fill in code. */
    {"bye",exitquit},
    {"quit",exitquit},
    {"logout",exitquit},
    {"exit",exitquit},
    {"echo", bi_echo},		/* When "echo" is typed, bi_echo() executes.  */
    { NULL, NULL }				/* NULL terminated. */
};




/****************************************************************************/
/* is_builtin and do_builtin                                                */
/****************************************************************************/

static struct cmd * this; 		/* close coupling between is_builtin & do_builtin */

/* Check to see if command is in the inbuilts table above.
Hold handle to it if it is. */
int is_builtin(char *cmd)
{
    struct cmd *tableCommand;

    for (tableCommand = inbuilts ; tableCommand->keyword != NULL; tableCommand++)
        if (strcmp(tableCommand->keyword,cmd) == 0)
        {
            this = tableCommand;
            return 1;
        }
    return 0;
}


/* Execute the function corresponding to the builtin cmd found by is_builtin. */
int do_builtin(char **argv)
{
    this->do_it(argv);
}
