#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct LinkedList
{
    int value;
    shared_ptr<LinkedList> next;
};

/** Implement the process of reversing a linked list.

Answer: A linked list can be reversed by the below steps:

- Declare three nodes preceding, present, and following.
- While in the present node, the preceding will be null.
- Let the present.next be preceding to reverse the list.
- In each looping, present and preceding are incremented by 1.

This is a tricky one. The catch in the logic bellow is to
traverse the list keeping a track of the following and the
previous elements. Having present, preceding and following
elements the swap of positions become straighforward, but not
simple to imagine because:

- the following become the present next
- the present next become the preceding (reversing)
- the preceding become the present (this is past)
- the present becomes the following
- continue until the old end of list becomes the new head, pointing
to the last preceding

```
beginning
  next ->  next ->  next ->  next ->  null
 *pres ->  next ->  next ->  next ->  null // present = head->next

 first iteration
  pres -> *foll ->  next ->  next ->  null                   // 1
  pres -> *null     foll ->  next ->  next ->  null          // 2
 *prec ->  null     foll ->  next ->  next ->  null          // 3
  prec ->  null    *pres ->  next ->  next ->  null          // 4

 second iteration
  prec ->  null     pres -> *foll ->  next ->  null          // 1
  prec ->  null     pres -> *prec     foll ->  next -> null  // 2
 *pres ->  prec ->  null     foll ->  next ->  null          // 3
  prec ->  next ->  null    *pres ->  next ->  null          // 4

 third iteration
  prec ->  next ->  null     pres -> *foll ->  null          // 1
  prec ->  next ->  null     pres -> *prec     foll -> null  // 2
 *pres ->  prec ->  next ->  null     foll ->  null          // 3
  prec ->  next ->  next ->  null    *pres ->  null          // 4

end
 *head ->  prec ->  next ->  next ->  null  // head->next = preceding;
```
*/
shared_ptr<LinkedList> LinkedListReverse(shared_ptr<LinkedList> head)
{
    shared_ptr<LinkedList> present = head->next;
    shared_ptr<LinkedList> preceding = nullptr;
    shared_ptr<LinkedList> following;

    while (present != nullptr)
    {
        following = present->next; // 1
        present->next = preceding; // 2
        preceding = present;       // 3
        present = following;       // 4
    }

    shared_ptr<LinkedList> rhead = make_shared<LinkedList>();
    rhead->value = 0;
    rhead->next = preceding;
    return rhead;
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

ostream& operator << (ostream& os, shared_ptr<LinkedList> item)
{
    vector<int> elements;

    while (item->next)
    {
        item = item->next;
        elements.push_back(item->value);
    }

    bool enterMiddle = false;

    for (size_t i = 0; i < elements.size(); ++i)
    {
        if (i < 5 || i > elements.size() - 6)
        {
            os << elements[i] << ' ';
        }
        else if (enterMiddle == false)
        {
            os << "... ";
            enterMiddle = true;
        }
    }

    return os;
}

void LinkedListReverse()
{
    shared_ptr<LinkedList> head = ConstructLinkedList(3);
    cout << "orig linked list: " << head << endl;
    shared_ptr<LinkedList> rhead = LinkedListReverse(head);
    cout << "reversed linked list: " << rhead << endl;

    head = ConstructLinkedList(10);
    cout << "orig linked list: " << head << endl;
    rhead = LinkedListReverse(head);
    cout << "reversed linked list: " << rhead << endl;

    head = ConstructLinkedList(1000);
    cout << "orig linked list: " << head << endl;
    rhead = LinkedListReverse(head);
    cout << "reversed linked list: " << rhead << endl;

    head = ConstructLinkedList(1);
    cout << "orig linked list: " << head << endl;
    rhead = LinkedListReverse(head);
    cout << "reversed linked list: " << rhead << endl;

    head = ConstructLinkedList(0);
    cout << "orig linked list: " << head << endl;
    rhead = LinkedListReverse(head);
    cout << "reversed linked list: " << rhead << endl;
}

ADD_INTERVIEW_QUESTION(LinkedListReverse);

