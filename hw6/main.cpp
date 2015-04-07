#include <iostream>
#include "segment.h"

using namespace std;

int main()
{
    //segment s(0, 0, 1, 1, -1, -1, 5, 5);
    segment user_seg;

    cout << "Enter 8 numbers; (x, y), (dx, dy), (x0, y0), (x1, y1): " << endl;
    cin >> user_seg;
    cout << "This segment = " << user_seg << endl;

    cout << "The x-intercept of this segment = " << user_seg.x_intercept() << endl;
    cout << "The y-intercept of this segment = " << user_seg.y_intercept() << endl;


    cout << "Is (3, 3) on this segment? ";
    if (user_seg.on_segment(2, 2) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}

