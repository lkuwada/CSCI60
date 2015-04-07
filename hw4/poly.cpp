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

double poly::operator [] (size_type i) const
{
    if (i > d)
        return 0.0;
    else
        return coeff[i];
}

double poly::operator () (double x) const
{
    double eval(1), ans(0);

        for (size_type i = 0; i <= d; ++i)
        {
            for (size_type j = i; j > 0; --j)
                eval *= x;

            eval *= coeff[i];
            ans += eval;
            eval = 1;
        }
        return ans;
}

poly poly::derivative() const
{
    if (d == 0)
        return poly();

    poly ans(d - 1);

    for (size_type i = 0; i < d; ++i)
    {
        ans.coeff[i] = (i + 1) * coeff[i + 1];
    }
    return ans;
}

poly poly::integral() const
{
    poly ans(d + 1);

    for (size_type i = 1; i <= d + 1; ++i)
    {
        ans.coeff[i] = coeff[i - 1] / (i);
    }
    ans.coeff[0] = 0;
    return ans;
}

void poly::operator = (const poly & p)
{
    if (this == &p) // checks for self-assignment
        return;

    if (p.d != d)
    {
        double *new_coeff = new double[p.d + 1];
        d = p.d;

        std::copy(coeff, coeff + d + 1, new_coeff);
        delete [] coeff;
        coeff = new_coeff;
    }
    else
    {
        std::copy(p.coeff, p.coeff + d + 1, coeff);
    }

}

void poly::set_coeff(size_type i, double v)
{
    if (i > d)
    {
        double *new_coeff = new double[i + 1];
        d = i;
        for (size_type j = 0; j <= i; ++j)
            new_coeff[j] = 0.0;

        std::copy(coeff, coeff + d + 1, new_coeff);
        delete [] coeff;
        coeff = new_coeff;
    }
    coeff[i] = v;
}

void poly::operator += (const poly & p)
{
    if (p.d > d)
    {
        poly ans(p.d);
        std::copy(coeff, coeff + d, ans.coeff);
        *this = ans;
    }

    for (size_type i = 0; i <= p.d; ++i)
    {
        coeff[i] += p.coeff[i];
    }
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
    for (poly::size_type i = p.degree(); i > 0; --i)
    {
        os << p[i] << "x^" << i << " + ";
    }
   os << p[0] << "x^0";
    return os;
}
