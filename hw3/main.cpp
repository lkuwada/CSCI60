#include <iostream>
#include "biguint.h"

using namespace std;

int main()
{
    int zero = 0;
    biguint i(123), j(45);

    cout << "biguint i = " << i << " and biguint j = " << j << endl;
    i.lshift();
    cout << "biguint i shifted to the left is: " << i << endl;

    i *= j;
    cout << "i * j = " << i << endl;

    biguint k(144), l(12);
    cout << "biguint k = " << k << " and biguint l = " << l << endl;
    k /= l;
    cout << "k / l = " << k << endl;

    biguint m(9), n(9);
    cout << "biguint m = " << m << " and biguint n = " << n << endl;
    m ^= n;
    cout << "m ^ n = " << m << endl;

    biguint a(200), b(12);
    cout << "biguint a = " << a << " and biguint b = " << b << endl;
    a %= b;
    cout << "a % b = " << a  << endl;

    return 0;
}

