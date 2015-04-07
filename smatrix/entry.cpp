#include "entry.h"
#include <cstdlib>
#include <iostream>

std::ostream & operator << (std::ostream & os,
                            const entry & e)
{
    os << "(" << e.r << ", " << e.c << ", " << e.v << ")";
    return os;
}

std::istream & operator >> (std::istream &is,
                            entry & e)
{
    is >> e.r >> e.c >> e.v;
    return is;
}

bool operator ==(const entry &e1, const entry &e2)
{
    return (e1.r == e2.r && e1.c == e2.c);

}

bool operator !=(const entry &e1, const entry &e2)
{
    return !(e1 == e2);
}

bool operator >(const entry &e1, const entry &e2)
{
    return (e1.r > e2.r ||
            (e1.r == e2.r && e1.c > e2.c));

}

bool operator <(const entry &e1, const entry &e2)
{
    return (e1.r < e2.r ||
            (e1.r == e2.r && e1.c < e2.c));

}
