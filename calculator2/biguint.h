#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: representation UNSIGNED integers having lots of digits

class biguint
{

  public:

    typedef std::size_t size_type;
    static const size_type CAPACITY = 1000;

    biguint (unsigned int = 0);
    // pre: none
    // post: this biguint has been initialized to given integer, default to 0

    biguint (const std::string & s);
    // pre: s has at most CAPACITY characters, which must all
    //      be decimal digits
    // post: this biguint has been initialized to given value
    //       represented by given string

    biguint (const char[]);
    // pre: none
    // post: this biguint has been initialized to given value
    //       represented by given c-string

    size_type operator[] (size_type p) const;
    // pre: p < CAPACITY
    // post: the p^th least significant digit is returned

    int compare(const biguint & n) const;
    // pre: none
    // post: returns 0 if n == this biguint, -1 if n > this biguint, 1 otherwise

    void rshift();
    // pre: none
    // post: the digits of this biguint have been shifted right by one position;
    //       the new leftmost digit is 0, and the old rightmost digit is discarded

    void lshift();
    // pre: none
    // post: the digits of this biguint have been shifted left by one position
    //       the new rightmost digit is 0
    //       the old leftmost digit is discarded

    void operator +=(const biguint & n);
    // pre: none
    // post: the value of this biguint has been incremented by n
    //       the overflow digit is discarded if there is one

    void operator -=(const biguint & n);
    // pre: none
    // post: the value of this biguint has been decremented by n
    //       if it is at least n
    //       otherwise the new value is 0

    void operator *=(size_type d);
    // pre: d <= 9
    // post: the value of this biguint has been multiplied by the digit d;
    //       the overflow digit is discarded if there is one

    void operator *=(const biguint &);
    // pre: none
    // post: the value of this biguint has been multiplied by the given biguint
    //       overflow digits, if any, are discarded

    void operator /=(const biguint & n);
    // pre: n != 0
    // post: the new value of this biguint is the old value divided by n 
    //       and truncated

    void operator %= (const biguint & n);
    // pre: n != 0
    // post: the new value of this biguint is the remainder of the old value
    //       when divided by n

    void operator ^= (const biguint &n);
    // pre: none
    // post: the new value of this biguint is the n^(th) power of the old value

    biguint operator ++();
    // pre: none
    // post: the value of this biguint has been incremented by one, and
    //       the NEW value is returned

    biguint operator ++(int);
    // pre: none
    // post: the value of this biguint has been incremented by one, and the
    //       ORIGINAL value is returned
    

    biguint operator --();
    // pre: none
    // post: if this biguint was positive, its value has been decremented by one
    //       otherwise if it was zero, nothing happens
    //       the new value is returned

    biguint operator --(int);
    // pre: none
    // post: if this biguint was positive, its value has been decremented by one
    //       otherwise if it was zero, nothing happens
    //       the ORIGINAL value is returned


    std::string toStdString() const;
    // pre: none
    // post: converts the value of this biguint into a string without leading zeroes



  private:
    size_type data[CAPACITY];
    // invariants:
    //   1.  the digits of this biguint are stored in
    //       data[0], data[1], ..., data[CAPACITY-1]
    //   2.  Least significant digit is at 0
    //       Most significiant digit is at CAPACITY -1
    //   3.  Unused digits are filled with 0


};

std::ostream & operator << (std::ostream &, const biguint &);
std::istream & operator >> (std::istream &, biguint &);

bool operator <(const biguint &, const biguint &);
bool operator <=(const biguint &, const biguint &);
bool operator ==(const biguint &, const biguint &);
bool operator !=(const biguint &, const biguint &);
bool operator >=(const biguint &, const biguint &);
bool operator >(const biguint &, const biguint &);

biguint operator +(const biguint &, const biguint &);
biguint operator -(const biguint &, const biguint &);
biguint operator /(const biguint &, const biguint &);
biguint operator *(const biguint &, const biguint &);
biguint operator %(const biguint &, const biguint &);
biguint operator ^(const biguint &, const biguint &);

#endif // BIGUINT_H
