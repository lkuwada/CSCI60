#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

/*int max(int a, int b, int c)
{
    //return max(a, max(b, c));

    if(a >= b && a >=c)
        return a;
    if(b >= a && b >= c)
        return b;
    return c;
}

string max(string a, string b, string c)
{
    if(a >= b && a >=c)
        return a;
    if(b >= a && b >= c)
        return b;
    return c;
}*/

//replaces the two functions above... don't have to specify the underlying type
template<class Item>
/*Item max(Item a, Item b, Item c)
{
    if(a >= b && a >=c)
        return a;
    if(b >= a && b >= c)
        return b;
    return c;
}*/

//template<class Item, class SizeType>
Item max(Item A[], size_t n)
{
    assert(n >= 1);
    Item ans = A[0];
    for(int i = 1; i < n; ++i)
        if(A[i] > ans)
            ans = A[i];
    return ans;
}



int main()
{
    /*int a(5), b(-6), c(3);
    string x("hello"), y("world"), z("z");
    cout << max(a, b, c) << endl;
    cout << max(x, y, z) << endl;*/

    int A[] = {1, 3, 2};
    string B[] = {"hello", "world"};

    int size = 3;
    cout << max(A, size) << endl;
    double n = 2.0;
    cout << max(B, n) << endl;

    return 0;
}

