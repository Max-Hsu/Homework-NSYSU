#include <iostream>
using namespace std;
void calculation(int gender,int momTInch,int dadTInch){
	int childInch,childFeet;
	if(gender){
		childInch=(dadTInch*12/13+momTInch)/2;
	}
	else{
		childInch=(momTInch*13/12+dadTInch)/2;
	}
	childFeet=childInch/12;
	childInch%=12;
	cout<<"Your future child is estimated to grow to "<<childFeet<<" feet and "<<childInch<<" inches."<<endl;
}
int main(){
	int gender;
	int momFeet,momInch;
	int dadFeet,dadInch;
	cout<<"Enter the gender of your future child. Use 1 for female , 0 for male."<<endl;
	cin>>gender;
	do{
	cout<<"Enter the height in feet and inches of the mom."<<endl;
	cin>>momFeet>>momInch;
	cout<<"Enter the height in feet and inches of the dad."<<endl;
	cin>>dadFeet>>dadInch;
	calculation(gender,momFeet*12+momInch,dadFeet*12+dadInch);
	cout<<"Enter the gender of your future child. Use 1 for female , 0 for male. (-1 to end)"<<endl;
	cin>>gender;
	}while(!(gender==-1));
	return 0;
}