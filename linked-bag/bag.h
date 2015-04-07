#ifndef BAG_H
#define BAG_H

#include <cstdlib>
#include "../node/node.h"

class bag
{
public:
    typedef std::size_t size_type;
    typedef node::value_type value_type;

    bag();
    // pre: none
    // post: an empty bag has been created

    bag(const bag &);
    // pre: none
    // post: a copy of the given bag has been created

    ~bag();
    // pre: none
    // post: dynamic memory allocated to this bag have been returned to the OS

    size_type size() const;
    // pre: none
    // post: returns the number of elements in this bag

    size_type count (const value_type &) const;
    // pre: none
    // post: returns the number of times the given element appears in this bag

    void insert (const value_type & entry);
    // pre: none
    // post: a copy of entry has been inserted into this bag

    bool erase_one (const value_type &target);
    // pre: none
    // post: if target is appears in ths bag, remove one copy and return true; else return false

    size_type erase (const value_type &target);
    // pre: none
    // post: deletes all of target in this bag and returns the number of items deleted

    void operator = (const bag & b);
    // pre: none
    // post: this bag is now a copy of b

    void operator += (const bag & b);
    // pre: none
    // post: the content of b has been added to this bag

private:
    node* head_ptr;
    // invariants:
    // elements in this bag are stored in the linked list whose head address is stored in head_ptr in no particular order

};

bag operator + (const bag &, const bag &);

#endif // BAG_H
