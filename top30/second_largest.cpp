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

/** Determine the second largest element of an array.

Answer: The second largest element of an array can be computed by
the following steps:

- State the largest element as the first element of the array and the
second largest element as the second element of the array.
- Iterate through the loop for traversing the array.
- IF arry[i] is greater than the largest element THEN
- Second element ? largest element
- Largest element ?arry[i]
- IF second element is less than arry[i] THEN
- Second element?arry[i]

To solve second elements issues we must always have two variables. The
first one is the first element and the second one the second element. We
start with the first and seconds elements and traverse all the way, always
moving first and second accordingly.
*/
int SecondLargest(vector<int> array)
{
    if (array.empty()) return 0;
    if (array.size() == 1 ) return *array.begin();
    if (array.size() == 2) return array[0] > array[1] ? array[1] : array[0];

    int first = array[0] > array[1] ? array[0] : array[1];
    int second = array[0] > array[1] ? array[1] : array[0];

    for (size_t i = 2; i < array.size(); ++i)
    {
        if (array[i] >= first)
        {
            second = first;
            first = array[i];
        }
        else if( array[i] > second )
        {
            second = array[i];
        }
    }

    return second;
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

void SecondLargest()
{
    vector<int> numbers;
    int second;

    numbers = { 0, 1, 2, 3, 4, 5 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 5, 4, 3, 2, 1, 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 1, 2, 3, 4, 5, 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 9, 2, 3, 4, 5, 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 0, 1 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 1, 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 1, 1 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 1, 1, 1, 1, 1 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    numbers = { 1, 1, 1, 1, 0 };
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    ConstructRandomRange(numbers, 10, 0, 100);
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    ConstructRandomRange(numbers, 10, -5000, +5000);
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;

    ConstructRandomRange(numbers, 10, 40, 140);
    second = SecondLargest(numbers);
    cout << "numbers: " << numbers << '\n'
        << "second number: " << second << endl;
}

ADD_INTERVIEW_QUESTION(SecondLargest);

