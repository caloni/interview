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
 */

long countInversions(vector<int>& arr, int begin, int middle, int end) {
    long inversions = 0;

    // here the son cries and the mother does not see him
    for (int k = 0; k < end; ++k) {
        if (begin < middle && middle < end) {
            if (arr[begin] > arr[middle]) {
                arr.insert(arr.begin() + begin, arr[middle]);
                arr.erase(arr.begin() + (middle + 1));
                inversions += middle - begin;
                ++middle;
                ++begin;
            }
            else {
                ++begin; // no inversion
            }
        } // else the rest if sorted
    }
    return inversions;
}

long countInversions(vector<int>& arr, int begin, int end) {
    int size = end - begin;
    if (size < 2) return 0;
    if (size == 2) {
        if (arr[begin] > arr[end - 1]) {
            swap(arr[begin], arr[end - 1]);
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        long inversions = 0;
        int middle = size / 2 + size % 2;
        inversions += countInversions(arr, begin, middle);
        inversions += countInversions(arr, middle, end);
        inversions += countInversions(arr, begin, middle, end);
        return inversions;
    }
}

long countInversions(vector<int> arr) {
    long inversions = 0;

    inversions = countInversions(arr, 0, arr.size());

    /*
    for( size_t i = 1; i < arr.size(); ++i ) {
        if( arr[i] < arr[i-1] ) {
            swap(arr[i], arr[i-1]);
            if( i > 1 ) i -= 2; // compare again with previous
            ++inversions;
        }
    }
    */
    
    return inversions;
}

int main()
{
    bool debug = false;
    while (!debug);
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

