#include "segment.h"
#include "line.h"
#include <limits>


segment::segment(double init_x, double init_y, double init_dx, double init_dy,
        double init_x0, double init_y0, double init_x1, double init_y1)
    :line(init_x, init_y, init_dx, init_dy), x0(init_x0), y0(init_y0), x1(init_x1), y1(init_y1)
{
    assert(get_dx() * (get_y1() - get_y0() == get_dy() * (get_x1() - get_x0())));
}

// Copy Constructor
segment::segment(const segment & s): line(s)
{
    x0 = s.x0;
    y0 = s.y0;
    x1 = s.x1;
    y1 = s.y1;
}

double segment::get_x0() const
{
    return x0;
}

double segment::get_y0() const
{
    return y0;
}

double segment::get_x1() const
{
    return x1;
}

double segment::get_y1() const
{
    return y1;
}

void segment::set_endpt0(double new_x, double new_y)
{
    x0 = new_x;
    y0 = new_y;
}

void segment::set_endpt1(double new_x, double new_y)
{
    x1 = new_x;
    y1 = new_y;
}

bool segment::on_segment(double new_x1, double new_y1) const
{
    bool is_onSeg(false);
    if (x0 <= x1)
    {
        if ((y1 - new_y1) * (get_dx()) == (x1 - new_x1) * (get_dy()))
        {
            if (new_x1 <= x1 && new_x1 >= x0)
                is_onSeg = true;
        }
    }
    if (x0 >= x1)
    {
        if ((y1 - new_y1) * (get_dx()) == (x1 - new_x1) * (get_dy()))
        {
            if (new_x1 <= x0 && new_x1 >= x1)
                is_onSeg = true;
        }
    }

    return is_onSeg;
}

double segment::x_intercept() const
{
    double x_int(line::x_intercept());
    double inf = std::numeric_limits<double>::infinity();

    if (!on_segment(x_int, 0))
        return inf;
    else
        return x_int;
}

double segment::y_intercept() const
{
    double y_int(line::y_intercept());
    double inf = std::numeric_limits<double>::infinity();

    if (!on_segment(0, y_int))
        return inf;
    else
        return y_int;
}


std::ostream & operator << (std::ostream & os, const segment & s)
{

    os << "Endpoint 1 = (" << s.get_x0() << ", " << s.get_y0() << ") ";
    os << "Endpoint 2 = (" << s.get_x1() << ", " << s.get_y1() << ")";

    return os;
}


std::istream & operator >> (std::istream & is, segment & s)
{
    double a, b, c, d, e, f, g, h;

    is >> a >> b >> c >> d >> e >> f >> g >> h;
    s = segment(a, b, c, d, e, f, g, h);

    return is;
}



