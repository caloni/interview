#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to verify if two strings are a rotation mutually?

Answer: To verify if two strings are a rotation mutually, the below
steps are followed:

- Initialize the two strings in two variables.
- Check if the length of two strings is similar, if not return false.
- Join the string to itself.
- Verify if the string which is rotated is present in the joined string.
- If the result is true, the second string is a rotation of the first string.

That is an awesome algorithm to detect this: we simply duplicate the string
and try to find the second string inside this one. Every rotation possibility
will be there in some point.
*/
bool RotationMutually(string s1, string s2)
{
    if (s1.size() != s2.size()) return false;
    s1 += s1;
    return s1.find(s2) != s1.npos;
}

void RotationMutually()
{
    string s1 = "this_is_a_rotation_mutually_string_to_be_checked_";
    string s2 = "to_be_checked_this_is_a_rotation_mutually_string_";
    cout << s1 << endl << s2 << endl;
    bool rotm = RotationMutually(s1, s2);
    cout << "the strings above are " << (rotm ? "" : "not ") << "rotation mutually\n";

    s1 = "HELLO";
    s2 = "LOHEL";
    cout << s1 << endl << s2 << endl;
    rotm = RotationMutually(s1, s2);
    cout << "the strings above are " << (rotm ? "" : "not ") << "rotation mutually\n";

    s1 = "ABCD";
    s2 = "CDAB";
    cout << s1 << endl << s2 << endl;
    rotm = RotationMutually(s1, s2);
    cout << "the strings above are " << (rotm ? "" : "not ") << "rotation mutually\n";

    s1 = "ABCD";
    s2 = "ACBD";
    cout << s1 << endl << s2 << endl;
    rotm = RotationMutually(s1, s2);
    cout << "the strings above are " << (rotm ? "" : "not ") << "rotation mutually\n";
}

ADD_INTERVIEW_QUESTION(RotationMutually);

