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

shared_ptr<LinkedList> ConstructLinkedList(int elements)
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

shared_ptr<LinkedList> TraverseToTheMidle(shared_ptr<LinkedList>& head)
{
    shared_ptr<LinkedList> next = head;
    shared_ptr<LinkedList> nextDouble = head;
    bool secondNext = true;

    while (nextDouble->next)
    {
        if (secondNext)
        {
            next = next->next;
        }
        nextDouble = nextDouble->next;
        secondNext = !secondNext;
    }

    return next;
}

void TraverseToTheMidle()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(10);
    shared_ptr<LinkedList> middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 10 elements: " << middle->value << endl;

    head = ConstructLinkedList(100);
    middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 100 elements: " << middle->value << endl;

    head = ConstructLinkedList(1);
    middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 1 element: " << middle->value << endl;

    head = ConstructLinkedList(2);
    middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 2 elements: " << middle->value << endl;

    head = ConstructLinkedList(3);
    middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 3 elements: " << middle->value << endl;

    head = ConstructLinkedList(0);
    middle = TraverseToTheMidle(head);
    cout << "middle in linked list with 0 elements: " << middle->value << endl;
}

ADD_INTERVIEW_QUESTION(TraverseToTheMidle);

