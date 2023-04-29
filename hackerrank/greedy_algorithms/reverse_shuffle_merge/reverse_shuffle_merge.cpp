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
    map<char, int> notUsed, used, required;
    for (char c : s) ++notUsed[c];
    for (auto& nu : notUsed) required[nu.first] = nu.second / 2;
    string a;
    for (int i = s.size() - 1; i >= 0; --i) {
        char c = s[i];
        --notUsed[c];
        if (a.empty()) {
            a.push_back(c);
            ++used[c];
        }
        else if (required[c] != used[c]) {
            char lc = a[a.size() - 1];
            if (lc <= c) {
                a.push_back(c);
                ++used[c];
            }
            else if (notUsed[lc] && notUsed[lc] > required[lc] - used[lc]) {
                a.pop_back();
                --used[lc];
                lc = a.size() ? a[a.size() - 1] : 0;
                while (lc > c && notUsed[lc] && notUsed[lc] > required[lc] - used[lc]) {
                    a.pop_back();
                    --used[lc];
                    lc = a.size() ? a[a.size() - 1] : 0;
                }
                a.push_back(c);
                ++used[c];
            }
            else {
                a.push_back(c);
                ++used[c];
            }
        }
    }
    return a;
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

