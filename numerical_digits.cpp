#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to calculate the number of numerical digits in a string?

Answer: To calculate the number of digits in a string, the below
steps are followed:

- Get the string on which count has to be performed
- Use the replaceAll function, which replaces all the numerical
digits with "".
- Get the length of the string without digits.

There is a simpler strategy than the answer above that is to
simply count when the character is a digit. In C/C++ there is
this isdigit function, but it is not hard do implement.
*/
int NumericalDigits(string s)
{
    // return count_if(s.begin(), s.end(), isdigit); // easy one
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (isdigit(s[i]))
        {
            count += 1;
        }
    }
    return count;
}

void NumericalDigits()
{
    string s = "this is 1 string to count numerical digital occurrences";
    cout << s << endl;
    int count = NumericalDigits(s);
    cout << "there are " << count << " ocurrences of numerical digits\n";

    s = "1234567890";
    cout << s << endl;
    count = NumericalDigits(s);
    cout << "there are " << count << " ocurrences of numerical digits\n";

    s = "aeiou";
    cout << s << endl;
    count = NumericalDigits(s);
    cout << "there are " << count << " ocurrences of numerical digits\n";

    s = "1q2w3e4r";
    cout << s << endl;
    count = NumericalDigits(s);
    cout << "there are " << count << " ocurrences of numerical digits\n";
}

ADD_INTERVIEW_QUESTION(NumericalDigits);

