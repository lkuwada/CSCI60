#ifndef BAG_H
#define BAG_H
#include <cstdlib>

// We want to make a tool, BAG, to store elements of the same type
// Each collection has a fixed size
// Supported functions:
//  - size of bag
//  - number of occurrences of an item in bag
//      (implicitly, multiple copies of an item are allowed)
//  - insert an element into bag
//  - remove one instance of element from bag
//  - remove all instances of element from bag
//  - add content of another bag to this bag


class bag
{
public:

    typedef int value_type; // type of elements stored in this bag. easy to change if you want double, etc.
    typedef std::size_t size_type; // type for counts... "size_t" predefined type--guaranteed to be non-negative
    static const size_type CAPACITY = 10; // capacity of each bag
    //                                        this bag has constant called capacity... refer to it later call bag::CAPACITY.
    //                                        use upper case because constant variable. only one copy of this value for whole class
    //                                        because it is static (each instance does not have own copy of CAPACITY).



// CONSTRUCTOR
    bag();
    // pre-condition: none
    // post-condition: an empty bag has been created



// CONSTANT MEMBER FUNCTIONS (Do not change the bag, only return information about the bag)
    size_type size() const;
    // pre-condition: none
    // post-condition: return the number of items in this bag

    size_type count(const value_type & target) const; // pass by reference (which allows you to change the object) so you put const
    // pre-condition: none                               so it won't change any value
    // post-condition: returns the number of times (including zero) target occurs in this bag



// NON-CONSTANT MEMBER FUNCTIONS (functions that CAN change the bag)
    void insert(const value_type & target);
    // pre-condition: bag is not full
    // post-condition: a new instance of target has been added to this bag

    bool erase_one(const value_type & target);
    // pre-condition: none
    // post-condition: if target is in this bag, one instance is removed and the return value is true; else (target is not in this
    //                 bag), nothing changes and return value is false

    size_type erase(const value_type & target);
    // pre-condition: none
    // post-condition: removes all occurrences of target in this bag and returns the number of items removed (zero allowed)

    void operator += (const bag & b);
    // pre-condition: size() + b.size() <= CAPACITY
    // post-condition: a copy of the content of b has been added to this bag

    void operator -= (const bag & b);



private:
    value_type data[CAPACITY];
    size_type used;

    // class invariants: (contract between designer and implementor) have to make sure this value is always size of bag, etc.
    // 1. used is the number of items in this bag
    // 2. data[0], data[1], ..., dad[used-1] are the location where these items are stored.
    //    don't care about content of remaining locations


};


// NON-MEMBER FUNCTIONS
bag operator + (const bag & b1, const bag & b2);
// pre-condition: b1.size() + b2.size() <= bag::CAPACITY
// post-condition: a new bag has been created, whose content is the union of those of b1 and b2

bag operator - (bag & b1, const bag & b2);

#endif // BAG_H
