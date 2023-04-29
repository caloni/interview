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
int ReverseNumberStringVersion(int number)
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

int ReverseNumberNumberVersion(int number)
{
    int reversedNumber = 0;

    while (number) {
        reversedNumber *= 10;
        int next = number % 10;
        reversedNumber += next;
        number /= 10;
    }

    return reversedNumber;
}


void ReverseNumber()
{
    int number = 123456789;
    int reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 787878;
    reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 192837;
    reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 1;
    reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 0;
    reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;

    number = 10;
    reverseNumber = ReverseNumberNumberVersion(number);
    cout << "the reversed version of " << number << " is " << reverseNumber << endl;
}

ADD_INTERVIEW_QUESTION(ReverseNumber);

