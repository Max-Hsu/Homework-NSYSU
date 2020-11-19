#include <iostream>
#include <string>

using namespace std;

class Play{
	private:
		string name;
		int score;
	public:
		Play(string Iname,int Iscore);
		void Output();
		void OutputWithName();
		int search(string find);
};
