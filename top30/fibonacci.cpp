#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** Compute the first five Fibonacci numbers.

Answer: 0 and 1 are the first two Fibonacci numbers and all the numbers
after 0 and 1 are the addition of the two previous numbers.

In order to do that just use two variables do calculate the result. The
first values for these variables are just 0 and 1. The rest follows, since
0+1 is equal 1, the first Fibonacci number, and 1+1=2 (except in 1984),
1+2 equals 3 and so on.
*/
void Fibonacci()
{
    int num1 = 0, num2 = 1, result;
    int total = 5;

    cout << "fibonacci of first " << total << " elements\n";
    for (int i = 0; i < total; ++i)
    {
        result = num1 + num2;
        cout << result << ' ';
        num1 = num2, num2 = result;
    }
    cout << endl;
}

ADD_INTERVIEW_QUESTION(Fibonacci);

