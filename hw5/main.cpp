#include <iostream>
#include "smatrix.h"

using namespace std;

int main()
{
    smatrix m(3, 3);
    entry a(0, 0, 1), b(1, 1, 2), c(2, 2, 3), d(2, 1, 4);
    m.add_entry(a);
    m.add_entry(b);
    m.add_entry(c);
    m.add_entry(d);
    cout << "matrix m = " << m << endl;

    smatrix n(3, 3);
    entry e(0, 0, 6), f(1, 1, 7), g(2, 2, 8);
    n.add_entry(e);
    n.add_entry(f);
    n.add_entry(g);
    cout << "matrix n = " << n << endl;

// get_entry()
    cout << "the value of (r, c) = (2, 1) in matrix m is: " << m.get_entry(2, 1) <<endl;

// is_diagonal()
    cout << "is matrix n diagonal? " << n.is_diagonal() << endl;

// ADDING TWO MATRICES
    m += n;
    cout << "the new matrix, m + n = " << m << endl;

// MULTIPLICATION
    m  *= 3;
    cout << "the new matrix, m * 3 = " << m << endl;

// TRANSPOSE
        m.transpose();
        cout << "transposed m = " << m << endl;






    return 0;
}

