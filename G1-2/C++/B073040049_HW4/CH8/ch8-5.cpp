#include <iostream>
#include "ch8-5.h"

using namespace std;
Vector2D::Vector2D(){}
Vector2D::Vector2D(int x,int y):
x(x),y(y){}
void Vector2D::output(){
	cout<<"("<<x<<","<<y<<")";
}
const int Vector2D::operator *(const Vector2D& vector2){
	return((x*vector2.x)+(y*vector2.y));
}
int main(){
	Vector2D(9,10).output();
	cout<<" * ";
	Vector2D(17,0).output();
	cout<<" = "<<Vector2D(9,10)*Vector2D(17,0)<<"\n";
	
	Vector2D(10,12).output();
	cout<<" * ";
	Vector2D(0,8).output();
	cout<<" = "<<Vector2D(10,12)*Vector2D(0,8)<<"\n";
	Vector2D(19,13).output();
	cout<<" * ";
	Vector2D(7,20).output();
	cout<<" = "<<Vector2D(19,13)*Vector2D(7,20)<<"\n";
	
	
	
	return 0;
}