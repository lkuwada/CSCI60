#include "bag.h"
#include <algorithm>
#include <cassert>
#include <iostream>

bag::bag(size_type initial_capacity)
{
    used = 0;
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
}

bag::bag(const bag & source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    std::copy(source.data, source.data + source.used, data);
}

bag::~bag()
{
    delete [] data;
}

void bag::allocate(size_type new_capacity)
{
    if (new_capacity == capacity)
        return;

    value_type *new_data = new value_type[new_capacity];
    copy(data, data+used, new_data);
    delete [] data;
    data = new_data;
    capacity = new_capacity;

}

void operator = (const bag & source)
{
    if (this == &source) // "this" is a keyword; it returns the address of current object
        return;

    value_type *new_data;

    if (capacity != source.capacity)
    {
        new_data = new value_type[source.capacity];
        delete [] data;
        data = new_data;
        capacity = source.capacity;
    }

    used = source.used;
    copy(source.data, source.data + source.used, data);
}

void bag::insert(const value_type &target)
{
    if (used == capacity)
        allocate(2*capacity);
    data[used++] = target;
}

void bag::operator +=(const bag & source)
{
    if (used + source.used > capacity)
        allocate(used + source.used);
    copy(source.data, source.data + source.used, data+used);
    used += source.used;
}

bag operator +(const bag & b1, const bag & b2)
{
    bag ans(b1);
    ans += b2;
    return ans;
}

bag::size_type bag::size() const
{
    return used;
}





