#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/** How to search a missing number in an array that contains integers
from 1 to 100?

Answer: To search a missing number in an array which contains integers
from 1 to 100, the below steps are followed:

- Take an integer array with the numbers from 1 to 100.
- Compute the sum of the numbers, the summation shall be= l*(l+1)/2,
where l is the number of integers.
- Perform subtraction of the missing element from the total addition of
numbers.

This is a mathematical one, or is simples to resolve using basic
mathematics. And the math says that the sum of a range of numbers
equals the number of integers versus this number plus one divided
by two. It has relation with the simple average (in this case 50).

The trick to implement it is to subtract every number from this total,
so the remaining one will be the missing number from the range.

Note that if the range doesn't start with 1 there must be a trick to
capture the average for ranges that don't start with 1. The logic must
be that there must be a average to detect the missing number.
*/
int FindMissingNumber(const vector<int>& array)
{
    int integers = (int) array.size() + 1;
    int missingNumber = integers * (integers + 1) / 2;

    for (const auto& a : array)
    {
        missingNumber -= a;
    }

    return missingNumber;
}

void ConstructArrayAndRemoveNumber(vector<int>& array, int end, int remove)
{
    array.clear();
    for (int i = 1; i <= end; ++i)
    {
        if (i != remove)
        {
            array.push_back(i);
        }
    }
}

void FindMissingNumber()
{
    vector<int> numbers;
    int missing = 49;
    ConstructArrayAndRemoveNumber(numbers, 100, missing);
    cout << numbers.size() + 1 << " numbers and missing number will be " << missing << endl;
    int foundMissing = FindMissingNumber(numbers);
    cout << "the missing number found is " << foundMissing << endl;

    missing = 1;
    ConstructArrayAndRemoveNumber(numbers, 100, missing);
    cout << numbers.size() + 1 << " numbers and missing number will be " << missing << endl;
    foundMissing = FindMissingNumber(numbers);
    cout << "the missing number found is " << foundMissing << endl;

    missing = 100;
    ConstructArrayAndRemoveNumber(numbers, 100, missing);
    cout << numbers.size() + 1 << " numbers and missing number will be " << missing << endl;
    foundMissing = FindMissingNumber(numbers);
    cout << "the missing number found is " << foundMissing << endl;

    missing = 568;
    ConstructArrayAndRemoveNumber(numbers, 976, missing);
    cout << numbers.size() + 1 << " numbers and missing number will be " << missing << endl;
    foundMissing = FindMissingNumber(numbers);
    cout << "the missing number found is " << foundMissing << endl;
}

ADD_INTERVIEW_QUESTION(FindMissingNumber);

