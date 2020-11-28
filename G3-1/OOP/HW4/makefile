CPP	=	g++
CC_FLAGS	=	-std=c11
CPP_FLAGS	=	-std=c++11

all : main
main:
	g++ $(CPP_FLAGS) main.cpp -o	main_lex


.PHONY:clean
clean:
	-rm	*.dep
	-rm	*.o
	-rm	main_lex

dep:
	$(CPP)	$(CPP_FLAGS)	main.cpp		-MM	>	main.dep