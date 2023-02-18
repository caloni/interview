#include "interview.hpp"
#include <cassert>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct LinkedList
{
    int value;
    shared_ptr<LinkedList> next;
};

/** How to get the third node of a linked list?

Answer: To get to the third node of the linked list the below steps
are followed:

- Start a counter with a value 0.
- Iterate through the linked list and perform these steps:
- If the value of the counter is 3, then the present node is returned.
- Counter is increased by 1.
- Modify the present such that it implies to the next of the present.

The counter for linked lists is the number of next iterations.
*/
shared_ptr<LinkedList> LinkedListGet(shared_ptr<LinkedList>& head, int position)
{
    int curr = 0;
    shared_ptr<LinkedList> next = head->next;

    while (next)
    {
        ++curr;
        if (curr == position)
        {
            return next;
        }
        next = next->next;
    }

    return nullptr;
}

static shared_ptr<LinkedList> ConstructLinkedList(int elements)
{
    shared_ptr<LinkedList> head = make_shared<LinkedList>();
    head->value = 0;

    auto next = head;
    for (int i = 1; i <= elements; ++i)
    {
        next = next->next = make_shared<LinkedList>();
        next->value = i;
    }

    return head;
}

static ostream& operator << (ostream& os, shared_ptr<LinkedList> item)
{
    return os << (item ? "[" + to_string(item->value) + "]" : "[empty]");
}

void LinkedListGet()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(10);
    shared_ptr<LinkedList> node = LinkedListGet(head, 3);
    cout << "in a 10 items list, item #3: " << node << endl;
    assert(node != nullptr);
    assert(node->value == 3);

    head = ConstructLinkedList(2);
    node = LinkedListGet(head, 3);
    cout << "in a 2 items list, item #3: " << node << endl;
    assert(node == nullptr);

    head = ConstructLinkedList(0);
    node = LinkedListGet(head, 3);
    cout << "in a 0 items list, item #3: " << node << endl;
    assert(node == nullptr);
}

ADD_INTERVIEW_QUESTION(LinkedListGet);

