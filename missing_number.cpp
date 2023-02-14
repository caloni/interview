#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

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

