#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

