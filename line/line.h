#ifndef LINE_H
#define LINE_H

#include <iostream>

//namespace lkuwada

//{

/* bare definition of a class: class name, semicolon at after last brace.
    Pre/post condition not saying how the function does whatever it does, only the what. stating requirement to make function run correctly
    */

class line
{
public:
    line(double init_x0 = 0.0,
         double init_y0 = 0.0,
         double init_x1 = 1.0,
         double init_y1 = 0.0);
    // Constructor: same name as class and no return type.

    double slope() const; // const: this function does not change the object, just gives info about object
    // pre-condition: line is not vertical
    // post-condition: slope of this line is returned

    bool is_vertical() const; // again const because it should not change the object (preventing function from modifying object)
    // pre-condition: none
    // post-condition: true if line is vertical

    bool is_horizontal() const;
    // pre-condition: none
    // post-condition: true if line is horizontal

    double x_intercept() const;
    // pre-condition: line is not horizontal
    // post-condition: x-intercept is returned

    double y_intercept() const;
    // pre-condition: line is not vertical
    // post-condition: y-intercept is returned

    void vshift(double);
    // pre-condition: none
    // post-condition: line is shifted vertically by given amount

    void hshift(double);
    // pre-condition: none
    // post-condition: line is shifted horizontally by given amount

    double get_x0() const;
    // pre-condition: none
    // post-condition: returns x-coord of first point

    double get_y0() const;
    // pre-condition: none
    // post-condition: returns y-coord of first point

    double get_x1() const;
    // pre-condition: none
    // post-condition: returns x-coord of second point

    double get_y1() const;
    // pre-condition: none
    // post-condition: returns y-coord of second point


    friend std::ostream & operator << (std::ostream &, line);
    friend std::istream & operator >> (std::istream &, line &);

// put "design" in private section. can change anything in this section and it won't matter to the user (encapsulation)
// seperate the what from the how
private:
    double x0, y0, x1, y1;
    // invariant: (x0, y0) and (x1, y1) are two distinct points on the line

    // 2nd design--problem with vertical line (slope)
    // double m, double b;
    // invariant: m is the slope, b is the intercept

    // 3rd design--problem with vertical line (slope)
    // double x0, y0, b;
    // invariant: (x0, y0) is a point on the line, m is slope

    //4th design:
    // double x0, y0, dx, dy;
    // invariant: (x0, y0) is a point on the line, (dx, dy) is line vector


};

//non member function

std::ostream & operator << (std::ostream &, line); // return type (std::ostream); name (operator <<); param (std::ostream &, line)
// pre-condition: none
// post-condition: outputs line in format "(x0, y0), (x1, y1)"

std::istream & operator >> (std::istream &, line &);
// pre-condition: none
// post-condition: reads x0, y0, x1, y1 from input stream


//}

#endif // LINE_H

