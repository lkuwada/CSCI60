#include <iostream>
#include "node.h"
#include <string>

using namespace std;

int main()
{
//    node<int> n(5, NULL);
//    cout << n << endl;

//    node<char> c('a', NULL);
//    cout << c << endl;

//    node<double> d;
//    cout << "Enter a double: ";
//    cin >> d;
//    cout << d << endl;


    node<string> *head = NULL;

    head = new node<string>("one", head);
    head = new node<string>("two", head);
    head = new node<string>("three", head);

    for (node_iterator<string> i(head); i != NULL; ++i)
        cout << *i << endl;


    return 0;
}

