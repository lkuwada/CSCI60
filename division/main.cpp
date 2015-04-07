#include <iostream>

using namespace std;

int main()
{
    unsigned int a, b;

    cout << "Enter a, b: ";
    cin >> a >> b;

    //want to compute a/b
    unsigned int lo = 0, hi = a, mid, product;


    while (lo <= hi)
    {
        mid = (lo + hi) / 2; // multiply by 5 and then divide by 10 by rshift()
        product = mid * b;
        if (product == a)
        {
            break;
        }
        if (product > a)
            hi = mid -1;
        else
            lo = mid + 1;
    }
    cout << mid << endl;
}

