#include <iostream>
#include "unibag.h"

using namespace std;

int main()
{
    main_savitch_6B::bag<int> b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(3);
    b.insert(2);
    b.insert(1);

    unibag<int> u(b);

    for (unibag<int>::iterator i = u.begin(); i != u.end(); ++i)
        cout << *i << endl;


    return 0;
}

