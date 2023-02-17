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

