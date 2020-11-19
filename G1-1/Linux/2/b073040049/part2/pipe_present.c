/*
 *  pipe_present.c :  check for |
 */

#include <stdio.h>
#include "shell.h"

/*
 * Return index offset into argv of where "|" is,
 * -1 if in an illegal position (first or last index in the array),
 * or 0 if not present.
 */
int pipe_present(char ** myCurrentArgv) {
	int index = 0;
	int position=0;
	while(myCurrentArgv[index]!=0){
        if(strcmp(myCurrentArgv[index],"|")==0){
            position=index;
        }
        index++;
	}
  	/* Search through myCurrentArgv for a match on "|". */

  	if (position==0){

    	return -1;

  	}
  	else if (position==index) {
    	return 0;

  	} else {
    	index=position;
    	return index;
  	}
}
