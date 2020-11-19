CPP	=	g++
CC_FLAGS	=	-std=c11
CPP_FLAGS	=	-std=c++11

all : tar main combine
tar:
	g++ $(CPP_FLAGS) mytar.cpp -c
main:
	g++ $(CPP_FLAGS) main.cpp -c
combine:
	g++ $(CPP_FLAGS) main.o mytar.o -o mytar


.PHONY:clean
clean:
	-rm	*.dep
	-rm	mytar

dep:
	$(CPP)	$(CPP_FLAGS)	main.cpp		-MM	>	main.dep
	$(CPP)	$(CPP_FLAGS)	mytar.cpp		-MM	>	mytar.dep