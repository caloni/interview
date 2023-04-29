// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
#include <stdc++.h>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int makeAnagram(string a, string b) {
    int removes = 0;
    map<char, int> counta, countb;
    for( char c: a ) ++counta[c];
    for( char c: b ) ++countb[c];
    for( auto& ita: counta ) {
        removes += abs(ita.second - countb[ita.first]);
        ita.second = countb[ita.first] = 0;
    }
    for( auto& itb: countb ) {
        removes += abs(itb.second - counta[itb.first]);
        itb.second = counta[itb.first] = 0;
    }
    return removes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}

