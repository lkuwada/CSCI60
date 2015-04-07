#ifndef ENTRY_H
#define ENTRY_H

#include <cstdlib>
#include <iostream>

struct entry
{

    entry(std::size_t init_r = -1,
          std::size_t init_c = -1,
          double init_v = 0.0)
    {
        r = init_r;
        c = init_c;
        v = init_v;
    }

    std::size_t r, c;
    double v;
};

std::ostream & operator << (std::ostream & os, const entry & e);

std::istream & operator >> (std::istream &is, entry & e);

bool operator ==(const entry &e1, const entry &e2);

bool operator !=(const entry &e1, const entry &e2);

bool operator >(const entry &e1, const entry &e2);

bool operator <(const entry &e1, const entry &e2);

#endif // ENTRY_H
