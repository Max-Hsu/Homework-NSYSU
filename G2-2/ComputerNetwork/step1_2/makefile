CC	=	g++
CFLAGS	=	-Wall	-std=c++11	-g	-pthread
PROGS	=	server	client
all:TcpHeader	server-thread	server	client
TcpHeader:
	$(CC)	$(CFLAGS)	-c	TcpHeader.cpp
server-thread:
	$(CC)	$(CFLAGS)	-c	server-thread.cpp
server:
	$(CC)	$(CFLAGS)	-c	server.cpp
	$(CC)	$(CFLAGS)	-o 	server	server.o	TcpHeader.o	server-thread.o
client:
	$(CC)	$(CFLAGS)	-c	client.cpp
	$(CC)	$(CFLAGS)	-o 	client	client.o	TcpHeader.o	server-thread.o
.PHONY:clean
clean:
	-rm -f $(PROGS) *.o	$(PROGS).dep
dep:
	$(CC)	$(CFLAGS)	server.cpp	-MM	>	server.dep
	$(CC)	$(CFLAGS)	client.cpp	-MM	>	client.dep
.PHONY:clientclean
clientclean:
	-rm -f *.mp4