#include <iostream>
#include <string>
using namespace std;

class stu{
	public:
		stu();
		stu(string departmenta,string namea,string studentIDa,string gendera);
		void setData(string departmenta,string namea,string studentIDa,string gendera);
		void OutputData();
	private:
		string department;
		string name;
		string studentID;
		string gender;
};