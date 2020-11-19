#include <iostream>

using namespace std;

class circlea {
	public:
		void setr(){
			int tr;
			cout<<"Type the radius : ";
			cin>>tr;
			this->R=tr;
		}
		void out(){
			cout<<"r = "<<this->R<<" , area = "<<this->R*this->R*3.14159<<"\n";
		}
		int rad(){
			return this->R;
		}
	protected:
		int R;
};

class cylinder:public circlea{
	public:
		cylinder(circlea & A){
			this->R=A.rad();
		}
		void seth(){
			int th;
			cout<<"Type the height : ";
			cin>>th;
			this->H=th;
		}
		void out(){
			cout<<"r = "<<this->R<<" , volume = "<<this->R*this->R*3.14159*this->H<<"\n";
		}
	private:
		int H;
};

int main(){
	circlea A;
	A.setr();
	A.out();
	cylinder B(A);
	B.seth();
	B.out();
	return 0;
}