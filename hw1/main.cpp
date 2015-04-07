#include <iostream>
#include "line.h"
#include <utility>

using namespace std;

using namespace LKUWADA;

int main()
{
    line l(0, 0, 1, 1);
    line n(-1, -4, 4, 1);

    cout << "Line l: " << l << "\nLine n: " << n << endl;


    cout << "\nslope of l = " << l.slope() << endl;
    cout << "x-intercept of l = " << l.x_intercept() << endl;
    cout << "y-intercept of l = " << l.y_intercept() << endl;


    cout << "\nslope of n = " << n.slope() << endl;
    cout << "x-intercept of n = " << n.x_intercept() << endl;
    cout << "y-intercept of n = " << n.y_intercept() << endl;


    line horiz(2, 2, 4, 0);
    cout << "\nLine horiz: " << horiz << "\nslope of horiz = " << horiz.slope() << endl;
    cout << "y-intercept of horiz = " << horiz.y_intercept() << endl;
    horiz.vshift(3);
    cout << "new y-intercept of horiz = " << horiz.y_intercept() << endl;


    line vert(-1, 1, 0, 5);
    //cout << "\nslope of vert = " << vert.slope() << endl;
    cout << "\nLine vert: " << vert << "\nx-intercept of vert = " << vert.x_intercept() << endl;
    vert.hshift(-2);
    cout << "new x-intercept of ver = " << vert.x_intercept() << endl;


    pair<double, double> intersect(l * n);
    cout << "\nThe two points (l and n) intersect at: (" << intersect.first << ", " << intersect.second << ")" << endl;


    cout << "\nEnter a point (x, y) and a slope (dx, dy): ";
    line x;
    cin >> x;
    cout << "Input line (x,y) and (dx, dy) is: " << x << endl;
    cout << "The x-intercept of the point you just entered is: " << x.x_intercept() << endl;
    cout << "The y-intercept of the point you just entered is: " << x.y_intercept() << endl;

    return 0;
}

