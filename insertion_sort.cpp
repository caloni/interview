#include "interview.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

/** Implement the insertion sort algorithm.

Answer: Implementation of insertion sort.

The insertion sort is similar to how humans order a deck of cards, so is
intuitive: divide the array in ordered and unordered. The division can
be and index that begins in the second element and goes to the end of the
array. You order first and second elements and move the third element. So
you see where the third element fits into the "ordered array", or the 
first and second elements, now divided by this index. If you keep that
way in the end of the array all elements were disposed in the ordered
position.

This logic is good to mimic the human logic, step by step. Imagine
a human picking up the third card, comparing with the second one,
comparing with the first, so exchanging the first and third ones.
*/
vector<int> InsertionSort(vector<int> array)
{
    for (size_t i = 1; i < array.size(); ++i)
    {
        size_t j = i;
        while ( j > 0 )
        {
            if (array[j-1] > array[j])
            {
                swap(array[j-1], array[j]);
            }
            --j;
        }
    }
    return array;
}

static void ConstructRandomRange(vector<int>& array, int size, int begin, int end)
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

static string Now()
{
    time_t givemetime = time(NULL);
    string now = ctime(&givemetime);
    now.pop_back();
    return now;
}

void InsertionSort()
{
    vector<int> numbers, ordered;

    numbers = { 0, 1, 2, 3, 4, 5 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 5, 4, 3, 2, 1, 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 1, 2, 3, 4, 5, 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 9, 2, 3, 4, 5, 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 0, 1 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 1, 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 1, 1 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 1, 1, 1, 1, 1 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    numbers = { 1, 1, 1, 1, 0 };
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    ConstructRandomRange(numbers, 10, 0, 100);
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    ConstructRandomRange(numbers, 10, -5000, +5000);
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    ConstructRandomRange(numbers, 10, 40, 140);
    ordered = InsertionSort(numbers);
    cout << "unordered numbers: " << numbers << '\n'
        << "ordered numbers: " << ordered << endl;

    ConstructRandomRange(numbers, 10000, -100000, +100000);
    cout << Now() << " 10k unordered random numbers from -100k to 100k; ordering...\n";
    ordered = InsertionSort(numbers);
    cout << Now() << " numbers ordered; "
        << "smallest=" << ordered[0]
        << ", biggest=" << ordered[ordered.size()-1]
        << endl;
}

ADD_INTERVIEW_QUESTION(InsertionSort);

