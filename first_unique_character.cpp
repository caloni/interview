#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

