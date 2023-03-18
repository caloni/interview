// https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
#include <stdc++.h>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string reverseShuffleMerge(string s) {
    map<char, int> charCounter;
    for( char c: s ) ++charCounter[c];
    string s1;
    for (auto& c : charCounter) {
        s1.append(c.second / 2, c.first);
    }
    sort(s1.begin(), s1.end());
    reverse(s.begin(), s.end());

    do {
        cout << s1;
        size_t lastChar = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            lastChar = s.find(s1[i], lastChar);
            if (lastChar == s.npos) break;
            ++lastChar;
        }
        if (lastChar != s.npos) {
            break;
        }
    } while (next_permutation(s1.begin(), s1.end()) );

    return s1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

