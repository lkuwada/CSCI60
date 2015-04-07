#include <iostream>
#include "bag.h"
#include "maxbag.h"

using namespace std;

int main()
{
//    main_savitch_6B::bag<int> b;
//    b.insert(4);
//    b.insert(5);

    maxbag<int> mb;

    mb.insert(3);
    mb.insert(5);
    mb.insert(1);
    mb.insert(-5);
    cout << mb.max() << endl;

    cout << "Hello World!" << endl;
    return 0;
}

