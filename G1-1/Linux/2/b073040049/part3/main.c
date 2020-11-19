/*
 * The same main will do to test all the versions  of  lookup.   The
 * argument  to  main  is  always  passed  as the second argument to
 * lookup. It identifies the resource needed by lookup to  find  its
 * answers.  It  might be a file name or a named pipe, or the key to
 * some shared memory or a message queue, etc. The point is,  it  is
 * just  a  string;  main does not need to understand how the string
 * will be used. The work involved in each  exercise  is  to  define
 * lookup in different ways. What is the same throughout is that the
 * FIRST time lookup is called, it may have to open some resource. A
 * static internal flag is used to determine whether or not this was
 * the first call.
 */

#include <errno.h>
#include <stdlib.h>
#include "dict.h"
#include <string.h>
//#include "lookup1.c"


int main(int argc, char **argv) {
	Dictrec tryit;

	if (argc != 2) {
		fprintf(stderr,"Usage : %s <resource>\n",argv[0]);
		exit(errno);
	}

	while(1) {
		printf("What word do you want : ");
		fgets(tryit.word,sizeof(tryit.word),stdin);
		switch(lookup(&tryit,argv[1]) ) {
			case FOUND:
			    tryit.word[strlen(tryit.word)-1]='\0';
				printf("%s : %s\n",tryit.word,tryit.text);
				break;
			case NOTFOUND:
			    tryit.word[strlen(tryit.word)-1]='\0';
				printf("%s : Not Found!\n",tryit.word) ;
				break;
			case UNAVAIL:
				DIE(argv[1]);
		}
	}
}
int lookup(Dictrec * sought, const char * resource) {
	//Dictrec dr;
	static FILE * in;
	static int first_time = 1;

	if (first_time) {
		first_time = 0;
		/* open up the file
		 *
		 * Fill in code. */
		if((in=fopen(resource,"r"))==0){
                printf("err");
		perror("open error");
		}
	}

	/* read from top of file, looking for match
	 *
	 * Fill in code. */
	rewind(in);
	char oput[32];
	char oput_t[480];
	char searchs[1000]={' '};
	while(fgets(searchs,1000,in)) {
		/* Fill in code. */

		if(strncmp(searchs,sought->word,strlen(sought->word)-1)==0){
        //printf("found \n");
        char newtext[480];
        for(int e=WORD;e<TEXT+WORD-1;e++){
            newtext[e-WORD]=searchs[e];
        }
		strcpy(sought->text,newtext);

		return FOUND;
		}
	}

	return NOTFOUND;
}
