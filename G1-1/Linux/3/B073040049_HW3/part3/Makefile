# Makefile for progressive dictionary exercise

PROGS = isam_lookup
	

all : $(PROGS)

isam_lookup : lookup2.o main.o
	$(CC) -o $@ lookup2.o main.o

clean :
	rm -f *.o $(PROGS)
