#include <iostream>
#include "Form.h"

using std::cout;
using std::endl;



Form gen4(4);  // general format, precision is 4

void f(double d)
{
    Form sci8 = gen4;
    sci8.scientific().precision(8);  // scientific format, precision 8
    Form fix8 = gen4;
    fix8.fixed().precision(8);  // fixed format, precision 8
    cout << "default = " << d << endl
         << "gen4    = " << gen4(d) << endl
         << "sci8    = " << sci8(d) << endl
         << "fix8    = " << fix8(d) << endl
         << "default = " << d << endl;
}



int main()
{
    f(1234.56789);
    f(12.3456789);

    return 0;
}
