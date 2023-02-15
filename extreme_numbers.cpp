#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

void ExtremeNumbers(const vector<int>& array, int& biggest, int& smallest)
{
    biggest = INT_MIN;
    smallest = INT_MAX;

    for_each(array.begin(), array.end(), [&biggest, &smallest](int number)
    {
        if (number > biggest)
        {
            biggest = number;
        }

        if (number < smallest)
        {
            smallest = number;
        }
    });
}

void ConstructRandomRange(vector<int>& array, int size, int begin, int end)
{
    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(begin, end);

    array.clear();
    for (int i = 0; i < size; ++i)
    {
        auto const randomNumber = distribution(random_engine);
        array.push_back(randomNumber);
    }
}

template<typename T>
ostream& operator << (ostream& os, const vector<T>& array)
{
    for_each(array.begin(), array.end(), [&os](int n) { os << n << ' '; });
    return os;
}

void ExtremeNumbers()
{
    vector<int> numbers;
    int biggest, smallest;
    ConstructRandomRange(numbers, 10, 0, 100);
    ExtremeNumbers(numbers, biggest, smallest);
    cout << "numbers between 0 and 100: " << numbers << '\n'
        << "biggest=" << biggest << " smallest=" << smallest << endl;

    ConstructRandomRange(numbers, 5, -5000, +5000);
    ExtremeNumbers(numbers, biggest, smallest);
    cout << "numbers between -5000 and +5000: " << numbers << '\n'
        << "biggest=" << biggest << " smallest=" << smallest << endl;

    ConstructRandomRange(numbers, 1, 40, 140);
    ExtremeNumbers(numbers, biggest, smallest);
    cout << "numbers between 40 and 140: " << numbers << '\n'
        << "biggest=" << biggest << " smallest=" << smallest << endl;

    ConstructRandomRange(numbers, 30, 1, 5);
    ExtremeNumbers(numbers, biggest, smallest);
    cout << "numbers between 1 and 5: " << numbers << '\n'
        << "biggest=" << biggest << " smallest=" << smallest << endl;
}

ADD_INTERVIEW_QUESTION(ExtremeNumbers);

