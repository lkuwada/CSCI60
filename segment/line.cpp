#include "line.h"
#include <cassert>
#include <utility>

namespace LKUWADA
{

line::line(double init_x,
           double init_y,
           double init_dx,
           double init_dy)

{
    assert(dx != 0.0 || dy != 0.0);
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

void line::vshift(double d)
{
    y += d;
}

void line::hshift(double d)
{
    x += d;
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

std::ostream & operator << (std::ostream & os, const line & l)
{

    os << "(" << l.get_x() << ", " << l.get_y() << ") ";
    os << "(" << l.get_dx() << ", " << l.get_dy() << ")";

    return os;
}


std::istream & operator >> (std::istream & is, line & l)
{
    double a, b, c, d;

    is >> a >> b >> c >> d;
    l = line(a, b, c, d);

    return is;

}

std::pair<double, double> operator *(const line & l1, const line & l2)
{
	assert(l1.dx()*l2.dy() != l1.dy()*l2.dx()); // not parallel

	double n = l2.dy()*(l1.x()-l2.x()) - l2.dx()*(l1.y() - l2.y());
	double d = l2.dx()*l1.dy() - l1.dx()*l2.dy();
	double r = n/d;

	return std::pair<double, double>(l1.x()+r*l1.dx(), l1.y() + r*l1.dy());
}


}




}
