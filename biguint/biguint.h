#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// 2^64 < 10^33
// specifications: +, *, /, %, input, output, (no subtraction)


// WANT: representation of UNSIGNED integers having lots of digits

class biguint
{
public:

    typedef std::size_t size_type;
    static const size_type CAPACITY = 20;

    //biguint ();
    // pre-condition: none
    // post-condition: this biguint has been initialized to 0

    biguint (unsigned int = 0); //can combine this and first constructor by initializing value to 0
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value

    biguint (const std::string & s); //not using namespace so you have to do "std::string"
    // pre-condition: s has at most CAPACITY characters, which must all be decimal digits
    // post-condition: this biguint has been initialized to given value represented by given string

    biguint (const char[]);
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value represented by given c-string



    size_type operator[] (size_type p) const;
    // pre-condition: p < CAPACITY
    // post-condition: the p^th least significant digit is returned

    void operator += (const biguint &);
    // pre-condition: none
    // post-condition: this biguint has been incremented by given value

    void operator *= (size_type d);
    // pre-condition: d < 10
    // post-condition: this biguint has been multiplied by given digit

    void operator *= (const biguint &);
    // pre-condition: none
    // post-condition: this biguint has been multiplied by given value

    int compare (const biguint & n) const;
    // pre-condition: none
    // post-condition: returns 0 if n == this biguint, -1 if n > this biguint, 1 if < this biguint

    void rshift ();
    // pre-condition: none
    // post-condition: the digits of this biguint have been shifted right by one position; the new leftmost digit is 0, and the old
    //                 rightmost digit is discarded


private:
    size_type data[CAPACITY];
    // invariants:
    //      1. The digits of this biguint are stored in data[0], data[1], ... , data[CAPACITY-1]
    //      2. Least significant digit it at 0
    //         Most significant digit is at CAPACITY-1
    //      3. Unused digits are filled with 0

};


std::ostream & operator << (std::ostream &, const biguint &);
std::istream & operator >> (std::istream &, biguint &);


#endif // BIGUINT_H
