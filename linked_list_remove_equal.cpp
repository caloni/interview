#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct LinkedList
{
    int value;
    shared_ptr<LinkedList> next;
};

static shared_ptr<LinkedList> ConstructRandomLinkedList(int size, int begin, int end)
{
    shared_ptr<LinkedList> head = make_shared<LinkedList>();
    head->value = 0;

    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(begin, end);

    auto next = head;
    for (int i = 0; i < size; ++i)
    {
        auto const randomNumber = distribution(random_engine);
        next = next->next = make_shared<LinkedList>();
        next->value = randomNumber;
    }

    return head;
}

shared_ptr<LinkedList> LinkedListRemoveEqual(shared_ptr<LinkedList> head)
{
    shared_ptr<LinkedList> head2 = make_shared<LinkedList>();
    head2->value = 0;
    set<int> values;
    shared_ptr<LinkedList> next = head->next;
    shared_ptr<LinkedList> next2 = head2;

    while (next)
    {
        if (values.find(next->value) == values.end())
        {
            values.insert(next->value);
            next2->next = next;
            next2 = next2->next;
        }
        next = next->next;
    }
    next2->next = nullptr;

    return head2;
}

static ostream& operator << (ostream& os, shared_ptr<LinkedList> item)
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

void LinkedListRemoveEqual()
{
    shared_ptr<LinkedList> head = ConstructRandomLinkedList(4, 1, 3);
    cout << "orig linked list: " << head << endl;
    shared_ptr<LinkedList> uniqueHead = LinkedListRemoveEqual(head);
    cout << "unique linked list: " << uniqueHead << endl;

    head = ConstructRandomLinkedList(10, 1, 5);
    cout << "orig linked list: " << head << endl;
    uniqueHead = LinkedListRemoveEqual(head);
    cout << "unique linked list: " << uniqueHead << endl;

    head = ConstructRandomLinkedList(100, 1, 10);
    cout << "orig linked list: " << head << endl;
    uniqueHead = LinkedListRemoveEqual(head);
    cout << "unique linked list: " << uniqueHead << endl;

    head = ConstructRandomLinkedList(1, 1, 10);
    cout << "orig linked list: " << head << endl;
    uniqueHead = LinkedListRemoveEqual(head);
    cout << "unique linked list: " << uniqueHead << endl;

    head = ConstructRandomLinkedList(0, 1, 10);
    cout << "orig linked list: " << head << endl;
    uniqueHead = LinkedListRemoveEqual(head);
    cout << "unique linked list: " << uniqueHead << endl;
}

ADD_INTERVIEW_QUESTION(LinkedListRemoveEqual);

