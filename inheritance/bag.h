// FILE: bag5.h (part of the namespace main_savitch_chapter6)
// TEMPLATE CLASS PROVIDED:
//   bag<Item> (a collection of items; each item may appear multiple times)
//
// TYPEDEFS for the bag<Item> template class:
//   bag<Item>::value_type
//     This is the Item type from the template parameter.
//     It is the data type of the items in the bag. It may be any
//     of the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, a copy constructor, an assignment
//     operator, and a test for equality (x == y).
//
//   bag<Item>::size_type
//     This is the data type of any variable that keeps track of how many items
//     are in a bag
//
//   bag<Item>::iterator and bag<Item>::const_iterator
//     Forward iterators for a bag or a const bag.
//
// CONSTRUCTOR for the bag<Item> class:
//   bag( )
//     Postcondition: The bag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bag<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bag, then one copy of target has
//     been removed from the bag; otherwise the bag is unchanged. A true
//     return value indicates that one copy was removed; false indicates that
//     nothing was removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const bag& addend)
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag<Item> class:
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag.
//
//   Item grab( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is a randomly selected item from the bag.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bag.
//
// STANDARD ITERATOR MEMBER FUNCTIONS (provide a forward iterator):
//   iterator begin( )
//   const_iterator begin( ) const
//   iterator end( )
//   const iterator end( ) const
//
// NONMEMBER FUNCTIONS for the bag<Item> class:
//   template <class Item>
//   bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag<Item> class:
//    Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag<Item>:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, insert, operator +=, operator +, and the
//   assignment operator.

#ifndef MAIN_SAVITCH_BAG5_H
#define MAIN_SAVITCH_BAG5_H
#include <cstdlib>   // Provides NULL and size_t and NULL
#include "node.h"   // Provides node class

namespace main_savitch_6B
{
    template <class Item>
    class bag
    {
      public:
    // TYPEDEFS
    typedef std::size_t size_type;
    typedef Item value_type;
    typedef node_iterator<Item> iterator;
    typedef const_node_iterator<Item> const_iterator;

    // CONSTRUCTORS and DESTRUCTOR
    bag( );
    bag(const bag& source);
    ~bag( );

    // MODIFICATION MEMBER FUNCTIONS
    size_type erase(const Item& target);

    bool erase_one(const Item& target);

    virtual void insert(const Item& entry);

    void operator +=(const bag& addend);

    void operator =(const bag& source);

    // CONST MEMBER FUNCTIONS
    size_type count(const Item& target) const;

    Item grab( ) const;

    size_type size( ) const
    {
        return many_nodes;
    }


    // FUNCTIONS TO PROVIDE ITERATORS
    iterator begin()
    {
        return iterator(head_ptr);
    }

    const_iterator begin() const
    {
        return const_iterator(head_ptr);
    }

    iterator end()
    {
        return iterator();
    } // Uses default constructor

    const_iterator end( ) const
    {
        return const_iterator();
    } // Uses default constructor

private:
    node<Item> *head_ptr; // Head pointer for the list of items
    size_type many_nodes; // Number of nodes on the list


    };

    // NONMEMBER functions for the bag
    template <class Item> bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);

}

// The implementation of a template class must be included in its header file:

// FILE: bag5.template
// CLASS implemented: bag (see bag5.h for documentation)
// NOTE:
//   Since bag is a template class, this file is included in node2.h.
// INVARIANT for the bag class:
//   1. The items in the bag are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//       many_nodes.

#include <cassert>  // Provides assert
#include <cstdlib>  // Provides NULL, rand
#include "node.h"  // Provides node

namespace main_savitch_6B
{
    template <class Item>
    bag<Item>::bag( )
    // Library facilities used: cstdlib
    {
        head_ptr = NULL;
        many_nodes = 0;
    }

    template <class Item>
    bag<Item>::bag(const bag<Item>& source)
    // Library facilities used: node2.h
    {
        node<Item> *tail_ptr;  // Needed for argument of list_copy

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }

    template <class Item>
    bag<Item>::~bag( )
    // Library facilities used: node2.h
    {
        list_clear(head_ptr);
        many_nodes = 0;
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::count(const Item& target) const
    // Library facilities used: cstdlib, node2.h
    {
        size_type answer;
        const node<Item> *cursor;

        answer = 0;
        cursor = list_search(head_ptr, target);
        while (cursor != NULL)
        {
        // Each time that cursor is not NULL, we have another occurrence of
        // target, so we add one to answer, and move cursor to the next
        // occurrence of the target.
            ++answer;
            cursor = cursor->link( );
            cursor = list_search(cursor, target);
        }
        return answer;
    }

    template <class Item>
    typename bag<Item>::size_type bag<Item>::erase(const Item& target)
    // Library facilities used: cstdlib, node2.h
    {
        size_type answer = 0;
        node<Item> *target_ptr;

        target_ptr = list_search(head_ptr, target);
        while (target_ptr != NULL)
        {
            // Each time that target_ptr is not NULL, we have another occurrence
        // of target. We remove this target using the same technique that
        // was used in erase_one.
            ++answer;
            target_ptr->set_data( head_ptr->data( ) );
            target_ptr = target_ptr->link( );
            target_ptr = list_search(target_ptr, target);
            list_head_remove(head_ptr);
        }
        return answer;
    }

    template <class Item>
    bool bag<Item>::erase_one(const Item& target)
    // Library facilities used: cstdlib, node2.h
    {
        node<Item> *target_ptr;

        target_ptr = list_search(head_ptr, target);
        if (target_ptr == NULL)
            return false; // target isn't in the bag, so no work to do

        target_ptr->set_data( head_ptr->data( ));
        list_head_remove(head_ptr);
        --many_nodes;
        return true;
    }

    template <class Item>
    Item bag<Item>::grab( ) const
    // Library facilities used: cassert, cstdlib, node2.h
    {
        size_type i;
        const node<Item> *cursor;

        assert(size( ) > 0);
        i = (std::rand( ) % size( )) + 1;
        cursor = list_locate(head_ptr, i);
        return cursor->data( );
    }

    template <class Item>
    void bag<Item>::insert(const Item& entry)
    // Library facilities used: node2.h
    {
        list_head_insert(head_ptr, entry);
        ++many_nodes;
    }

    template <class Item>
    void bag<Item>::operator +=(const bag<Item>& addend)
    // Library facilities used: node2.h
    {
        node<Item> *copy_head_ptr;
        node<Item> *copy_tail_ptr;

        if (addend.many_nodes > 0)
        {
            list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
            copy_tail_ptr->set_link( head_ptr );
            head_ptr = copy_head_ptr;
            many_nodes += addend.many_nodes;
        }
    }

    template <class Item>
    void bag<Item>::operator =(const bag<Item>& source)
    // Library facilities used: node2.h
    {
        node<Item> *tail_ptr; // Needed for argument to list_copy

        if (this == &source)
            return;

        list_clear(head_ptr);
        many_nodes = 0;

        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
    }

    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2)
    {
        bag<Item> answer;

        answer += b1;
        answer += b2;
        return answer;
    }

}

#endif
