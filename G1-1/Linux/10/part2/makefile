PROGS = isock_server	isock_client
target : clean	$(PROGS)
.PHONY	:clean
clean :
	rm -f *.o $(PROGS)
isock_server:
	gcc	-o	isock_server	isock_server.c	lookup5.c
isock_client:
	gcc	-o	isock_client	main.c	lookup8.c
