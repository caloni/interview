#include "interview.hpp"
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

int LinkedListCount(shared_ptr<LinkedList>& head)
{
    int count = 0;
    shared_ptr<LinkedList> next = head->next;

    while (next)
    {
        ++count;
        next = next->next;
    }

    return count;
}

void LinkedListCount()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(1);
    int count = LinkedListCount(head);
    cout << "list with 1 element has [" << count << "] element" << endl;

    head = ConstructLinkedList(10);
    count = LinkedListCount(head);
    cout << "list with 10 elements has [" << count << "] elements" << endl;

    head = ConstructLinkedList(100);
    count = LinkedListCount(head);
    cout << "list with 100 elements has [" << count << "] elements" << endl;

    head = ConstructLinkedList(1000);
    count = LinkedListCount(head);
    cout << "list with 1000 elements has [" << count << "] elements" << endl;

    head = ConstructLinkedList(0);
    count = LinkedListCount(head);
    cout << "list with 0 elements has [" << count << "] elements" << endl;
}

ADD_INTERVIEW_QUESTION(LinkedListCount);

