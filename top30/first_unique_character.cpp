#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to compute the first character of a string that is not repeated?

Answer: To compute the first character of a string which is not repeated,
the below steps are followed:

- A Set data structure for the repeated characters and a list for the
non-repeated character is taken.
- After segregating the repeated and non-repeated, at the end of the
iteration, the first element of the list is printed in the console.

The catch of this algorithm is to remove from the unique set an element
that is being repeated and putting it in the repeated set.
*/
char FirstUniqueCharacter(string s)
{
    string repeated;
    string unique;
    for (auto c : s)
    {
        size_t pos;

        if ( (pos=repeated.find(c)) != repeated.npos)
        {
            continue;
        }
        else if ( (pos=unique.find(c)) != unique.npos)
        {
            unique.erase(pos, 1);
            repeated.push_back(c);
        }
        else
        {
            unique.push_back(c);
        }
    }
    return unique.size() ? unique[0] : 0;
}

void FirstUniqueCharacter()
{
    string s = "this is the first unique character string";
    cout << s << endl;
    char c = FirstUniqueCharacter(s);
    c != 0 ? cout << "the first unique character is '" << c << "'\n" : cout << "there is no unique character\n";

    s = "one one one two";
    cout << s << endl;
    c = FirstUniqueCharacter(s);
    c != 0 ? cout << "the first unique character is '" << c << "'\n" : cout << "there is no unique character\n";

    s = "nononono";
    cout << s << endl;
    c = FirstUniqueCharacter(s);
    c != 0 ? cout << "the first unique character is '" << c << "'\n" : cout << "there is no unique character\n";
}

ADD_INTERVIEW_QUESTION(FirstUniqueCharacter);

