#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to remove special characters in a string that is
in lowercase?

Answer: Special characters in a string can be removed by
using the replaceAll function in Java.

In C++ we just use the isalnum (is alphanumeric) function. In
other languages is not difficult to implement.
*/
string RemoveSpecialCharacters(string s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        if ( !isalnum(s[i]) )
        {
            s.erase(i, 1);
            --i;
        }
    }

    return s;
}

void RemoveSpecialCharacters()
{
    string s1 = "this i$ th& fir$t uniqu& ch*ct&r string";
    string s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;

    s1 = "$$$$$$$$$$$$$$$$";
    s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;

    s1 = "12.34+5.67=8.90";
    s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;

    s1 = "!Q@W#E$R%T";
    s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;

    s1 = "user@email.com";
    s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;

    s1 = "abcdefg123456";
    s2 = RemoveSpecialCharacters(s1);
    cout << "orig str: " << s1 << '\n'
        << "new str: " << s2 << endl;
}

ADD_INTERVIEW_QUESTION(RemoveSpecialCharacters);

