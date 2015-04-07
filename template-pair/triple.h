#ifndef TRIPLE_H
#define TRIPLE_H

#include <iostream>

// template classes must be implemented in the same file. cannot implement in the .cpp file.


template <class T> //keyword "template" means T is going to be a parameter, type will be specified

class triple
{
public:
    triple(const T & init_a = T(), const T & init_b = T(), const T & init_c = T())
    {
        a = init_a;
        b = init_b;
        c = init_c;
    }

    T & get_a()  // return type T. "&" says function will not return a copy of a/b/c but it will return the actual object
    {
        return a;
    }

    const T & get_a () const
    {
        return a;
    }

    T & get_b()  //       returns the reference to the variable...
    {
        return b;
    }

    const T & get_b () const
    {
        return b;
    }

    T & get_c()
    {
        return c;
    }

    const T & get_c() const
    {
        return c;
    }

    void set_a (const T & v)
    {
        a = v;
    }

    void set_b (const T & v)
    {
        b = v;
    }

    void set_c (const T & v)
    {
        c = v;
    }

private:
    T a, b, c;
};

template <class T>
std::ostream & operator << (std::ostream & os, const triple<T> & t)
{
    os << t.get_a() << ", " << t.get_b() << ", " << t.get_c();
    return os;
}

template <class T>
std::istream & operator >> (std::istream & is, triple<T> & t)
{
    T a, b, c;
    is >> a >> b >> c;
    t = triple<T>(a, b, c);
    return is;
}


// can do this instead of doing it in the public sectin. instead of hardcoding the definition...

//template <class T> // 'T' can be any name... textbook calls it Item.
//triple::triple (const T & init_a, const T & init_b, const T & init_c)
//{
//    a = init_a;
//    b = init_b;
//    c = init_c;
//}



#endif // TRIPLE_H
