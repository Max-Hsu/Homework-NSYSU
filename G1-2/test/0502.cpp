#include <iostream>

using namespace std;
class X{
	public:
		void fun1();
		void setX();
		const X& operator + (const X& nx);
		X(int x);
		X();
	private:
		int x;
		int fun2();
};
X::X(int x):
x(x){}
X::X(){}
void X::setX(){
	cin>>x;
}
int X::fun2(){
	return x*100;
}
void X::fun1(){
	cout<<fun2()<<"\n";
}
X& X::operator + (const X& nx){
	return (fun2()+nx.fun2());
}
int main(){
	X test;
	test.setX();
	test.fun1();
	X add=test+test;
	return 0;
}