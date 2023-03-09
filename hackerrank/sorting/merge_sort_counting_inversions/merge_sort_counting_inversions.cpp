// https://www.hackerrank.com/challenges/ctci-merge-sort/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countInversions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.

 ChatGPT: You can modify the merge sort algorithm to count the number of 
 swaps. The idea is to count the number of swaps needed when merging 
 the subarrays during the merge step of the merge sort algorithm.
 */

long mergeSort(vector<int>& arr, int begin, int end) {
    long inversions = 0;

    if (begin < end - 1) {
        int middle = begin + (end - begin) / 2;
        inversions += mergeSort(arr, begin, middle);
        inversions += mergeSort(arr, middle, end);

        vector<int> temp(end - begin);
        int i = begin, j = middle, k = 0;

        while (i < middle && j < end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                inversions += middle - i;
                temp[k++] = arr[j++];
            }
        }

        while (i < middle) {
            temp[k++] = arr[i++];
        }

        while (j < end) {
            temp[k++] = arr[j++];
        }

        copy(temp.begin(), temp.end(), arr.begin() + begin);
    }

    return inversions;
}

long countInversions(vector<int> arr) {
    int n = arr.size();
    long inversions = mergeSort(arr, 0, n);
    return inversions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

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

