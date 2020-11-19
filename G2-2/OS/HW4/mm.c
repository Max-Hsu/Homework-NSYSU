#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mm.h"
#define NALLOC 1024

static header base;
static header *freep=NULL;

header *morecore(unsigned nu)
{
    char *cp;
    header *up;
    if(nu<NALLOC){
        nu=NALLOC;
    }
    cp=(char*)sbrk(nu * sizeof(header));

    if(cp==(char*)-1){
        return NULL;
    }
    up=(header*) cp;
    up->s.size=nu;
    myfree((void*) (up+1));
    return freep;
}

void  *mymalloc ( size_t size_use )
{
    header *p,*prevp=NULL; //p will be current processing header , prevp is also freep (the whole free block list)
    unsigned nunits;

    nunits=(size_use+sizeof(header)-1)/sizeof(header)+1;
    if((prevp=freep)==NULL) //init
    {
        base.s.ptr=freep=prevp=&base;
        base.s.size=0;
    }
    for(p=prevp->s.ptr;; prevp=p,p=p->s.ptr) 
    {
        if(p->s.size>=size_use)
        {
            //printf("HI\n");
            if(p->s.size==size_use)
                prevp->s.ptr=p->s.ptr;
            else
            {
                p->s.size-=size_use;
                p+=p->s.size;
                p->s.size=size_use;
            }
            freep=prevp;
            return (void*)(p+1);
        }
        if(p==freep) //init
        {
            //printf("here");
            if((p=morecore(nunits))==NULL)
                return NULL;
        }
    }
}

void myfree ( void * ptr )
{
    header *bp,*p;

    bp=(header*)ptr-1;//bp is pointer to the next free block , see structure of text book
    for(p=freep; !(bp>p && bp < p->s.ptr); p=p->s.ptr)      //edge check
        if( p>=p->s.ptr && ( bp > p || bp < p->s.ptr) )
            break;

    //merge upper free_block
    //printf("\n%p %p\n",p,bp);
    if(bp+bp->s.size==p->s.ptr)
    {   
        //printf("upper");
        bp->s.size+=p->s.ptr->s.size;
        bp->s.ptr=p->s.ptr->s.ptr;
    }
    else{
        //printf("no");
        bp->s.ptr=p->s.ptr;
    }


    //merge lower free_block
    if(p+p->s.size==bp)
    {
        //printf("below");
        p->s.size+=bp->s.size;
        p->s.ptr=bp->s.ptr;
    }
    else{
        //printf("no");
        p->s.ptr=bp;
    }
    freep=p;
}

void  *mycalloc ( size_t sizeOfBlock, size_t size )
{
    void *p;
    int total_size=size*sizeOfBlock;
    p=mymalloc(total_size);
    memset(p,0,total_size);
    return p;
}

void  *myrealloc ( void * ptr, size_t size )
{
    void *temp;
    temp=mymalloc(size);
    memcpy(temp,ptr,size);
    myfree(ptr);
    return temp;
}