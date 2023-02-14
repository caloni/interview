#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool Anagram(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;
    char s1Count[256] = {};
    char s2Count[256] = {};
    for_each(s1.begin(), s1.end(), [&s1Count](char c) { s1Count[c] += 1; });
    for_each(s2.begin(), s2.end(), [&s2Count](char c) { s2Count[c] += 2; });
    return memcmp(s1Count, s2Count, sizeof(s1Count));
}

void Anagram()
{
    string s1 = "this is the first anagram string";
    string s2 = "this is the second string";
    cout << s1 << endl << s2 << endl;
    bool anagram = Anagram(s1, s2);
    cout << "the string above are " << (anagram ? "" : "not ") << "anagrams" << endl;

    s1 = "angel";
    s2 = "glean";
    cout << s1 << endl << s2 << endl;
    anagram = Anagram(s1, s2);
    cout << "the string above are " << (anagram ? "" : "not ") << "anagrams" << endl;

    s1 = "players";
    s2 = "parsley";
    cout << s1 << endl << s2 << endl;
    anagram = Anagram(s1, s2);
    cout << "the string above are " << (anagram ? "" : "not ") << "anagrams" << endl;

    s1 = "players";
    s2 = "parsleys";
    cout << s1 << endl << s2 << endl;
    anagram = Anagram(s1, s2);
    cout << "the string above are " << (anagram ? "" : "not ") << "anagrams" << endl;

    s1 = "pplayers";
    s2 = "parsley";
    cout << s1 << endl << s2 << endl;
    anagram = Anagram(s1, s2);
    cout << "the string above are " << (anagram ? "" : "not ") << "anagrams" << endl;
}

ADD_INTERVIEW_QUESTION(Anagram);

