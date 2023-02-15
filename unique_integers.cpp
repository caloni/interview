#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void UniqueIntegers(const vector<T>& array, vector<T>& unique)
{
    set<T> uniqueSet;
    unique.clear();
    for_each(array.begin(), array.end(), [&unique, &uniqueSet](T item)
    {
        if (uniqueSet.find(item) == uniqueSet.end())
        {
            uniqueSet.insert(item);
            unique.push_back(item);
        }
    });
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& array)
{
    for_each(array.begin(), array.end(), [&os](int n) { os << n << ' '; });
    return os;
}

void UniqueIntegers()
{
    vector<int> array = { 0, 1, 2, 3, 4, 5 };
    vector<int> unique;
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;

    array = { 0, 0, 0, 0, 0 };
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;

    array = { 0, 1, 0, 1, 0 };
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;

    array = { 0, 2, 2, 2, 0 };
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;

    array = { 0 };
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;

    array = { 23, 53, 13, 16, 1, 53, 14, 1 };
    cout << "array: " << array << endl;
    UniqueIntegers(array, unique);
    cout << "unique elements: " << unique << endl;
}

ADD_INTERVIEW_QUESTION(UniqueIntegers);

