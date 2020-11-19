#include <iostream>

using namespace std;
char defaultchar='#';
class charpair{
	public:
		charpair();
		charpair(int size);
		charpair(int size,char symbol);
		char& operator[](int index);
		void outputsize();
	private:
		char set[100];
		int sizeofset;
};