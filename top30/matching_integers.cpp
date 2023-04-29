#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

/** How to get the matching elements in an integer array?

Answer: To get the matching elements in an integer array, the below
steps are followed:

- Build two loops.
- In the first loop, collect elements one at a time and add up the number
of instances of the selected element.

This algorithm is an ineficient one, because it has to traverse twice
the same array. This is the price of an unordered array, though.
*/
int MatchingIntegers(const vector<int>& array, set<int>& matching)
{
    matching.clear();
    for (size_t i = 0; i < array.size(); ++i)
    {
        for (size_t j = i+1; j < array.size(); ++j)
        {
            if (array[i] == array[j])
            {
                matching.insert(array[i]);
            }
        }
    }
    return (int) matching.size();
}

ostream& operator << (ostream& os, const vector<int>& array)
{
    for_each(array.begin(), array.end(), [&os](int n) { os << n << ' '; });
    return os;
}

ostream& operator << (ostream& os, const set<int>& array)
{
    for_each(array.begin(), array.end(), [&os](int n) { os << n << ' '; });
    return os;
}

void MatchingIntegers()
{
    vector<int> array = { 0, 1, 2, 3, 4, 5 };
    set<int> matching;
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;

    array = { 0, 0, 0, 0, 0 };
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;

    array = { 0, 1, 0, 1, 0 };
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;

    array = { 0, 2, 2, 2, 0 };
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;

    array = { 0 };
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;

    array = { 23, 53, 13, 16, 1, 53, 14, 1 };
    cout << "array: " << array << endl;
    MatchingIntegers(array, matching);
    cout << "matching elements: " << matching << endl;
}

ADD_INTERVIEW_QUESTION(MatchingIntegers);

