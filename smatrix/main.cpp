#include <iostream>
#include "smatrix.h"

using namespace std;

int main()
{
//    entry e1, e2;
//    cout << "Enter two entries (row, col, value): ";
//    cin >> e1 >> e2;
//    cout << "Read: " << e1 << e2 << endl;
//    cout << (e1 == e2) << endl;
//    cout << (e1 > e2) << endl;

    smatrix m(4, 5);
    cout << m << endl;

    smatrix n;
    cout << "Enter a sparse matrix; dimensions followed by entries, (-1, -1, 0) to stop: " << endl;
    cin >> n;
    cout << n << endl;

    smatrix c1(n);
    smatrix c2;
    c2 = n;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    return 0;
}

