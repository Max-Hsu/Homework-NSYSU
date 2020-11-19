#include <iostream>
#include <iomanip>

using namespace std;

double babylonian(double n,double guess){
double r=n/guess;
return	(guess+r)/2;
}
int main(int argc,char *argv[]){
double number;
double newguess;
cout<<"please input the N:";
cin>>number;
newguess=babylonian(number,number/2);
newguess=babylonian(number,newguess);
newguess=babylonian(number,newguess);
newguess=babylonian(number,newguess);
newguess=babylonian(number,newguess);


cout.precision(2);
cout.setf(ios::fixed,ios::floatfield);
cout<<"estimated root:"<<newguess<<endl;
return 0;
}