#include "smatrix.h"
#include <iostream>
#include "entry.h"
#include <cassert>

smatrix::smatrix(std::size_t init_nrows, std::size_t init_ncols)
{
    nrows = init_nrows;
    ncols = init_ncols;
    head_ptr = NULL;
}

smatrix::smatrix(const smatrix & source)
{
    nrows = source.nrows;
    ncols = source.ncols;

    node * tail_ptr;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
}

smatrix::~smatrix()
{
    list_clear(head_ptr);
}

void smatrix::operator = (const smatrix & source)
{
    if (this == &source)
        return;

    list_clear(head_ptr);
    nrows = source.nrows;
    ncols = source.ncols;

    node *tail_ptr;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
}

std::size_t smatrix::get_nrows() const
{
    return nrows;
}

std::size_t smatrix::get_ncols() const
{
    return ncols;
}

void smatrix::add_entry(const entry &e)
{
    assert(e.r < nrows && e.c < ncols);

    list_head_insert(head_ptr, e);
    for (node *cursor = head_ptr; cursor->link() != NULL; cursor = cursor->link())
    {
        entry e1 = cursor->data();
        entry e2 = cursor->link()->data();

        if (e1 == e2)
        {
            list_remove(cursor);
            return;
        }

        if (e1 < e2)
            return;

        cursor->set_data(e2);
        cursor->link()->set_data(e1);
    }
}

std::ostream & operator << (std::ostream & os,
                            const smatrix & m)
{

    os << "[" << m.nrows << ", " << m.ncols << "]";

    for (node *cursor = m.head_ptr; cursor != NULL;
         cursor = cursor->link())
    {
        os << cursor->data();
    }

    return os;
}

std::istream & operator >>(std::istream &is,
                           smatrix &m)
{
    is >> m.nrows >> m.ncols;

    int r, c;
    double v;

    while (true)
    {
        is >> r >> c >> v;
        if (r == -1 && c == -1)
            break;
        m.add_entry(entry(r, c, v));
    }

    return is;



}






