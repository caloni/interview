#include "interview.hpp"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/** How to verify if a number is prime or not?

Answer: To verify if a number is prime or not, the below
steps are followed:

- Start a loop from value 2(k) up to (number / 2)
- If the number is perfectly divisible by k, then the number
is non – prime.
- If the number is not perfectly divisible except for 1 and by
itself, then the number is prime.

The same logic to get the factors of a number with a different
result: if there is no round division between 2 and the number
that number is a prime.
*/
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

