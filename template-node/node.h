#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class node
{
public:

    typedef T value_type;

    node(const T & init_data = T(), node * init_link = NULL)
    {
        data_field = init_data;
        link_field = init_link;
    }

    T & data()
    {
        return data_field;
    }

    const T & data() const
    {
        return data_field;
    }

    node * link()
    {
        return link_field;
    }

    const node * link() const
    {
        return link_field;
    }

private:
    T data_field;
    node *link_field;
};

template <class T>
std::ostream & operator << (std::ostream & os, const node<T> & n)
{
    os << n.data() << ", " << n.link();
    return os;
}

template <class T>
std::istream & operator >> (std::istream & is, node<T> & n)
{
    T v;
    is >> v;
    n = node<T>(v, NULL);
    return is;
}

template <class T>
void list_clear(node<T>* & head_ptr)
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}

//template <class T>
//node<T> * list_search(node<T> * head_ptr, const T & target)
//{

//}

//template <class T>
//const node<T> * list_search(const node<T> * head_ptr, const T & target)
//{

//}

// To combine the 2 versions of list_search
template<class NodePtr, class T>
NodePtr list_search(NodePtr head_ptr, const T & target)
{
    NodePtr cursor;

    for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
        if (target == cursor->data())
            return cursor;

    return NULL;
}


template <class T>
class node_iterator
{
public:
    node_iterator(node<T> *initial = NULL)
    {
        current = initial;
    }

    T & operator * () const
    {
        return current->data();
    }

    node_iterator & operator ++() // prefix++
    {
        current = current->link();
        return *this;
    }

    node_iterator operator ++(int) // postfix++
    {
        node_iterator original(current);
        current = current->link();
        return original;
    }

    bool operator == (const node_iterator other) const
    {
        return (current == other.current);
    }

    bool operator != (const node_iterator other) const
    {
        return (current != other.current);
    }

private:
    node<T> * current;
};

template <class T>
class const_node_iterator
{
public:
    const_node_iterator(const node<T> *initial = NULL)
    {
        current = initial;
    }

    const T & operator * () const
    {
        return current->data();
    }

    const_node_iterator & operator ++() // prefix++
    {
        current = current->link();
        return *this;
    }

    const_node_iterator operator ++(int) // postfix++
    {
        const_node_iterator original(current);
        current = current->link();
        return original;
    }

    bool operator == (const const_node_iterator other) const
    {
        return (current == other.current);
    }

    bool operator != (const const_node_iterator other) const
    {
        return (current != other.current);
    }

private:
    const node<T> * current;
};


#endif // NODE_H
