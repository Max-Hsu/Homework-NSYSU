all : convert main
convert : convert.o
	gcc -o convert convert.o 
convert.o : convert.c
	gcc -c convert.c
main : main.o
	gcc -o main main.o 
main.o : main.c
	gcc -c main.c
