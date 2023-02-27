#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to get the matching characters in a string?

Answer: To get the matching characters in a string, the below steps
are followed:

- Hash Map data structure is taken which works with the key-value pair.
- Loop the strings, character by character, and verify if that character
of the string exists in the hash map or not.
- If the result is true, the counter for the character in the hash map is
increased or else then put a count as 1.
- Once the loop ends, then the Hash map is traversed and print the characters
with more than 1 count.

This algorithm is so much easier if your language has a hash map. If it has none
you must ask the interviewer to use or assume an existing one (otherwise the task
becomes to implement a hash map).
*/
string MatchingCharacters(string s)
{
    map<char, int> m;
    for_each(s.begin(), s.end(), [&m](char c) { m[c] += 1; });
    s.clear();
    for_each(m.begin(), m.end(), [&s](map<char, int>::const_reference e) {
        if (e.second > 1) {
            string ps = e.first == ' ' ? "<space>" : string(1, e.first);
            s += ps + "[" + to_string(e.second) + "] ";
        }
    });
    return s;
}

void MatchingCharacters()
{
    string s = "this is the first matching characters string";
    cout << s << endl;
    string ms = MatchingCharacters(s);
    cout << "matching characters: " << ms << endl;

    s = "another one";
    cout << s << endl;
    ms = MatchingCharacters(s);
    cout << "matching characters: " << ms << endl;

    s = "iiiiiiiiiiiiiiiiiiiii";
    cout << s << endl;
    ms = MatchingCharacters(s);
    cout << "matching characters: " << ms << endl;

    s = "abcdefghijklmnopqrstuvwxyz0123456789";
    cout << s << endl;
    ms = MatchingCharacters(s);
    cout << "matching characters: " << ms << endl;
}

ADD_INTERVIEW_QUESTION(MatchingCharacters);

