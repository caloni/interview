// https://www.hackerrank.com/challenges/common-child/problem
#include <stdc++.h>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    string child;
    size_t i1 = 0, i2 = 0;
    while (i1 < s1.size() && i2 < s2.size()) {
        if (s1[i1] == s2[i2]) { // nothing to change
            child.push_back(s1[i1]);
            ++i1, ++i2;
        }
        else { // something has to change
            size_t i2InI1 = s1.find(s2[i2], i1+1);
            size_t i1InI2 = s2.find(s1[i1], i2+1);

            if (i1InI2 != s2.npos && i2InI1 == s1.npos ) { // found one of two, then choose it
                child.push_back(s1[i1]);
                ++i1;
                i2 = i1InI2 + 1;
            }
            else if ( i2InI1 != s1.npos && i1InI2 == s2.npos) { // found one of two, then choose it
                child.push_back(s2[i2]);
                ++i2;
                i1 = i2InI1 + 1;
            }
            else if (i1InI2 != s2.npos && i2InI1 != s1.npos) { // both are possible, then take the nearest one
                size_t dist1In2 = i1InI2 - i1; // how many chars we going to eat
                size_t dist2In1 = i2InI1 - i2; // how many chars we going to eat
                if (dist1In2 < dist2In1) {
                    child.push_back(s1[i1]);
                    ++i1;
                    i2 = i1InI2 + 1;
                }
                else {
                    child.push_back(s2[i2]);
                    ++i2;
                    i1 = i2InI1 + 1;
                }
            }
            else { // none are found; skip both
                ++i1, ++i2;
            }
        }
    }
    return (int) child.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}

