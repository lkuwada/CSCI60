#ifndef MAXBAG_H
#define MAXBAG_H

#include "bag.h"

// maxbag is a DERIVED class based on the BASE class main_savitch_6B::bag<T>

// since this is a PUBLIC derived class, all public members of bag are public members of maxbag
// (we say maxbag inherits public members of bag)

// friends are NOT inherited
// constructors, destructors, assignment operators of the BASE class are NOT inherited
// however, they are accessible

// if constructor is not provided for DERIVED class, C++ will provide one, which
//  a) calls the default constructor of the BASE class
//  b) calls the default constructor for each new member variable

template <class T>
class maxbag: public main_savitch_6B::bag<T>
{

public:
    T max() const;

};



template <class T>
T maxbag<T>::max() const
{
    main_savitch_6B::bag<T>::const_iterator i(main_savitch_6B::bag<T>::begin());
    T answer(*i);

    while (++i != main_savitch_6B::bag<T>::end())
        if (*i > answer)
            answer = *i;
    return answer;


    //return *std::max_element(main_savitch_6B::bag<T>::begin(), main_savitch_6B::bag<T>::end());
}

#endif // MAXBAG_H
