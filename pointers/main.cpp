#include <iostream>

using namespace std;

int main()
{
/*
    int a(10);
    char c('$');
    double d(3.14159);

    char *pc(&c);
    cout << "original pc: " << (void *) pc << endl;
    pc ++;
    cout << "new pc: " << (void *) pc << endl;

    double *pd(&d);
    cout << "original pd: " << pd << endl;
    ++pd; // add size of the object you are pointing to, not adding 1
    cout << "new value of pd: " << pd << endl;

    int *pa(&a); // not an integer because of * before name. declaring new variable pa. point is an integer, not type.
                 // initialize by putting address of a.
    cout << "address of a: " << pa << endl;

    pa++; // size of the object is added to the address
    cout << "new value of pa: " << pa << endl;



    cout << "original value of a: " << a << endl;
    *pa = 20; // dereferencing variable. put 20 in variable who's address is *pa
    cout << "new value of a: " << a << endl;


    cout << "size of char: " << sizeof(char) << endl;
    cout << "size of int: " << sizeof(int) << endl;
    cout << "size of double: " << sizeof(double) << endl;
    cout << "size of long int: " << sizeof(long int) << endl;
    cout << "size of long long int: " << sizeof(long long int) << endl;
    cout << "size of long double: " << sizeof(long double) << endl;
*/




    int n;
    cout << "Enter array size: ";
    cin >> n;


    int *pa = new int[n]; // new asks for a memory block. can treat pa as name of array

    for (int i = 0; i < n; ++i)
        pa[i] = i;

    for (int i = 0; i < n; ++i)
        cout << pa[i] << endl;

    delete  [] pa; // should return the block of memory you ask for in the beginning.


}

