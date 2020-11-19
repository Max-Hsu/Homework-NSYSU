#include <iostream>
#include "ch6-10.h"
using namespace std;
float ounceToPound=float(1)/16;
void weight::setWeightPounds(float Pounds)
{
	weightInPound=Pounds;
}
void weight::setWeightKilograms(float Kilograms)
{
	weightInPound=Kilograms*2.21;
}
void weight::setWeightOunces(float Ounces)
{
	weightInPound=Ounces*ounceToPound;
}
void weight::PrintIt()
{
	cout<<"> In kilograms : "<<weightInPound/2.21<<"\n";
	cout<<"> In Pounds : "<<weightInPound<<"\n";
	cout<<"> In Ounces : "<<weightInPound*16<<"\n";
}
int main(){
	class weight a,b,c;
	cout<<"Set Kilograms = 60 \n";
	a.setWeightKilograms(60);
	a.PrintIt();
	cout<<"\nSet Pounds = 110 \n";
	b.setWeightPounds(110);
	b.PrintIt();
	cout<<"\nSet Ounces = 1800 \n";
	c.setWeightOunces(1800);
	c.PrintIt();
	return 0;
}