#include <iostream>
#include <string>

using namespace std;

class UniversityStaff{
	public:
		UniversityStaff(){}
		UniversityStaff(string theName):name(theName){}
		UniversityStaff(const UniversityStaff& theObject){
			name = theObject.name;
		}
		string getName()const{
			return name;
		}
		UniversityStaff& operator=(const UniversityStaff& rtSide){
			this->name = rtSide.name;
			return *this;
		}
		friend istream& operator >> (istream& inStream,UniversityStaff& staffObject){
			string nname;
			inStream>>nname;
			staffObject = UniversityStaff(nname);
			return inStream;
		}
		friend ostream& operator << (ostream& outStream,const UniversityStaff& staffObject){
			outStream<<staffObject.getName();
			return outStream;
		}
	protected:
		string name;
};
class Student:public UniversityStaff{
	public:
		Student(){}
		Student(string universityNamea,string regNuma,string namea):universityName(universityNamea),regNum(regNuma),Name(UniversityStaff(namea)){}
		Student(Student & docopy){
			this->universityName=docopy.universityName;
			this->regNum=docopy.regNum;
			this->Name=docopy.Name;
		}
		void set(string universityNamea,string regNuma,string namea){
			this->universityName=universityNamea;
			this->regNum=regNuma;
			this->Name=UniversityStaff(namea);
		}
		void output(){
			cout<<universityName<<"\n"<<regNum<<"\n"<<Name.getName()<<"\n";
		}
		string forScience(){
			return  universityName+"\n"+regNum+"\n"+Name.getName()+"\n";
		}
	protected:
		string universityName;
		string regNum;
		UniversityStaff Name;
		
};
class ScienceStudent:public Student{
	public:
		ScienceStudent(){}
		ScienceStudent(string disciplinea , string statusa , string universityNamea,string regNuma,string namea):Student(universityNamea,regNuma,namea),discipline(disciplinea) , status(statusa){}
		ScienceStudent(ScienceStudent & docopy){
			this->discipline = docopy.discipline;
			this->status = docopy.status;
			this->universityName = docopy.universityName;
			this->regNum = docopy.regNum;
			this->Name = docopy.Name;
		}
		void set(string disciplinea , string statusa , string universityNamea , string regNuma , string namea){
			this->discipline = disciplinea;
			this->status = statusa;
			this->universityName = universityNamea;
			this->regNum = regNuma;
			this->Name = UniversityStaff(namea);
		}
		void output(){
			cout<<this->forScience()<<this->discipline<<"\n"<<this->status<<"\n";
		}
	private:
		string discipline;
		string status;

};

int main(){
	cout<<"Student Test1(constructed) Data:\n";
	Student A("ABC","DEF","GHI");
	A.output();
	cout<<"Student Test2(assigned) Data:\n";
	Student B;
	B.set("BEF","IS","GOOF");
	B.output();
	cout<<"Student Test2(copy constructed) Data:\n";
	Student C(B);
	C.output();
	cout<<"ScienceStudent Test1(constructed) Data:\n";
	ScienceStudent D("DD","EE","AA","erq","qw");
	D.output();
	cout<<"ScienceStudent Test2(assigned) Data:\n";
	ScienceStudent E;
	E.set("DG","QR","TR","TTF","CC");
	E.output();
	cout<<"ScienceStudent Test2(copy constructed) Data:\n";
	ScienceStudent F(E);
	F.output();
	return 0;
}