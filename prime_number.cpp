#include "interview.hpp"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

bool PrimeNumber(int number)
{
    if (number == 2) return true;

    for (int i = 2; i <= (number / 2); ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

void PrimeNumber()
{
    cout << "numbers from 1 to 100 (with * are prime):\n";
    for (int i = 2; i < 100; ++i)
    {
        bool prime = PrimeNumber(i);
        cout << (prime ? '*' : ' ') << i << ' ';
    }
    cout << endl;
}

ADD_INTERVIEW_QUESTION(PrimeNumber);

