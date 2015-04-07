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

bool smatrix::is_diagonal() const
{
    assert (nrows == ncols);
    size_t counter(0);

    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().c == cursor->data().r && cursor->data().v != 0)
            ++counter;
        if (cursor->data().c != cursor->data().r && cursor->data().v != 0)
            return false;
    }

    if (counter == nrows)
        return true;
}

double smatrix::get_entry(std::size_t r, std::size_t c) const
{
    assert (r < nrows && c < ncols);

    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data().r == r && cursor->data().c == c)
            return cursor->data().v;
    }
}

void smatrix::operator +=(const smatrix & m)
{
    assert (nrows == m.get_nrows() && ncols == m.get_ncols());

    node *cursor = head_ptr, * m_cursor = m.head_ptr;
    while (m_cursor != NULL)
    {
        if (cursor == NULL || (m_cursor->data() < cursor->data()))
        {
            add_entry(m_cursor->data());
            m_cursor = m_cursor->link();
        }
        else if (cursor->data() == m_cursor->data())
        {
            entry new_data(cursor->data().r, cursor->data().c, cursor->data().v + m_cursor->data().v);
            cursor->set_data(new_data);
            m_cursor = m_cursor->link();
            cursor = cursor->link();
        }
        else
            cursor = cursor->link();
    }
}

void smatrix::operator *= (double c)
{
    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        entry temp(cursor->data().r, cursor->data().c, cursor->data().v * c);
        cursor->set_data(temp);
    }
}

void smatrix::transpose()
{
    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        entry temp1(cursor->data().c, cursor->data().r, cursor->data().v);
        cursor->set_data(temp1);
    }

}



std::ostream & operator << (std::ostream & os,
                            const smatrix & m)
{

    os << "[" << m.nrows << ", " << m.ncols << "]";

    for (node *cursor = m.head_ptr; cursor != NULL; cursor = cursor->link())
    {
        os << cursor->data();
    }

    return os;
}

std::istream & operator >>(std::istream &is, smatrix &m)
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






