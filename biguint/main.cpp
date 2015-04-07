#include <iostream>
#include "biguint.h"

using namespace std;

int main()
{
    biguint i(132);
    cout << i << endl;

    biguint j(string("789"));
    cout << j << endl;

    biguint k("987654321");
    cout << k << endl;

    //biguint x;

    //cout << "Enter a biguint: ";
    //cin >> x;
    //cout << "Read value = " << x << endl;

    //i += j;
    //cout << i << endl;

    //cout << i.compare(j) << endl;

    //i.rshift();

    //cout << i << endl;

    return 0;
}

