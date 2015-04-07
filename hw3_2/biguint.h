#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>


class biguint
{
public:

    typedef std::size_t size_type;
    static const size_type CAPACITY = 10;

// CONSTRUCTORS
    biguint (unsigned int = 0);
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value

    biguint (const std::string & s);
    // pre-condition: s has at most CAPACITY characters, which must all be decimal digits
    // post-condition: this biguint has been initialized to given value represented by given string

    biguint (const char[]);
    // pre-condition: none
    // post-condition: this biguint has been initialized to given value represented by given c-string


    size_type operator[] (size_type pos) const;
    // pre-condition: pos < bigugint::CAPACITY
    // post-condition: the digit at position pos is returned (the least significant digit is at postition 0)

    void operator += (const biguint &);
    // pre-condition: none
    // post-condition: the value of this biguint has been incremented by n. the overflow digit is discarded if there is one

    void operator *= (size_type d);
    // pre-condition: d <= 9
    // post-condition: the value of this biguing has been multiplied by the digit d; the overfow digit discarded if there is one

    int compare (const biguint & n) const;
    // pre-condition: none
    // post-condition: returns 0 if n == this biguint, -1 if n > this biguint, 1 if < this biguint

    void rshift ();
    // pre-condition: none
    // post-condition: the digits of this biguint have been shifted right by one position; the new leftmost digit is 0, and the
    //                 old rightmost digit is discarded


    void operator -= (const biguint &);
    // pre-condition: none
    // post-condition: if this biguint >= n, then n is subtracted from this biguint; else set this biguint to zero



    void lshift();
    // pre-condition: none
    // post-condition: the digits of this biguint have been shifted left by one position; the new rightmost digit is 0, and the old
    //                 leftmost digit is discarded

    void operator *= (const biguint & n);
    // pre-condition: none
    // post-condition: the value of this biguint has been multiplied by n; any overflow digits are discarded

    void operator /= (const biguint & n);
    // pre-condition: n != 0
    // post-condition: the new value of this biguint is the old value divided by n and truncated

    void operator %= (const biguint & n);
    // pre-condtion: n != 0
    // post-condition: the new value of this biguint is the reaminder of the old value when divided by n

    void operator ^= (const biguint & n);
    // pre-condition: none
    // post-condition: the new value of this biguint is the n^(th) power of the old value


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

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);
biguint operator * (const biguint &, const biguint &);

#endif // BIGUINT_H
