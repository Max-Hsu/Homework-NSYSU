PROGS = usock_server	usock_client
target : clean	$(PROGS)
.PHONY	:clean
clean :
	rm -f *.o $(PROGS)
usock_server:
	gcc	-o	usock_server	usock_server.c	lookup5.c
usock_client:
	gcc	-o	usock_client	main.c	lookup7.c
