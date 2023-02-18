#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to perform swapping two strings by not using a third variable?

Answer: Two strings are swapped without the help of the third variable
by the following steps:

- (i) Take two strings i, j, and append them then store in the first string.
- (ii) Using the substring method extract the string:
`j = substring(0,i.length()-j.length())`
- (iii) Store the string j in string i
`i= subsrtirng(j.length)`

This is a tricky question with some good insights, like to take leverage of
existing variables, and how strings are characters buffers that can be streched
by our own desire. Try to put that in mind.
*/
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

