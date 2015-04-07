#include <iostream>
#include "bag.h"

using namespace std;

int main()
{
// #1
    bag a, b, c, d;

    b.insert(8);

    c.insert(7);
    c.insert(9);
    c.insert(4);
    c.insert(7);
    c.insert(0);
    c.insert(4);
    c.insert(7);
    c.insert(7);
    c.insert(4);
    c.insert(7);

    d.insert(7);
    d.insert(4);
    d.insert(7);
    d.insert(4);
    d.insert(7);

//    c -= d;
//    cout << c.count(7) << endl;
//    cout << c.count(4) << endl;

    bag e(c - d);
    cout << e.count(7) << " " << e.count(4) << endl;


//    cout << "The number of objects in a is: " << a.size() << endl;
//    cout << "The number of objects in b is: " << b.size() << endl;
//    cout << "The number of objects in c is: " << c.size() << endl;
//    cout << "The number of objects in d is: " << d.size() << endl;

//    cout << "The number of times 7 occurs in bag c is: " << c.count(7) << endl;
//    c.erase_one(7);
//    cout << "The number of times 7 occurs in bag c is now: " << c.count(7) << endl;
//    c.erase(7);
//    cout << "The number of times 7 occurs in bag c is now: " << c.count(7) << endl;

//    b += d;
//    cout << "After d has been added to bag b, the size of b is now: " << b.size() << endl;

//    cout << "The number of objects in c is: " << c.size() << endl;
//    bag e(c + d);
//    cout << "The number of objects in bag e, which is c + d, is: " << e.size() << endl;



    return 0;
}

