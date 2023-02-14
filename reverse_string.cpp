#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void ReverseString()
{
    string s = "this is the normal string to be reversed";
    cout << s << endl;
    cout << "reversing\n";
    size_t beg = 0, end = s.size() - 1;
    while (beg < end)
    {
        char buf = s[beg];
        s[beg] = s[end];
        s[end] = buf;
        ++beg;
        --end;
    }
    cout << s << endl;
}

ADD_INTERVIEW_QUESTION(ReverseString);

