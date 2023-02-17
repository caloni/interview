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

shared_ptr<LinkedList> LinkedListReverse(shared_ptr<LinkedList> head)
{
    shared_ptr<LinkedList> present = head->next;
    shared_ptr<LinkedList> preceding = nullptr;
    shared_ptr<LinkedList> following;

    while (present != nullptr)
    {
        following = present->next;
        present->next = preceding;
        preceding = present;
        present = following;
    }

    shared_ptr<LinkedList> rhead = make_shared<LinkedList>();
    rhead->value = 0;
    rhead->next = preceding;
    return rhead;
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

