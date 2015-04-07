#ifndef NAMEDBAG_H
#define NAMEDBAG_H

#include "bag5.h"
#include <string>

template <class T>
class namedbag: public main_savitch_6B::bag<T>
{
public:
    // default constructor
    // called first, and then default constructor of the BASE class will be called
    namedbag()
    {
        name = std::string();
    }

    // copy constructor
    namedbag(const main_savitch_6B::bag<T> & source, const std::string init_name)
        : main_savitch_6B::bag<T>(source), name(init_name)
    {

    }

    // called first, and then destructor of the BASE class will be called
    ~namedbag()
    {

    }

    void operator = (const namedbag & source)
    {
        if (this = &source) // self assignment
            return;

        main_savitch_6B::bag<T>::operator=(source);
        name = source.name;
    }

    void setname(const std::string newname)
    {
        name = newname;
    }

    std::string getname() const
    {
        return name;
    }

private:
    std::string name;
};

#endif // NAMEDBAG_H
