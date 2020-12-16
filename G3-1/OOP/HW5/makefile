CPP	=	g++
CC_FLAGS	=	-std=c11
CPP_FLAGS	=	-std=c++11

all :	partone	parttwo

partone:
	cd part1 && $(CPP) $(CPP_FLAGS) test.cpp -o	main1
parttwo:
	cd part2 && $(CPP) $(CPP_FLAGS) Trace.cpp test.cpp -o main2

.PHONY:clean
clean:
	-rm	part1/main1
	-rm	part2/main2

dep:
	cd part1 && $(CPP)	$(CPP_FLAGS)	test.cpp		-MM	>	main1.dep
	cd part2 && $(CPP)	$(CPP_FLAGS)	test.cpp		-MM	>	main2.dep