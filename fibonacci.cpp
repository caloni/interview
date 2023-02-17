#include "interview.hpp"
#include <iostream>
#include <map>
#include <string>

using namespace std;

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

