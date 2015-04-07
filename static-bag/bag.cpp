#include "bag.h"
#include <algorithm>
#include <cassert>
#include <iostream>

bag::bag()
{
    used = 0;
}

bag::size_type bag::size() const
{
    return used;
}

bag::size_type bag::count(const value_type & target) const
{
    size_type ans(0);

    for (size_type i = 0; i < used; ++i)
        if (data[i] == target)
            ++ans;

    return ans;
}

void bag::insert(const value_type &target)
{
    assert (size() < CAPACITY);
    data[used++] = target; // not the same as [++used]; can do [used++] instead of next line
    //++used;
}

bool bag::erase_one(const value_type &target)
{
    size_type i;

    for (i = 0; i < used && data[i] != target; ++i)
        ;

    if (i == used)
        return false;

    //--used;
    data[i] = data[--used];
    return true;
}

bag::size_type bag::erase(const value_type &target)
{
    size_type i(0), ans(0);

    while (i < used) // for-loops do not have to have all 3 parameter specifications.
    {
        if (data[i] != target)
            ++i;
        else
        {
            data[i] = data[--used];
            ++ans;
        }
    }

    return ans;
}

void bag::operator += (const bag & b)
{
    assert(size() + b.size() <= CAPACITY);
    std::copy(b.data, b.data + b.used, data + used);
    used += b.used;
}

bag operator + (const bag & b1, const bag & b2)
{
    assert (b1.size() + b2.size() <= bag::CAPACITY);
    bag ans;
    ans += b1;
    ans += b2;
    return ans;
}

void bag::operator -=(const bag & b)
{
    for (bag::size_type i = 0; i < b.used; ++i)
    {
        for (bag::size_type j = 0; j < used; ++j)
        {
            if (b.data[i] == data[j])
            {
                this->erase_one(b.data[i]);
                break;
            }
        }
    }
}

bag operator - (bag & b1, const bag & b2)
{
    bag ans;
    ans += b1;
    ans -= b2;
    return ans;
}








