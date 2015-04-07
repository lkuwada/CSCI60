#include "biguint.h"
#include <cassert>
#include <cctype>
#include <cstring>
#include <sstream>

biguint::biguint(unsigned int initial)
{
    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    size_type k = 0;
    while (initial != 0)
    {
        data[k++] = initial % 10;
        initial /= 10;
    }
}

biguint::biguint(const std::string & s)
{
    size_type l = s.length();

    assert(l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert(isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';

}


biguint::biguint(const char s[])
{
    size_type l = strlen(s);

    assert(l <= CAPACITY);
    for (size_type i = 0; i < l; ++i)
        assert(isdigit(s[i]));

    for (size_type i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_type i = 0; i < l; ++i)
        data[l - 1 - i] = s[i] - '0';

}


std::istream & operator >> (std::istream & is, biguint & b)
{
    std::string s;
    is >> s;
    b = biguint(s);
    return is;

}

biguint::size_type biguint::operator [] (size_type p) const
{
    assert(p < CAPACITY);
    return data[p];
}

int biguint::compare(const biguint & n) const
{
	for (size_type i = 0; i < CAPACITY; ++i)
	{
		if (data[CAPACITY-1 - i] < n.data[CAPACITY-1-i])
			return -1;
		else if (data[CAPACITY-1 - i] > n.data[CAPACITY-1-i])
			return 1;
	}
	return 0;
}

void biguint::rshift()
{
	for (size_type i = 0; i < CAPACITY - 1; ++i)
		data[i] = data[i+1];

	data[CAPACITY-1] = 0;
}

void biguint::lshift()
{
  for (size_type i = CAPACITY-1; i >= 1; --i)
    data[i] = data[i-1];

  data[0] = 0;
}

biguint biguint::operator++() 
{
  *this += 1;
  return *this;
}

biguint biguint::operator++(int)
{
  biguint orig = *this;
  *this += 1;
  return orig;
}

biguint biguint::operator--()
{
  if (*this != biguint())
    *this -= 1;

  return *this;
}

biguint biguint::operator--(int)
{
  biguint orig(*this);

  if (*this != biguint())
    *this -= 1;
  return orig;
}


void biguint::operator +=(const biguint & n)
{
	size_type carry(0), sum;

	for (size_type i = 0; i < CAPACITY; ++i)
	{
		sum =  carry + data[i] + n.data[i];
		data[i] = sum % 10;
		carry = sum / 10;
	}
}

void biguint::operator -=(const biguint & n)
{
  if (*this <= n)
    {
      *this = biguint();
      return;
    }
  size_type carry(1), sum;
  
  for (size_type i = 0; i < CAPACITY; ++i)
    {
      sum =  carry + data[i] + 9 - n.data[i];
      data[i] = sum % 10;
      carry = sum / 10;
    }
}

void biguint::operator *=(size_type d)
{
	assert(d <= 9);

	size_type carry(0), sum;
	for (size_type i = 0; i < CAPACITY; ++i)
	{
		sum = carry + data[i] * d;
		data[i] = sum % 10;
		carry = sum / 10;
	}
}

void biguint::operator *=(const biguint & n)
{
  biguint ans;

  for (int i = CAPACITY - 1; i >= 0; --i)
    {
      biguint temp(n);
      temp *= data[i];
      ans.lshift();
      ans += temp;
    }
  std::copy(ans.data, ans.data+CAPACITY, data);
}

void biguint::operator ^=(const biguint &n)
{
  biguint ans(1);

  for (biguint i = 1; i <= n; ++i)
    ans *= *this;

  std::copy(ans.data, ans.data+CAPACITY, data);
}


void biguint::operator /= (const biguint & n)
{
  assert(n != biguint());
  biguint lo, hi(*this), mid;

  while (lo <= hi)
    {
      mid = (lo + hi);
      mid *= 5;
      mid.rshift();
      int result = (*this).compare(mid*n);
      if (result == 0)
	{
	  std::copy(mid.data, mid.data + CAPACITY, data);
	  return;

	}
      if (result == 1)
	lo = mid + 1;
      else
	hi = mid - 1;

    }
  std::copy(hi.data, hi.data+CAPACITY, data);
}

void biguint::operator %=(const biguint & n)
{
  assert(n != biguint());
  biguint temp(*this);
  temp /= n;

  *this -= temp * n;
}


std::string biguint::toStdString() const
{
    std::stringstream s;
    s << *this;
    return s.str();

/*
    bool padding = true;
    std::string ans;

    for (size_type i = 0; i < CAPACITY; ++i)
    {
        size_type p = CAPACITY - 1 - i;
        if (data[p] != 0)
        {
            padding = false;
        }

        if (!padding)
            ans += '0' + data[p];
    }

    if (padding)
        ans = "0";
    return ans;
*/
}


std::ostream & operator << (std::ostream & os, const biguint & b)
{
    bool padding = true;


    for (biguint::size_type i = 0; i < biguint::CAPACITY; ++i)
    {
        biguint::size_type p = biguint::CAPACITY - 1 - i;
        if (b[p] != 0)
        {

            padding = false;
        }
        if (!padding)
            os << b[biguint::CAPACITY - 1 - i];
    }
    if (padding)
        os << "0";
    return os;

}

bool operator <(const biguint &a, const biguint & b)
{
  return (a.compare(b) == -1);
}

bool operator <=(const biguint &a, const biguint & b)
{
  return (a.compare(b) != 1);
}

bool operator ==(const biguint &a, const biguint & b)
{
  return (a.compare(b) == 0);
}

bool operator !=(const biguint &a, const biguint & b)
{
  return (a.compare(b) != 0);
}

bool operator >=(const biguint &a, const biguint & b)
{
  return (a.compare(b) != -1);
}

bool operator >(const biguint &a, const biguint & b)
{
  return (a.compare(b) == 1);
}

 biguint operator + (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans += b;
   return ans;
 }
 biguint operator - (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans -= b;
   return ans;
 }


 biguint operator * (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans *= b;
   return ans;
 }
 biguint operator / (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans /= b;
   return ans;
 }
 biguint operator % (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans %= b;
   return ans;
 }
 biguint operator ^ (const biguint & a, const biguint & b)
 {
   biguint ans(a);
   ans ^= b;
   return ans;
 }
