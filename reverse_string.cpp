#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

string ReverseString(string s)
{
    size_t beg = 0, end = s.size() - 1;
    while (beg < end)
    {
        char buf = s[beg];
        s[beg] = s[end];
        s[end] = buf;
        ++beg;
        --end;
    }
    return s;
}

void ReverseString()
{
    string s = "this is the normal string to be reversed";
    cout << s << endl;
    cout << "reversing\n";
    string rs = ReverseString(s);
    cout << rs << endl;
    cout << "this is string is " << (s == rs ? "" : "not ") << "a palindrome\n";

    s = "stellawonnowallets";
    cout << s << endl;
    cout << "reversing\n";
    rs = ReverseString(s);
    cout << rs << endl;
    cout << "this is string is " << (s == rs ? "" : "not ") << "a palindrome\n";
}

ADD_INTERVIEW_QUESTION(ReverseString);

