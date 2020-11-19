CC	=	gcc
CFLAGS	=	-Wall	-std=c11	-g
PROGS	=	mm
all:	mm	test
mm:
	$(CC)	$(CFLAGS)	-c	mm.c
test:
	$(CC)	$(CFLAGS)	-c	test.c
	$(CC)	$(CFLAGS)	-o 	test	test.o	mm.o
.PHONY:clean
clean:
	-rm -f test *.o	$(PROGS).dep
dep:
	$(CC)	$(CFLAGS)	$(PROGS).c	-MM	>	$(PROGS).dep
