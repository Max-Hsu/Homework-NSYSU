CPP	=	g++
CC_FLAGS	=	-std=c11
CPP_FLAGS	=	-std=c++11

all : complex main combine
complex:
	g++ $(CPP_FLAGS) Complex.cpp -c
main:
	g++ $(CPP_FLAGS) main.cpp -c
combine:
	g++ $(CPP_FLAGS) main.o Complex.o -o main_Complex


.PHONY:clean
clean:
	-rm	*.dep
	-rm	*.o
	-rm	main_Complex

dep:
	$(CPP)	$(CPP_FLAGS)	main.cpp		-MM	>	main.dep
	$(CPP)	$(CPP_FLAGS)	Complex.cpp		-MM	>	Complex.dep