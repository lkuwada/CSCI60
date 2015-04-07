#include <iostream>
#include "poly.h"

using namespace std;

int main()
{
    poly a(3);
    a.set_coeff(0, 7);
    a.set_coeff(1, 6);
    a.set_coeff(2, 5);
    a.set_coeff(3, 4);

    poly b(4);
    b.set_coeff(0, 5);
    b.set_coeff(1, 4);
    b.set_coeff(2, 3);
    b.set_coeff(3, 2);
    b.set_coeff(4, 1);

    cout << "poly a = " << a << endl;
    cout << "poly b = " << b << endl;

    poly a_deriv = a.derivative();
    cout << "the derivative of poly a = " << a_deriv << endl;

    poly a_integral = a.integral();
    cout << "the integral of poly a = " << a_integral << endl;

    double answer = a(4);
    cout << "poly a evaluated at 4 = " << answer << endl;

    a += b;
    cout << "poly a + b = " << a << endl;


    return 0;
}



