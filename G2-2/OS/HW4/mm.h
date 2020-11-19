#ifndef __MY_MM_H_INCLUDED__
#define __MY_MM_H_INCLUDED__

#include <stdio.h> 

typedef long Align;
typedef union Header{
   struct{
       union Header *ptr;
       unsigned size;
   }s;
   Align x;
}header;

char* sbrk(int);

void *mymalloc ( size_t size_use );
void myfree ( void * ptr );
void *myrealloc ( void *ptr, size_t size );
void *mycalloc ( size_t sizeOfBlock, size_t size );


header *morecore(unsigned nu);

#endif