#include "poly.h"
#include <algorithm>
#include <cstdlib>

poly::poly(size_type init_d)
{
    coeff = new double[1 + init_d];
    d = init_d;
    for (size_type i = 0; i <= d; ++i)
        coeff[i] = 0.0;
}

poly::poly(const poly & p)
{
    coeff = new double[1 + p.d];
    d = p.d;
    std::copy(p.coeff, p.coeff + p.d + 1, coeff);
}

poly::~poly()
{
    if (coeff != NULL)
        delete [] coeff;
}

poly::size_type poly::degree() const
{
    return d;
}

double poly::operator [](size_type i) const
{
    if (i > d)
        return 0.0;
    else
        return coeff[i];
}

void poly::set_coeff(size_type i, double v)
{
    if (i > d)
    {
        double new_coeff = new double[i + 1];
        d = i;
        for (size_type j = 0; j <= i; ++j)
            new_coeff[j] = 0.0;

        copy(coeff, coeff + d + 1, new_coeff);
        delete [] coeff;
        coeff = new_coeff;
    }
    coeff[i] = v;
}

std::istream & operator >> (std::istream & is, poly & p)
{
    poly::size_type d;
    double c;
    is >> d;

    for (int i = d; i >= 0; --i)
    {
        is >> c;
        p.set_coeff(i, c);
    }
    return is;
}

std::ostream & operator << (std::ostream & os, const poly &p)
{
    for (int i = p.degree(); i >= 0; --i)
        os << p[i] << " ";
    return os;
}
