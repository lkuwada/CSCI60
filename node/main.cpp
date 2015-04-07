#include <iostream>
#include "node.h"

using namespace std;

int main()
{
    node n(5);
    node m(6);

    n.set_link(&m);
    cout << n << endl;
    cout << m << endl;

    node p (4, &n);

    for (node * i = &p; i != NULL; i = i->link())
        cout << i->data() << endl;


    cout << list_length(NULL) << endl;

    node * head_ptr = &p;
    list_head_insert(head_ptr, 10);

    list_insert(&n, 20);
    list_insert(&m, 30);

    list_print(head_ptr);

    list_head_remove(head_ptr);

    node * copy_head, *copy_tail;
    list_copy(head_ptr, copy_head, copy_tail);

    cout << "list = ";
    list_print(head_ptr);

    list_remove(&n);
    cout << "list = ";
    list_print(head_ptr);


    node *ptr = list_locate(head_ptr, 34);
    if (ptr != NULL)
        cout << *ptr << endl;

//    list_clear(head_ptr);
//    list_print(head_ptr);

    cout << "Printing copy ";
    list_print(copy_head);

    return 0;
}

