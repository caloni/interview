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

/** How to traverse to the middle of a linked list?

Answer: To traverse to the middle of a linked list the below steps
are followed:

- Declare two pointers first and second which are initialized to
the linked list head.
- Increment the first linked list by two nodes and second by one
node in each loop.
- While the first node reaches the end of the list, the second node
will point to the middle.

The principle of the counter of a linked list is the count of next
iterations is the same, but to keep track of a relative position as
the middle a second counter is needed.
*/
shared_ptr<LinkedList> LinkedListTraverseToTheMiddle(shared_ptr<LinkedList>& head)
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


void LinkedListTraverseToTheMiddle()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(10);
    shared_ptr<LinkedList> middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 10 elements: " << middle->value << endl;

    head = ConstructLinkedList(100);
    middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 100 elements: " << middle->value << endl;

    head = ConstructLinkedList(1);
    middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 1 element: " << middle->value << endl;

    head = ConstructLinkedList(2);
    middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 2 elements: " << middle->value << endl;

    head = ConstructLinkedList(3);
    middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 3 elements: " << middle->value << endl;

    head = ConstructLinkedList(0);
    middle = LinkedListTraverseToTheMiddle(head);
    cout << "middle in linked list with 0 elements: " << middle->value << endl;
}

ADD_INTERVIEW_QUESTION(LinkedListTraverseToTheMiddle);

