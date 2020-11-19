#include <iostream>
#include "Complex.h"
#include <cmath>


using std::cout;
using std::endl;
using std::ostream;

Complex::Complex(const double re, const double im):real(re),imag(im){

}
Complex::Complex(const Complex & c):real(c.real),imag(c.imag){

}
double Complex::Real(){
    return this->real;
}
double Complex::Imag(){
    return this->imag;
}
double Complex::Norm(){
    return this->real*this->real + this->imag* this->imag;
}
double Complex::Abs(){
    return sqrt(this->Norm());
}
double Complex::Arg(){
    return atan2(this->imag,this->real);
}
Complex & Complex::operator=(const Complex & c){
    this->real = c.real;
    this->imag = c.imag;
    return *this;
}
Complex Complex::Polar(const double leng , const double arg){
    double real_c = leng * cos(arg);
    double imag_c = leng * sin(arg);
    this->real = real_c;
    this->imag = imag_c;
    return *this;
}
Complex Complex::operator++(){
    return Complex(this->real+1,this->imag+1);
}
Complex Complex::operator++(int){
    Complex old(*this);
    this->real+=1;
    this->imag+=1;
    return old;
}
Complex Complex::operator--(){
    return Complex(this->real-1,this->imag-1);
}
Complex Complex::operator--(int){
    Complex old(*this);
    this->real-=1;
    this->imag-=1;
    return old;
}
Complex Polar(const double leng, const double arg){
    double real_c = leng * cos(arg);
    double imag_c = leng * sin(arg);
    return Complex(real_c,imag_c);
}
double Norm (const Complex & x){
    return x.real*x.real + x.imag*x.imag;
}
double Abs (const Complex & x){
    return sqrt(Norm(x));
}
double Arg (const Complex & x){
    return atan2(x.imag,x.real);
}


Complex operator+ (const Complex & x , const Complex & y){
    return Complex(x.real+y.real,x.imag+y.imag);
}
Complex operator- (const Complex & x , const Complex & y){
    return Complex(x.real-y.real,x.imag-y.imag);
}
Complex operator* (const Complex & x , const Complex & y){
    return Complex(x.real*y.real-x.imag*y.imag , x.real*y.imag+x.imag*y.real);
}
Complex operator/ (const Complex & x , const Complex & y){
    double c_sq = y.real*y.real;
    double d_sq = y.imag*y.imag;
    return Complex((x.real*y.real+x.imag*y.imag)/(c_sq+d_sq),(x.imag*y.real-x.real*y.imag)/(c_sq+d_sq));
}
Complex operator+= (Complex & x , const Complex & y){
    x.real += y.real;
    x.imag += y.imag;
    return (x);
}
Complex operator-= (Complex & x , const Complex & y){
    x.real -= y.real;
    x.imag -= y.imag;
    return (x);
}
Complex operator*= (Complex & x , const Complex & y){
    double x_real = x.real;
    double x_imag = x.imag;
    x.real = x_real*y.real-x_imag*y.imag;
    x.imag = x_real*y.imag+x_imag*y.real;
    return (x);
}
Complex operator/= (Complex & x , const Complex & y){
    double x_real = x.real;
    double x_imag = x.imag;
    double c_sq = y.real*y.real;
    double d_sq = y.imag*y.imag;
    x.real = (x_real*y.real+x_imag*y.imag)/(c_sq+d_sq);
    x.imag = (x_imag*y.real-x_real*y.imag)/(c_sq+d_sq);
    return (x);
}
bool operator== (const Complex & x , const Complex & y){
    return (x.real == y.real) && (x.imag == y.imag);
}
bool operator!= (const Complex & x , const Complex & y){
    return (x.real != y.real) || (x.imag != y.imag);
}
ostream & operator << (ostream &o , const Complex & x){
    o <<"("<< x.real <<  "," << x.imag<<")";
    return o;
}

Complex::~Complex(){

}