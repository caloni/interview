// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
#include <stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.

 That was a very confused question for me because I misunderstood the
 relation between counters of characters and frequencies of counters. The
 use of maps to keep the same counters was the hard work, because the index
 is the counter, but I need the frequency of the maximum counter to
 the final if.

 The lesson here is to never underestimate the problem, because there are
 problems that just using more and more data structure is not going to
 solve it. It need to clarify the ideas first and navigate into the
 deeper issue.
 */

string isValid(string s) {
    map<char, int> char2Count; // { 'a': 1, 'b': 1, 'c': 1, 'd': 2 }
    for( char c: s ) ++char2Count[c];

    struct Count2Freq {
        int count = 0, freq = 0; // counter of characters and frequency of counter
    };
    map<int, Count2Freq> count2Freq; // counter -> { counter, frequency } => { 1: { 1, 3 }, 2: { 2, 1 } }
    for (auto& c : char2Count) {
        Count2Freq& c2f = count2Freq[c.second];
        if (!c2f.count) c2f.count = c.second;
        ++c2f.freq;
    }

    vector<int> freq; // list of frequency counters [ 1, 2 ]
    for( auto& c: count2Freq ) freq.push_back(c.first);

    if( freq.size() == 1 ) return "YES"; // valid string always

    if (freq.size() == 2) { // there are two kinds of frequencies
        for( auto& c: count2Freq ) {
            if (c.second.count == 1 && c.second.freq == 1) {
                return "YES"; // if one of the counters is alone and it is only one occurrence just remove it: valid string
            }
        }
        if (abs(freq[0] - freq[1]) == 1) { // the difference between frequencies is only 1
            // at least one of the counters has a frequency of only one letter?
            if (count2Freq[freq[0]].freq == 1 || count2Freq[freq[1]].freq == 1) {
                return "YES"; // valid string because we can remove exactly one character from one letter
            }
        }
    }

    return "NO"; // valid string never
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

