#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

