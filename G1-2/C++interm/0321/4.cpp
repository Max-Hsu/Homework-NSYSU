#include <iostream>

using namespace std;
const int pi=3;
void circle_area(int num,char choice,int &anscms){
	if(choice=='d'){
		num/=2;
	}
	anscms=num*num*pi;
}
void circle_peri(int num,char choice,int &anscmss){
	if(choice=='d'){
		num/=2;
	}
	anscmss=num*2*pi;
}
int main(){
	int dia;
	char choice;
	int ans;
	cout<<"enter the circle diameter:";
	cin>>dia;
	cout<<"enter r if the diameter was radius or enter d if it was full diameter :";
	cin>>choice;
	circle_area(dia,choice,ans);
	cout<<"area of the circle is : "<<ans<<endl;
	circle_peri(dia,choice,ans);
	cout<<"perimeter of the circle is : "<<ans<<endl;
	return 0;
}