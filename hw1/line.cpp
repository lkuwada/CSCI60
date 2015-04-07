#include "line.h"
#include <cassert>
#include <utility>

namespace LKUWADA
{

line::line(double init_x, double init_y, double init_dx, double init_dy)
{
    x = init_x;
    y = init_y;
    dx = init_dx;
    dy = init_dy;
}

double line::slope() const
{
    assert(!is_vertical());

    return (dy/dx);
}

bool line::is_horizontal() const
{
    return (dy == 0);
}

bool line::is_vertical() const
{
    return (dx == 0);
}

bool line::is_parallel(const line & a) const
{
    return ((dy/dx) == (a.get_dy()/a.get_dx()));
}

double line::x_intercept() const
{
    assert(!is_horizontal());

    return x - y * dx/dy;
}

double line::y_intercept() const
{
    assert(!is_vertical());

    return y - x * dy/dx;
}

double line::get_x() const
{
    return x;
}

double line::get_y() const
{
    return y;
}

double line::get_dx() const
{
    return dx;
}

double line::get_dy() const
{
    return dy;
}

void line::vshift(double d)
{
    y += d;
}

void line::hshift(double d)
{
    x += d;
}


std::ostream & operator << (std::ostream & os, const line & l)
{
    os << "(x, y) = (" << l.get_x() << ", " << l.get_y() << ")" << ", ";
    os << "(dx, dy) = (" << l.get_dx() << ", " << l.get_dy() << ")" << ". ";

    return os;
}

std::istream & operator >> (std::istream & is, line & l)
{
    double a, b, c, d;

    is >> a >> b >> c >> d;
    l = line(a, b, c, d);

    return is;
}

std::pair<double, double> operator * (const line & l1, const line & l2)
{
    assert(!l1.is_parallel(l2));

    double r = ((l2.get_dy() * (l1.get_x() - l2.get_x())) - (l2.get_dx() * (l1.get_y()-l2.get_y())))/
              (l2.get_dx() * l1.get_dy() - l1.get_dx() * l2.get_dy());

    return std::pair<double, double> (l1.get_x() + r * l1.get_dx(), l1.get_y() + r * l1.get_dy());
}



}

