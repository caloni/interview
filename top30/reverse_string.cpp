#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How can you reverse a string?

Answer: String is reversed with the following algorithm:

 - The string which is to be reversed is declared.
 - Get the length of the string.
 - Start a loop and then swap the position of the array elements.
 - Keep the exchanged positions.
 - Print the reversed string.

What is a palindrome string?

Answer: After the string is reversed as discussed in Q #1, we need to put
the following condition: the palindrome string is the one which on reversing
remains the same, for example, – 'madam' is a palindrome string.

The key here is just to swap the beginning and ends until the begin index is
bigger (or equal) than the end index, in other words, both have passed the 
middle of the string.
*/
string ReverseString(string s)
{
    size_t beg = 0, end = s.size() - 1;
    while (beg < end)
    {
        char buf = s[beg];
        s[beg] = s[end];
        s[end] = buf;
        ++beg;
        --end;
    }
    return s;
}

void ReverseString()
{
    string s = "this is the normal string to be reversed";
    cout << s << endl;
    cout << "reversing\n";
    string rs = ReverseString(s);
    cout << rs << endl;
    cout << "this is string is " << (s == rs ? "" : "not ") << "a palindrome\n";

    s = "stellawonnowallets";
    cout << s << endl;
    cout << "reversing\n";
    rs = ReverseString(s);
    cout << rs << endl;
    cout << "this is string is " << (s == rs ? "" : "not ") << "a palindrome\n";
}

ADD_INTERVIEW_QUESTION(ReverseString);

