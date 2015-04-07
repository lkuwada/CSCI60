#ifndef POLY_H
#define POLY_H

#include <cstdlib>
#include <iostream>

class poly
{
public:
    typedef std::size_t size_type;


// CONSTRUCTORS
    poly(size_type d = 0);
    // pre: none
    // post: a new polynomial has been created and initialized to 0x^d + 0x^(d-1) + ... + 0x + 0

    poly(const poly &);
    // pre: none
    // post: a new polynomial, which is a copy of given poly, has been created


// DESTRUCTOR
    ~poly();
    // pre: none
    // post: dynamically allocated memory has been returned to OS

    size_type degree () const;
    // pre: none
    // post: returns the degree of this poly


// CONSTANT MEMBER FUNCTIONS
    double operator [] (size_type i) const;
    // pre: none
    // post: returns the coefficient of term x^i. If i > degree(), return 0

    double operator () (double v) const;
    // pre: none
    // post: returns the value of this poly evalutated at v

    poly derivative() const;
    // pre: none
    // post: returns the derivative of this poly

    poly integral() const;
    // pre: none
    // post: returns the indefinite integral of this poly with zero constant term


// NON-CONSTANT MEMBER FUNCTIONS
    void operator = (const poly &);
    // pre: none
    // post: makes this poly a copy of the given poly (need to allocate a new dynamic array)

    void set_coeff (std::size_t i, double v);
    // pre: none
    // post: set the coefficient of x^i to v

    void operator += (const poly &);
    // pre: none
    // post: given poly has been added to this poly


private:
    double *coeff;
    size_type d;
    // invariants:
    // 1. coeff[0], ..., coeff[d] stores the coefficients of x^0, ..., x^d (hence the dynamic array has size d+1)
    // 2. d is the degree of this polynomial
};

std::ostream & operator << (std::ostream &, const poly &);
// pre: none
// post: outputs this poly to the output stream os in the format coeff[d]x^d + ... + coeff[0]x^0

std::istream & operator >> (std::istream &, poly &);
// pre: none
// post: read a poly from the input stream is in the format d coeff[d] coeff[d-1] ... coeff[0]


#endif // POLY_H
