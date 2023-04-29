#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** Find the count for the occurrence of a particular character in a string.

Answer: To count the occurrence of a particular character in a string,
the below steps are followed:

- Start with a string and a particular character whose occurrence shall
be counted.
- Start a loop from 0 to the length of the string.
- Compare if a particular character of the string equals to the
character that is
being searched.
- If the result is true, then increment the value of the counter.

This is a dummy algorithm that can be used for more complex ones. By example,
if there are more than one character to search, or some kind of pattern with
multiple possibilities, regex like, to search.

Is in the simplest algorithms that reside the key for the more complex ones.
*/
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

