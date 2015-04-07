#include "line.h"
#include <cassert>


//using namespace lkuwada;

line::line(double init_x0, double init_y0, double init_x1, double init_y1)
{
    assert((init_x0 != init_x1) || (init_y0 != init_y1)); // makes sure the two points are distinct
    x0 = init_x0;
    y0 = init_y0;
    x1 = init_x1;
    y1 = init_y1;
}

double line::slope() const
{
    assert(!is_vertical());

    return (y1 - y0)/ (x1 - x0);
}

bool line::is_horizontal() const
{
    return (y0 == y1);
}

bool line::is_vertical() const
{
    return (x0 == x1);
}

double line::x_intercept() const
{
    // (x0, y0) + t(dx, dy) = (x, 0)

    assert(!is_horizontal());
    double dx = x1 - x0;
    double dy = y1 - y0;

    return x0 - y0 * dx/dy;
}

double line::y_intercept() const
{
    assert(!is_vertical());
    double dx = x1 - x0;
    double dy = y1 - y0;

    return y0 - x0 * dy/dx;
}

void line::vshift(double d)
{
    y0 += d;
    y1 += d;
}

void line::hshift(double d)
{
    x0 += d;
    x1 += d;
}

double line::get_x0() const
{
    return x0;
}

double line::get_y0() const
{
    return y0;
}

double line::get_x1() const
{
    return x1;
}

double line::get_y1() const
{
    return y1;
}

std::ostream & operator << (std::ostream & os, const line & l) //"const line & l" more efficient than "line l" b/c it's less
                                                              //copying when passing by reference. passing address but can't
                                                              //change address b/c const
{
//    os << "(" << l.x0 << ", " << l.y0 << ")" << " ";
//    os << "(" << l.x1 << ", " << l.y1 << ")";

    os << "(" << l.get_x0() << ", " << l.get_y0() << ")" << " ";
    os << "(" << l.get_x1() << ", " << l.get_y1() << ")" << " ";

    return os;
}

std::istream & operator >> (std::istream & is, line & l)
{
    //is >> l.x0 >> l.y0 >> l.x1 >> l.y1;
    double a, b, c, d;

    is >> a >> b >> c >> d;
    l = line(a, b, c, d);

    return is;
}
