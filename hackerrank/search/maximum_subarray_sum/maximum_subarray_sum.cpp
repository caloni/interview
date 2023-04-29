// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
gh-3: Implement the dummy slow solution for max subarray sum issue.

I know that this won't solve the harder tests with lots of numbers. I just
wanted to clarify that there is a ingenuous solution before to figure out what
is the clever solution. We need to calculate the moduli of all the possible
combinations of subarrays before to know what is the maximum one?
 */
long maximumSum(vector<long> a, long m) {
    long maxSum = 0;
    for (int i = 0; i < a.size(); ++i) {
        long aSum = 0;
        for (int j = i; j < a.size(); ++j) {
            aSum = (aSum + a[i]) % m;
            maxSum = max(maxSum, aSum);
        }
        aSum = 0;
        for (int j = 0; j < i; ++j) {
            aSum = (aSum + a[i]) % m;
            maxSum = max(maxSum, aSum);
        }
    }
    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        long m = stol(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

        fout << result << "\n";
    }

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

