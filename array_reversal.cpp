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

vector<int> ArrayReversal(vector<int> array)
{
    size_t i = 0, j = array.size() - 1;
    while (i < j)
    {
        swap(array[i], array[j]);
        ++i, --j;
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

void ArrayReversal()
{
    vector<int> numbers, ordered;

    numbers = { 0, 1, 2, 3, 4, 5 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 5, 4, 3, 2, 1, 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 1, 2, 3, 4, 5, 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 9, 2, 3, 4, 5, 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 0, 1 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 1, 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 1, 1 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 1, 1, 1, 1, 1 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    numbers = { 1, 1, 1, 1, 0 };
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    ConstructRandomRange(numbers, 10, 0, 100);
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    ConstructRandomRange(numbers, 10, -5000, +5000);
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;

    ConstructRandomRange(numbers, 10, 40, 140);
    ordered = ArrayReversal(numbers);
    cout << "original array: " << numbers << '\n'
        << "reversed array: " << ordered << endl;
}

ADD_INTERVIEW_QUESTION(ArrayReversal);

