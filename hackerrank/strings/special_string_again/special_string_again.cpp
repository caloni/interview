// https://www.hackerrank.com/challenges/special-palindrome-again/problem
#include <stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = 0;
    for( int i = 0; i < s.size(); ++i ) {
        if( i+1 < s.size() && s[i] == s[i+1] ) { // we have duplicates
            int j = i+2;
            while( j < s.size() && s[i] == s[j] ) // count them all...
                ++j;
            int size = j - i;
            int substrings = size * (size + 1) / 2; // ... and apply natural numbers sum
            count += substrings;
            i = j -1;
        }
        else {
            ++count;
            if( i-1 >= 0 && i+1 < s.size() && s[i-1] == s[i+1] ) { // in the middle of sth
                int middleCount = 1;
                int dist = 2;
                char c = s[i-1];
                // count how many sths are around to calc the total substrings
                while( i-dist >= 0 && i+dist < s.size() 
                    && s[i-dist] == c && s[i+dist] == c ) {
                    ++middleCount;
                    ++dist;
                }
                count += middleCount;
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

