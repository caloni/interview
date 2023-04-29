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

 ChatGPT:

The problem asks us to find the length of the longest common child of
two input strings s1 and s2. To solve this problem, we can use dynamic 
programming.

We define a two-dimensional array dp of size (n+1)x(n+1), where n is 
the length of the input strings. The dp[i][j] element of this array 
represents the length of the longest common child of the substrings 
s1[0:i] and s2[0:j].

To fill the dp array, we use a nested loop that iterates over all 
possible pairs of indices (i,j). At each iteration, we compare the 
characters s1[i-1] and s2[j-1]. If they are the same, we add 1 to the 
length of the longest common child found so far, which is stored in dp[i-1][j-1]. 
If they are different, we take the maximum of the longest common child found 
so far for s1[0:i-1] and s2[0:j] (i.e., dp[i-1][j]) and the longest common 
child found so far for s1[0:i] and s2[0:j-1] (i.e., dp[i][j-1]).

Finally, the value in the bottom-right corner of the dp array (dp[n][n]) 
represents the length of the longest common child of the two input strings.
 */

int commonChild(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[m][n];
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

