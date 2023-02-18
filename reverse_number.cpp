#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to reverse a number?

Answer: Reversal of a number is achieved in the following steps:

- Take out the rightmost digit of the number.
- Sum up the digit with the new reversed number.
- Perform multiplication by 10.
- Divide the number by 10.

A much more simple logic is to convert it to string and
reverse the string. I would go that way in a interview.
*/
int ReverseNumber(int number)
{
    string s = to_string(number);
    size_t beg = 0, end = s.size() - 1;
    while (beg < end)
    {
        char buf = s[beg];
        s[beg] = s[end];
        s[end] = buf;
        ++beg;
        --end;
    }
    return stoi(s);
}

void ReverseNumber()
{
    int number = 123456789;
    int reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 787878;
    reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 192837;
    reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 1;
    reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 0;
    reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 10;
    reverseNumber = ReverseNumber(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;
}

ADD_INTERVIEW_QUESTION(ReverseNumber);

