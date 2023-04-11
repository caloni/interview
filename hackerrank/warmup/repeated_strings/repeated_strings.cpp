// https://www.hackerrank.com/challenges/repeated-string/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
To solve the [repeated string problem] we count the 'a' occurrences for the full
unique string and divide n by the size of the unique string size, getting the
number of times we need to multiply the full occurrences.

For the partial string after the number of full unique strings we format this
string and count independently this last part.

The total of occurrences is calculated multiplying the times there will be full
unique strings and sum up the partial string 'a' occurrences.

This algorithm has a complexity of O(n) because we got to count every char.
*/

long repeatedString(string s, long n) {
    long fullOccur = (long) count(s.begin(), s.end(), 'a');
    long fullMult = n / s.size();
    string partialStr = s.substr(0, n % s.size());
    long partialOccur = (long) count(partialStr.begin(), partialStr.end(), 'a');
    return fullOccur * fullMult + partialOccur;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

