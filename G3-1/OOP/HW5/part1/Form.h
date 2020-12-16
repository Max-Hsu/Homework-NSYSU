#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <sstream>

using namespace std;
struct Bound_form; //Form plus value

class Form{
    private:
        friend ostream& operator<<(ostream&, const Bound_form&) ;
        int prc; // precision
        int wdt; // width, 0 means as wide as necessary
        ios_base::fmtflags fmt; // general, scientific, or fixed (§21.4.3)
    public:
        explicit Form(int p= 6) : prc(p){ // default precision is 6
            wdt= 0; // as wide as necessary
        }
        Bound_form operator()(double d) const; // make a Bound_form for *this and d
        Form& scientific() { fmt= ios_base::scientific; return*this; }
        Form& fixed() { fmt= ios_base::fixed; return*this; }
        Form& general() { fmt= ios_base::fmtflags(); return*this; }
        Form& uppercase() ;
        Form& lowercase() ;
        Form& precision(int p) { prc= p; return*this; }
        Form& width(int w) { wdt= w; return*this; } // applies to all types
        Form& fill(char) ;
        Form& plus(bool b= true) ; // explicit plus
        Form& trailing_zeros(bool b= true) ; // print trailing zeros
};
struct Bound_form{
    const Form & f;
    double val;
    Bound_form(const Form & ff, double v) : f(ff) , val(v) { }
};
Bound_form Form::operator()(double d) const{ return Bound_form(*this,d) ; }
ostream& operator<<(ostream& os, const Bound_form& bf){
    ostringstream s; // string streams are described in §21.5.3
    s.precision(bf.f.prc) ;
    s.setf(bf.f.fmt,ios_base::floatfield);
    s<< bf.val; // compose string in s
    return os<< s.str() ; // output s to os
}
#endif