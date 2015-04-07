#include <iostream>
#include "namedbag.h"

using namespace std;

int main()
{
    main_savitch_6B::bag<double> b;
    b.insert(5.0);
    b.insert(3.1415);

    namedbag<double> nb(b, "coach"), nb2;

    cout << nb.getname() << endl;

    for (namedbag<double>::iterator i = nb.begin(); i != nb.end(); ++i)
        cout << *i << endl;

    nb2 = nb;
    cout << nb2.getname() << endl;
    for (namedbag<double>::iterator i = nb2.begin(); i != nb2.end(); ++i)
        cout << *i << endl;

    return 0;
}

