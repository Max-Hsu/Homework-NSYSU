#include <iostream>

using namespace std;
class Paira{
	public:
		Paira();
		Paira(int x,int y){
			this->x=x;
			this->y=y;
		}
		Paira operator ++ ();
		Paira operator ++ (int num);
		Paira operator -- ();
		Paira operator -- (int num);
		const Paira operator += (const Paira & toAdd);
		const Paira operator -= (const Paira & toMinus);
		const Paira operator *= (const Paira & toMul);
		const Paira operator /= (const Paira & toDiv);
		friend istream& operator >>(istream& toInput,Paira& toInputPair);
		friend ostream& operator <<(ostream& toInput,const Paira& toOutputPair);
	private:
		int x,y;
};
Paira::Paira(){
	x=0;
	y=0;
}
istream& operator>>(istream& toInput,Paira& toInputPair){
	toInput>>toInputPair.x;
	toInput>>toInputPair.y;
}
ostream& operator<<(ostream& toOutput,const Paira& toOutputPair){
	toOutput<<toOutputPair.x<<"\t"<<toOutputPair.y<<"\n";
}
Paira Paira::operator ++(){
	return Paira(x+1,y+1);
}
Paira Paira::operator ++(int num){
	return Paira(x,y);
}
Paira Paira::operator --(){
	return Paira(x-1,y-1);
}
Paira Paira::operator --(int num){
	return Paira(x,y);
}

const Paira Paira::operator += (const Paira & toAdd){
	return Paira(x+toAdd.x,y+toAdd.y);
}
const Paira Paira::operator -= (const Paira & toMinus){
	return Paira(x-toMinus.x,y-toMinus.y);
}
const Paira Paira::operator *= (const Paira & toMul){
	return Paira(x*toMul.x-y*toMul.y,y*toMul.x+x*toMul.y);
}
const Paira Paira::operator /= (const Paira & toDiv){
	return Paira(((x*toDiv.x+y*toDiv.y)/(toDiv.x*toDiv.x+toDiv.y*toDiv.y)),((y*toDiv.x-x*toDiv.y)/(toDiv.x*toDiv.x+toDiv.y*toDiv.y)));
}


int main(){
	Paira a,b;
	cin>>a;
	cin>>b;
	cout<<a;
	cout<<b;
	cout<<a++;
	cout<<++a;
	cout<<a--;
	cout<<--a;
	Paira add=a+=b;
	Paira Min=add-=b;
	Paira Mul=Min*=b;
	Paira Div=Mul/=b;
	cout<<add;
	cout<<Min;
	cout<<Mul;
	cout<<Div;
	return 0;
}