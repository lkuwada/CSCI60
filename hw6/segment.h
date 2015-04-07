#ifndef SEGMENT_H
#define SEGMENT_H

#include <cassert>
#include "line.h"


class segment: public line
{
public:
    segment(double init_x = 0, double init_y = 0, double init_dx = 1, double init_dy = 0,
            double init_x0 = 0, double init_y0 = 0, double init_x1 = 0, double init_y1 = 0);
    // pre: none
    // post: an instance of a segment has been created

    segment(const segment & s);
    // pre: none
    // post: a copy of segment s has been created

    double get_x0() const;
    // pre: none
    // post: returns the x value of the first endpt

    double get_y0() const;
    // pre: none
    // post: returns the y value of the first endpt

    double get_x1() const;
    // pre: none
    // post: returns the x value of the second endpt

    double get_y1() const;
    // pre: none
    // post: returns the y value of the second endpt

    void set_endpt0(double new_x, double new_y);
    // pre: none
    // post: sets the coordinates for the first endpoint to (new_x, new_y)

    void set_endpt1(double new_x, double new_y);
    // pre: none
    // post: sets the coordinates for the second endpoint to (new_x, new_y)

    bool on_segment(double, double) const;
    // pre: none
    // post: returns true iff the given point is on this segment (btwn the two endpoints)

    double x_intercept() const;
    double y_intercept() const;


private:
    double x0, y0, x1, y1;
    // invariants: (x0, y0) and (x1, y1) are the endpoints of this segment

};

std::ostream & operator << (std::ostream &, const segment &);
// pre-condition: none
// post-condition: outputs segment in format "(x0, y0), (x1, y1)"

std::istream & operator >> (std::istream &, segment &);
// pre-condition: none
// post-condition: reads x0, y0, x1, y1, dx, dy, x, y from input stream



#endif // SEGMENT_H
