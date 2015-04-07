#include <iostream> //< > means go to predefined location
#include "line.h" // " " means go to place defined by us...

using namespace std;

//using namespace lkuwada;

int main()
{
    line l(0,0,1,1);
    line k;
    line n(1, 2, 3, 3);

    cout << "slope of l = " << l.slope() << endl;
    cout << "slope of k = " << k.slope() << endl;
    cout << "slope of n = " << n.slope() << endl;

    cout << l.is_horizontal() << endl;

    n.vshift(2.0);

    cout << n << k << l << endl; // want to print this out.. overload something...

    cout << "Enter a line (4 doubles): ";
    line x;
    cin >> x;
    cout << "Input line is: " << x << endl;

    return 0;
}

