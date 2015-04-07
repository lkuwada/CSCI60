#ifndef BAG_H
#define BAG_H

#include <cstdlib>

class bag
{
public:
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type DEFAULT_CAPACITY = 10;
    // initial size of memory block

    bag(size_type initial_capacity = DEFAULT_CAPACITY);
    // pre: none
    // post: this bag has been allocated a memory block of given size

    bag(const bag & source);
    // pre: none
    // post: a bag has been created, which is a copy of the bag source

    ~bag(); // return memory at the end of a block (after end brace)
    // pre: none
    // post: this bag has been destroyed and its dynamic memory returned to the OS

    size_type size() const;
    // pre: none
    // post: returns the number of items in this bag

    size_type count(const value_type & target) const;
    // pre: none
    // post: returns the number of times target appears in this bag

    void insert(const value_type & target);
    // pre: none
    // post: a copy of target has been added to this bag

    bool erase_one(const value_type & target);
    // pre: none
    // post: if target is in this bag, one copy is removed, and true is returned; otherwise, false is returned

    size_type erase(const value_type & target);
    // pre: none
    // post: all copies of target are removed from this bag and the number of removed items is returned (zero is allowed)

    void operator += (const bag & source);
    // pre: none
    // post: content of source has been added to this bag

    void operator =(const bag & source);
    // pre: none
    // post: this bag has been made a copy of source

    void allocate(size_type new_capacity);
    // pre: none
    // post: the memory block's size has been changed to the new capacity (but only if it is >= the size of this bag)



private:
    value_type *data; //pointer
    size_type used;
    size_type capacity;

    // class invariants:
    // 1.   used is the number of items in this  bag
    // 2.   capacity is the size of the memory block allocated to this bag
    // 3.   data holds the address of the memory block allocated to this bag.
    //      the items are stored in data[0], data[1], ... , data[used - 1]
    //      don't care about values in the remaining array element


};

bag operator + (const bag &, const bag &);

#endif // BAG_H
