#include "biguint.h"
#include <cassert>
#include <cctype>
#include <cstring>


biguint::biguint (unsigned int initial)
{
    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    size_type k = 0;
    while (initial != 0)
    {
        data[k++] = initial % 10;
        initial /= 10;
    }
}

biguint::biguint (const std::string & s)
{
    size_type l = s.length();

    assert (l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert (isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';
}

biguint::biguint (const char s[])
{
    size_type l = strlen(s);

    assert (l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert (isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';
}



biguint::size_type biguint::operator [] (size_type p) const
{
    assert (p < CAPACITY);
    return data[p];
}

int biguint::compare (const biguint & n) const
{
    for (size_type i = CAPACITY - 1; i > 0; --i)
    {
        if (data[i] > n[i])
            return 1;
        if (data[i] < n[i])
            return -1;
    }

    return 0;
}

void biguint::rshift()
{

    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        data [i] = data [i + 1];
    }
    data[CAPACITY - 1] = 0;

}

void biguint::operator += (const biguint & b)
{
    int carry(0), sum;
    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        sum = carry + data[i] + b.data[i];
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

void biguint::operator *= (size_type d)
{
    assert(d <= 9);

    int carry(0), sum;
    for (size_type i = 0; i < CAPACITY - 1; ++i)
    {
        sum = carry + data[i] * d;
        data[i] = sum % 10;
        carry = sum / 10;
    }
}



std::ostream & operator << (std::ostream & os, const biguint & b)
{
    bool padding = true;

    for (biguint::size_type i = 0; i < biguint::CAPACITY; ++i)
    {
        biguint::size_type p = biguint::CAPACITY - 1 -i;
        if (b[p] != 0)
            padding = false;
        if (!padding)
            os << b[biguint::CAPACITY - 1 - i];
    }

    if (padding)
        os << "0";

    return os;
}

std::istream & operator >> (std::istream & is, biguint & b)
{
    std::string s;
    is >> s;
    b = biguint(s);
    return is;
}
