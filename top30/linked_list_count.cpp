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

/** How to get the length of a linked list?

Answer: To get the length of a linked list, the below steps are followed:

- Start a counter with a value of 0 and present node as head.
- Till the present node is not null , perform these :
- present = present -> next
- counter = counter + 1
- Counter value is returned.

The algorithm is straightforward, but can teach us something about the
use of the head element in linked lists. The head normally is a header, too,
in other words it has no valid value. The first valid value is in the next 
member of the head. This way we can always keep a list using its head, always
presente, even without value, and the first value for this list is the next from
the head. If the next is empty the list is empty, but we can always have a head
element.
*/
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

