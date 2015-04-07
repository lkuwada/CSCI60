#include "bag.h"

bag::bag()
{
    head_ptr = NULL;
}

bag::bag(const bag & b)
{
    node *tail_ptr;

    list_copy(b.head_ptr, head_ptr, tail_ptr);
}

bag::~bag()
{
    list_clear(head_ptr);
}

void bag::operator = (const bag & b)
{
    if (this == &b)
        return;

    list_clear(head_ptr);

    node *tail_ptr;
    list_copy(b.head_ptr, head_ptr, tail_ptr);

}

bag::size_type bag::size() const
{
    return list_length(head_ptr);
}

bag::size_type bag::count (const value_type & target) const
{
    size_type ans(0);
    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
    {
        if (cursor->data() == target)
            ++ans;
    }
    return ans;
}

void bag::insert (const value_type &entry)
{
    list_head_insert(head_ptr, entry);
}

bool bag::erase_one (const value_type &target)
{
    node *cursor = list_search(head_ptr, target);
    if (cursor == NULL)
        return false;

    cursor->set_data(head_ptr->data());
    list_head_remove(head_ptr);
    return true;
}

bag::size_type bag::erase(const value_type &target)
{
//    for (node *cursor = head_ptr; cursor != NULL; cursor = cursor->link())
//    {
//        if (cursor->data() == target)
//        {
//            cursor->set_data(head_ptr->data());
//            list_head_remove(head_ptr);
//        }
//    }

    size_type ans(0);
    while (erase_one(target))
        ++ans;

    return ans;
}

void bag::operator +=(const bag & b)
{
    if (b.head_ptr == NULL)
        return;

    node *new_head, *new_tail;

    list_copy(b.head_ptr, new_head, new_tail);
    new_tail->set_link(head_ptr);
    head_ptr = new_head;
}

bag operator + (const bag &b1, const bag &b2)
{
    bag ans(b1);
    ans += b2;
    return ans;
}






