#include <iostream>
#include "biguint.h"


using namespace std;

int main()
{
    biguint i(123);
    cout << i << endl;

    biguint j("586");
    cout << j << endl;

    i += j;
    cout << i << endl;

    i *= 4;
    cout << i << endl;

    i.rshift();
    cout << i << endl;

    cout << i.compare(j) << endl;

    biguint x;
    cout << "Enter a biguint: ";
    cin >> x;
    cout << "Read value = " << x << endl;


    return 0;
}

