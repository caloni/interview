#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

