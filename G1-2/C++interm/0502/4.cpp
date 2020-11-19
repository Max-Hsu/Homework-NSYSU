#include <iostream>

using namespace std;
class paira{
	public:
		paira();
		paira(int x,int y);
		void set(int num);
		void setx(int num1,int num2);
		friend ostream& operator<<(ostream& outputS,const paira& pairtoOut);
		friend const paira operator+(const paira& pairtoOut1,const paira& pairtoOut2);
		friend const paira operator*(const paira& pairtoOut1,const int c);
	private:
		int x,y;
};
paira::paira():
x(0),y(0)
{}

paira::paira(int zx,int zy):
x(zx),y(zy)
{}
ostream& operator<<(ostream& outputS,const paira& pairtoOut){
	outputS<<"("<<pairtoOut.x<<","<<pairtoOut.y<<")";
	return outputS;
}
const paira operator+(const paira& pairtoOut1,const paira& pairtoOut2){
	return paira((pairtoOut1.x+pairtoOut2.x),(pairtoOut1.y+pairtoOut2.y));
}
const paira operator*(const paira& pairtoOut1,const int c){
	return paira((pairtoOut1.x*c),(pairtoOut1.y*c));
}
void paira::set(int num){
	x=num;
}
void paira::setx(int num1,int num2){
	x=num1;
	y=num2;
}
int main(){
	paira Pair1,Pair2,Pair3;
	cout<<"Please set 3 pairs\n";
	int numchoice;
	cout<<"Enter 0 or 1 or 2 (0 means no parameter , 1 means one parameter , 2 means two parameters):\n";
	cin>>numchoice;
	if(numchoice==1){
		int numin;
		cout<<"Please enter first number\n";
		cin>>numin;
		Pair1.set(numin);
	}
	else if(numchoice==2){
		int numin1,numin2;
		cout<<"Please enter first &second number\n";
		cin>>numin1>>numin2;
		Pair1.setx(numin1,numin2);
	}
	
	cout<<"Enter 0 or 1 or 2 (0 means no parameter , 1 means one parameter , 2 means two parameters):\n";
	cin>>numchoice;
	if(numchoice==1){
		int numin;
		cout<<"Please enter first number\n";
		cin>>numin;
		Pair2.set(numin);
	}
	else if(numchoice==2){
		int numin1,numin2;
		cout<<"Please enter first &second number\n";
		cin>>numin1>>numin2;
		Pair2.setx(numin1,numin2);
	}
	cout<<"Enter 0 or 1 or 2 (0 means no parameter , 1 means one parameter , 2 means two parameters):\n";
	cin>>numchoice;
	if(numchoice==1){
		int numin;
		cout<<"Please enter first number\n";
		cin>>numin;
		Pair3.set(numin);
	}
	
	else if(numchoice==2){
		int numin1,numin2;
		cout<<"Please enter first &second number\n";
		cin>>numin1>>numin2;
		Pair3.setx(numin1,numin2);
	}
	int con;
	cout<<"Enter constant number c :\n";
	cin>>con;
	paira oP=Pair1+Pair2+Pair3;
	cout<<oP<<"\n";
	cout<<"X:"<<Pair1<<"\n";
	cout<<"Y:"<<Pair2<<"\n";
	cout<<"Z:"<<Pair3<<"\n";
	cout<<Pair1+Pair2+Pair3<<"\n";
	cout<<Pair3*con<<"\n";
	return 0;
}