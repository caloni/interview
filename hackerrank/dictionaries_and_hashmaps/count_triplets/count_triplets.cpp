// https://www.hackerrank.com/challenges/count-triplets-1/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

long long nChoosek(long n, long k)
{
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;

    long long result = n;
    for (long i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;

    }
    return result;
}

/* Complete the countTriplets function below.

ChatGPT helped me with that. In its words:

This problem is known as the "Count Triplets" problem.
It is a popular problem in coding interviews and is often used to test a
candidate's ability to come up with efficient algorithms for
processing arrays.

The approach I showed you is known as the "hashmap" or "map" approach, and
it's based on the observation that a valid triplet (i, j, k) must have the
property that arr[j] = arr[i] * r and arr[k] = arr[j] * r = arr[i] * r^2.
By keeping track of the frequency of elements that come before and after each
element in the array, we can easily find the number of valid triplets in O(n)
time complexity.
*/
long long countTriplets(vector<long> arr, long r) {
    long long triplets = 0;
    map<long, long> left, right;

    // count all elements 'at the right' before we started
    for (int i = 0; i < arr.size(); ++i) {
        right[arr[i]]++;
    }

    // count all possible triplets with i as the middle element
    if (r == 1) {
        for (const auto& element : right) {
            triplets += nChoosek(element.second, 3);
        }
        return triplets;
    }

    // now we traverse the list again counting the left
    // and calculating how many are in the middle term
    for (int i = 0; i < arr.size(); ++i) {
        right[arr[i]]--; // decrease from the 'at the right' list

        if (arr[i] % r == 0) { // the middle term is divisible by the ratio
            triplets += left[arr[i] / r] * right[arr[i] * r];
        }

        left[arr[i]]++; // increase from the 'at the left' list
    }

    return triplets;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long long ans = countTriplets(arr, r);

    fout << ans << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
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

