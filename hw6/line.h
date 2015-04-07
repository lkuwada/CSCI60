#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <utility>


class line
{
public:

// CONSTRUCTOR
    line(double init_x = 0.0,
         double init_y = 0.0,
         double init_dx = 1.0,
         double init_dy = 0.0);


// CONSTANT MEMBER FUNCTIONS
    double slope() const;
    // pre-condition: line is not vertical
    // post-condition: slope of this line is returned

    bool is_vertical() const;
    // pre-condition: none
    // post-condition: true if line is vertical

    bool is_horizontal() const;
    // pre-condition: none
    // post-condition: true if line is horizontal

    bool is_parallel(const line &) const;
    // pre-condition: none
    // post-condition: true if the two lines are parallel

    double x_intercept() const;
    // pre-condition: line is not horizontal
    // post-condition: x-intercept is returned

    double y_intercept() const;
    // pre-condition: line is not vertical
    // post-condition: y-intercept is returned

    double get_x() const;
    // pre-condition: none
    // post-condition: returns x-coordinate of the point

    double get_y() const;
    // pre-condition: none
    // post-condition: returns y-coordinate of the point

    double get_dx() const;
    // pre-condition: none
    // post-condition: returns the x component of the line vector (run)

    double get_dy() const;
    // pre-condition: none
    // post-condition: returns the y component of the line vector (rise)


// NON-CONSTANT MEMBER FUNCTIONS
    void vshift(double);
    // pre-condition: none
    // post-condition: line is shifted vertically by given amount

    void hshift(double);
    // pre-condition: none
    // post-condition: line is shifted horizontally by given amount


    friend std::ostream & operator << (std::ostream &, const line &);
    friend std::istream & operator >> (std::istream &,  line &);


private:
    double x, y, dx, dy;
    // class invariants: (x, y) is a point on this line. (dx, dy) is the line vector (run, rise).


};

//NON-MEMBER FUNCTIONS
std::ostream & operator << (std::ostream &, const line &);
// pre-condition: none
// post-condition: outputs line in format "(x, y), (dx, dy)"

std::istream & operator >> (std::istream &, line &);
// pre-condition: none
// post-condition: reads x, y, dx, dy from input stream

std::pair<double, double> operator * (const line & l1, const line & l2);
// pre-condition: l1 and l2 are not parallel
// post-condition: returns the intersection of l1 and l2



#endif // LINE_H
