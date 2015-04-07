#ifndef UNIBAG_H
#define UNIBAG_H

#include "bag5.h"

template <class T>
class unibag: public main_savitch_6B::bag<T>
{
public:
    unibag(const main_savitch_6B::bag<T> & source)
    {
        typename main_savitch_6B::bag<T>::const_iterator i;

        for (i = source.begin(); i != source.end(); ++i)
                insert(*i);
    }
    void insert(const T & entry)
    {
        if (count(entry) == 0)
            main_savitch_6B::bag<T>::insert(entry);
    }

};

#endif // UNIBAG_H
