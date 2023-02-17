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

shared_ptr<LinkedList> LinkedListFind(shared_ptr<LinkedList>& head, int value)
{
    int count = 0;
    shared_ptr<LinkedList> next = head->next;

    while (next)
    {
        if (next->value == value)
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

void LinkedListFind()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(1);
    shared_ptr<LinkedList> found = LinkedListFind(head, 1);
    shared_ptr<LinkedList> notFound = LinkedListFind(head, 2);
    cout << "item found is " << found << "; item not found is " << notFound << endl;
    assert(found != nullptr);
    assert(found->value == 1);
    assert(notFound == nullptr);

    head = ConstructLinkedList(100);
    found = LinkedListFind(head, 50);
    notFound = LinkedListFind(head, 101);
    cout << "item found is " << found << "; item not found is " << notFound << endl;
    assert(found != nullptr);
    assert(found->value == 50);
    assert(notFound == nullptr);

    head = ConstructLinkedList(1000);
    found = LinkedListFind(head, 999);
    notFound = LinkedListFind(head, 1001);
    cout << "item found is " << found << "; item not found is " << notFound << endl;
    assert(found != nullptr);
    assert(found->value == 999);
    assert(notFound == nullptr);

    head = ConstructLinkedList(0);
    notFound = LinkedListFind(head, 1);
    cout << "item not found is " << notFound << endl;
    assert(notFound == nullptr);
}

ADD_INTERVIEW_QUESTION(LinkedListFind);

