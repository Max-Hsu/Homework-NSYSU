CC	=	g++
CFLAGS	=	-Wall	-pthread
PROGS	=	dining_polling

all:
	$(CC)	$(CFLAGS)	-c	$(PROGS).cpp
	$(CC)	$(CFLAGS)	-o	$(PROGS)	$(PROGS).o

.PHONY:clean
clean:
	-rm $(PROGS).o	$(PROGS).dep

dep:
	$(CC)	$(CFLAGS)	$(PROGS).cpp	-MM	>	$(PROGS).dep
