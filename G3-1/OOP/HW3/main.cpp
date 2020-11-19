#include <iostream>
#include "Complex.h"

using std::cout;
using std::endl;
using std::ostream;
int main(){
    Complex a(77, 66.3);
    Complex b(a);
    int i = 1;

    cout << i++ << ": (" << a.Real() << ',' << a.Imag() << ')' << endl;
    cout << i++ << ": " << b << endl;
    cout << i++ << ": " << Norm(b) << endl;
    cout << i++ << ": " << b.Norm() << endl;
    cout << i++ << ": " << Abs(b) << endl;
    cout << i++ << ": " << b.Abs() << endl;
    cout << i++ << ": " << Arg(b) << endl;
    cout << i++ << ": " << b.Arg() << endl;
    //8
    a = Complex(12, 33.2);
    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << 1+a << endl;

    cout << i++ << ": " << a++ << endl;
    cout << i++ << ": " << ++a << endl;
    //12
    b = a.Polar(5.6, 1.8);

    cout << i++ << ": " << a << endl;
    cout << i++ << ": " << b << endl;
    //14
    b = Polar(6.5, 8.1);
    cout << i++ << ": " << b << endl;

    cout << i++ << ": " << a+b << endl;
    cout << i++ << ": " << a-b << endl;
    cout << i++ << ": " << a*b << endl;
    cout << i++ << ": " << a/b << endl;

    a /= b;
    cout << i++ << ": " << a << endl;
    a /= Complex(4, 3);
    cout << i++ << ": " << a << endl;

    a *= b;
    cout << i++ << ": " << a << endl;
    a *= Polar(5.1, 5.1);
    cout << i++ << ": " << a << endl;

    a += b;
    b -= a;
    cout << i++ << ": " << b << endl;

    if (!(a == b))
    cout << i++ << ": " << "OK" << endl;
    if (a != b)
    cout << i++ << ": " << "OK" << endl;
}