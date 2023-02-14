#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int CountString(string s, char c)
{
    // count(s.begin(), s.end(), c); // easy one
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (s[i] == c)
        {
            count += 1;
        }
    }
    return count;
}

void CountString()
{
    string s = "this is a string to count 'i' occurrences";
    cout << s << endl;
    int count = CountString(s, 'i');
    cout << "there are " << count << " ocurrences of 'i' character\n";

    s = "nothing can be done";
    cout << s << endl;
    count = CountString(s, 'i');
    cout << "there are " << count << " ocurrences of 'i' character\n";

    s = "what do you know?";
    cout << s << endl;
    count = CountString(s, 'i');
    cout << "there are " << count << " ocurrences of 'i' character\n";

    s = "this is a italian idiotic microwave";
    cout << s << endl;
    count = CountString(s, 'i');
    cout << "there are " << count << " ocurrences of 'i' character\n";
}

ADD_INTERVIEW_QUESTION(CountString);

