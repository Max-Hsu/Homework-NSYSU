/*
 * lookup5 : local file ; setup a memory map of the file
 *           Use bsearch. We assume that the words are already
 *           in dictionary order in a file of fixed-size records
 *           of type Dictrec
 *           The name of the file is what is passed as resource
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include "dict.h"

/*
 * This obscure looking function will be useful with bsearch
 * It compares a word with the word part of a Dictrec
 */
typedef struct {
    char word[WORD];  /* The word to be looked up */
    long off;         /* Offset into file for word definition */
} Index;

int dict_cmp(const void *a,const void *b) {
    return strcmp((char *)a,((Dictrec *)b)->word);
}

int lookup(Dictrec * sought, const char * resource) {
    struct stat buff;
    char *a;
    a=(char *)malloc(1000*sizeof(char));
    getcwd(a,1000);
	static Index * table;
	Dictrec dr;
	static int numrec;
	int i;
	Index * found,tmp;
	static FILE * in;
	static int first_time = 1;
    strcat(a,"/");
    strcat(a,resource);
    int file_des=open(resource,O_RDONLY);
	if (first_time) { /* set up index */
		first_time = 0;

		/* Open file.
		 *
		 * Fill in code. */
        stat(a,&buff);
        int file_size;
        file_size=buff.st_size;
        //printf("%d",file_size);
		/* Get number records in file by dividing ending file offset by recsize.
		 *
		 * Fill in code. */
        lseek(file_des,0,SEEK_SET);
		/* Go to the beginning of the file.
		 *
		 * Fill in code. */
        //printf("size:%ld",sizeof(Index));
        numrec=file_size/(WORD+TEXT);
		/* Allocate zeroed-out memory: numrec elements of struct Index. */
		table = calloc(sizeof(Index),numrec);
        for(int i=0;i<numrec;i++){
            char buf_word_text[512];
            read(file_des,buf_word_text,512);
            //printf("%s\n",buf_word_text);
            strncpy(table[i].word,buf_word_text,WORD);
            table[i].off=i*512;
            //printf("%s\n",table[i].word);
        }
		/* Read the file into the just-allocated array in memory.
		 *
		 * Fill in code. */

		/* Sort the table of entry/offset Index structures. */
		qsort(table,numrec,sizeof(Index),dict_cmp);

	} /* end of first-time initialization */

	/* use bsearch to find word in the table; seek & read from file if found. */
	strcpy(tmp.word,sought->word);
	found = bsearch(&tmp,table,numrec,sizeof(Index),dict_cmp);

    //printf("%s",found->word);
	/* If found, go to that place in the file, and read the record into the
	 * caller-supplied space. */
	if (found) {
        lseek(file_des,0,SEEK_SET);
        //printf("%ld",(found->off)+WORD);
        lseek(file_des,((found->off)+WORD),SEEK_SET);
	    char found_text[TEXT];
        read(file_des,found_text,TEXT);
        strcpy(sought->text,found_text);
		/* Fill in code. */
		//printf("found!!\n");
		return FOUND;
	}
	return NOTFOUND;
}

