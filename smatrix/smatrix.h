//#ifndef SMATRIX_H
//#define SMATRIX_H

//#include <cstdlib>
//#include "node.h"


//class smatrix
//{
//public:
//    smatrix(std::size_t init_nrows = 0, std::size_t init_ncols = 0);
//    // pre: none
//    // post: an emtry sparse matrix has been created

//    smatrix(const smatrix &);
//    // pre: none
//    // post: a copy of the given sparse matrix has been created

//    ~smatrix();
//    // pre: none
//    // post: this sparse matrix has been destroyed

//    void operator = (const smatrix &);
//    // pre: none
//    // post: this sparse matrix has been assigned a new value which is the given sparse matrix

//    std::size_t get_nrows() const;
//    // pre: none
//    // post: returns the number of rows of this sparse matrix

//    std::size_t get_ncols() const;
//    // pre: none
//    // post: returns the number of cols of this sparse matrix

//    double entry (std::size_t, std::size_t) const;
//    // pre: r < nrows, c < ncols
//    // post: returns the value at given position

//    bool is_diagonal() const;
//    // pre: nrows == ncols
//    // post: returns true iff this sparse matrix is diagonal

//    void add_entry(const entry & e);
//    // pre: e.r < nrows && e.c < ncols
//    // post: add a new entry to this sparse matrix, overriding old value if it exists

//    void operator += (const smatrix &);
//    // pre: dimensions of m and this matrix must be the same
//    // post: m has been added to this matrix

//    void operator *= (double c);
//    // pre: none
//    // post: scalar c has been multiplied to this sparse matrix

//    void transpose();
//    // pre: none
//    // post: this sparse matrix has been transposed (first row becomes first column, etc)

//    friend std::ostream & operator << (std::ostream &, const smatrix &);
//    friend std::istream & operator >> (std::istream &, smatrix &);


//private:
//    std::size_t nrows, ncols;
//    node * head_ptr;

//    // invariants:
//    // nrows and ncols are the dimensions of this sparse matrix
//    // the entries of this sparse matrix are stored in linked list with head pointer head_ptr
//    // each entry is a triple (row, col, value)
//    // and the entries are stored in terms of rows and cols
//    // (0, 0), (0, 1), ..., (1, 0), (1, 1) ..
//    // if an entry is not on this list, its value is assumed to be zero
//};

//std::ostream & operator << (std::ostream &, const smatrix &);
//std::istream & operator >> (std::istream &, smatrix &);

//#endif // SMATRIX_H


#ifndef SMATRIX_H
#define SMATRIX_H

#include <cstdlib>
#include "node.h"


class smatrix
{
public:
    smatrix(std::size_t init_nrows = 0, std::size_t init_ncols = 0);
    // pre: none
    // post: an empty sparse matrix has been created

    smatrix(const smatrix &);
    // pre: none
    // post: a copy of the given sparse matrix has been created

    ~smatrix();
    // pre: none
    // post: this sparse matrix has been destroyed

    void operator =(const smatrix & );
    // pre: none
    // post: this sparse matrix has been assigned a new value
    //       which is the given sparse matrix

    double get_entry(std::size_t r, std::size_t c) const;
    // pre: r < nrows, c < ncols
    // post: returns the value at given position

    std::size_t get_nrows() const;
    // pre: none
    // post: returns the number of rows of this sparse matrix

    std::size_t get_ncols() const;
    // pre: none
    // post: returns the number of cols of this sparse matrix

    bool is_diagonal() const;
    // pre: nrows == ncols
    // post: returns true iff this sparse matrix is diagonal

    void add_entry(const entry &);
    // pre: none
    // post: add a new entry to this sparse matrix, overriding
    //       old value if it exists

    void operator +=(const smatrix & m);
    // pre: dimensions of m and this matrix must be the same
    // post: m has been added to this matrix

    void operator *=(double c);
    // pre: none
    // post: scalar c has been multiplied to this sparse matrix

    void transpose();
    // pre: none
    // post: this sparse matrix has been transposed

    friend std::ostream & operator << (std::ostream &, const smatrix &);
    friend std::istream & operator >> (std::istream &, smatrix &);

private:
    std::size_t nrows, ncols;
    node * head_ptr;

    // invariants:
    // nrows and ncols are the dimensions of this sparse matrix
    // the entries of this sparse matrix are stored in linked
    // list with head pointer head_ptr
    // each entry is a triple (row, col, value)
    // and the entries are sorted in terms of row and col
    // (0, 0), (0, 1), ..., (1, 0), (1, 1), ...., ...

};

std::ostream & operator << (std::ostream &, const smatrix &);
std::istream & operator >> (std::istream &, smatrix &);

#endif // SMATRIX_H
