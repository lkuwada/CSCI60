#include <iostream>
#include "triple.h"

using namespace std;

int main()
{
    triple<int> i;
    cout << "Enter an integer triple: ";
    cin >> i;
    cout << i << endl;

    triple<char> c;
    cout << "Enter a character triple: ";
    cin >> c;
    cout << c << endl;

    triple<vector<double> > d;

    return 0;
}

