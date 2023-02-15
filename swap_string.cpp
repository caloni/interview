#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

void SwapStringsWithoutThirdVariable(string& s1, string& s2)
{
    s1 = s1 + s2;
    s2 = s1.substr(0, s1.size() - s2.size());
    s1 = s1.substr(s2.size());
}

void SwapStringsWithoutThirdVariable()
{
    string s1 = "this is the first string";
    string s2 = "this is the second string";
    cout << "s1: " << s1 << '\n' << "s2: " << s2 << endl;
    SwapStringsWithoutThirdVariable(s1, s2);
    cout << "after swap:\ns1: " << s1 << '\n' << "s2: " << s2 << endl;
}

ADD_INTERVIEW_QUESTION(SwapStringsWithoutThirdVariable);

