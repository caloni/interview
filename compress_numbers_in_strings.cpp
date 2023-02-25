#include "interview.hpp"
#include <iostream>

using namespace std;

/** Compress the numbers in a string with digits given the following rule:

Remove every repeated digits in sequence, e.g. 11, 22, 333, 555, etc.
It must be removed even if the repeated sequence appears after a previous
compression occurred, e.g. the string "235554431" must transform to "21".

Answer: In order to do that we need to iterate for all the string until
the character before last and compare the current one and the next one. When
a repeated digit is found a inside loop must iterate until there is no more
the repeated digit and remove from the string this range of characters.

To avoid repeated digits that appeared after a compression routine the
string must be checked again, until there is no compression involved in
traverse all the string since its beginning.
*/
string CompressNumbersInString(string input)
{
    for (size_t i = 0; i < input.size() - 1; ++i)
    {
        if (input[i] == input[i + 1])
        {
            size_t end = i + 2;
            while (end < input.size() && input[end] == input[i])
            {
                ++end;
            }

            input.erase(i, end - i);
            i = -1;
            continue;
        }
    }

    return input;
}

void CompressNumbersInString()
{
    string input = "235554431";
    string output = CompressNumbersInString(input);

    cout << "input: " << input << '\n'
        << "output: " << output << endl;
}

ADD_INTERVIEW_QUESTION(CompressNumbersInString);
