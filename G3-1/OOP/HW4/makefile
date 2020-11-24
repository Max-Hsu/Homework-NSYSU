CPP	=	g++
CC_FLAGS	=	-std=c11
CPP_FLAGS	=	-std=c++11

all : file_handle	main	combine
file_handle:
	g++ $(CPP_FLAGS) file_handle.cpp -c
main:
	g++ $(CPP_FLAGS) main.cpp -c
combine:
	g++ $(CPP_FLAGS) main.o file_handle.o -o main_lex


.PHONY:clean
clean:
	-rm	*.dep
	-rm	*.o
	-rm	main_lex

dep:
	$(CPP)	$(CPP_FLAGS)	main.cpp		-MM	>	main.dep
	$(CPP)	$(CPP_FLAGS)	file_handle.cpp		-MM	>	file_handle.dep