PROGS = udp_server	udp_client
target : clean	$(PROGS)
.PHONY	:clean
clean :
	rm -f *.o $(PROGS)
udp_server:
	gcc	-o	udp_server	udp_server.c	lookup5.c
udp_client:
	gcc	-o	udp_client	main.c	lookup9.c
