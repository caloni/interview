#include "interview.hpp"
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

/** How to calculate the number of vowels and consonants in a string?

Answer: To calculate the number of vowels and consonants in a string,
the below steps are followed:

- Get the string on which count has to be performed.
- Run a loop from 0 to the length of the string.
- Take a single character at a time and verify if they are a part of the
group of vowels.
- If the result is true, increase the count of vowels or else increment
the count of consonants.

This is the kind of problem to detect in which group each element is found
to count the results. If the group does not exist in the language you
have to implement it, either typing all the elements or constructing using
a loop or something like that.
*/
void VowelsAndConsonants(string s, int& vowels, int& consonants, int& others)
{
    static const string st_Vowels = "aeiou";
    static const string st_Consonants = "bcdfghjklmnpqrstvwxyz";

    vowels = consonants = others = 0;
    for_each(s.begin(), s.end(), [&](char c) {
        if (st_Vowels.find(c) != st_Vowels.npos )
        {
            vowels++;
        }
        else if (st_Consonants.find(c) != st_Consonants.npos )
        {
            consonants++;
        }
        else
        {
            others++;
        }
    });
}

void VowelsAndConsonants()
{
    int vowels, consonants, others;

    string s = "this is the first counting vowels and consonants string";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "aeiou";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "bcdfghjklmnpqrstvwxyz";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "at";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "atatatat";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "792 + 34 / 534 = 0";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;

    s = "792.0 + 34e / 534 = 0";
    cout << s << endl;
    VowelsAndConsonants(s, vowels, consonants, others);
    cout << "there are " << vowels << " vowels, " << consonants << " consonants and " << others << " others" << endl;
}

ADD_INTERVIEW_QUESTION(VowelsAndConsonants);

