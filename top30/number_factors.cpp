#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** Determine the factors of a number.

Answer: The factors of a number is expressed by the following code snippet:
code bellow.

This is a simple one: just traverse all the numbers from 1 to itself and
try to get the round divisions using the module operator in the language.
Print it. You're done.
*/
void NumbersFactor()
{
    for (int number = 1; number < 30; ++number)
    {
        cout << "factors for " << number << " are: ";
        for (int i = 1; i <= number; ++i)
        {
            if (number % i == 0)
            {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
}

ADD_INTERVIEW_QUESTION(NumbersFactor);

