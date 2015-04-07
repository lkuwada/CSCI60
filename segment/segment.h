#ifndef SEGMENT_H
#define SEGMENT_H

#include <cassert>
#include "line.h"

class segment: public LKUWADA::line
{
public:
    segment(double init_x, double init_y, double init_dx, double init_dy,
            double init_x0, double init_y0, double init_x1, double init_y1)
        :line(init_x, init_y, init_dx, init_dy, x0(init_x0), y0(init_y0), x1(init_x1), y1(init_y1))
    {
        assert(abs(dx) == abs(x1 - x0) && abs(dy) == (y1 - y0));
    }
};

#endif // SEGMENT_H
