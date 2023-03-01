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

// Complete the countTriplets function below.
long long countTriplets(vector<long> arr, long r) {
    long long triplets = 0;
    map<long, vector<int>> indexes;

    // get the index for all numbers
    for (int i = 0; i < arr.size(); ++i) {
        indexes[arr[i]].push_back(i);
    }

    // check directly in the indexes
    for (const auto& item : indexes) {
        const vector<int>& firsts = item.second;
        const auto& seconds = indexes.find(item.first * r);
        const auto& thirds = indexes.find(item.first * r * r);

        // the seconds and thirds are the same; apply combination formula
        if (r == 1) {
            triplets = nChoosek(firsts.size(), 3);
        }
        // we have seconds and thirds
        else if (seconds != indexes.end() && thirds != indexes.end()) {

            // for every first item of triplet
            for (int firstIdx = 0; firstIdx < (int)firsts.size(); ++firstIdx) {
                int firstPos = firsts[firstIdx];

                // for every second item after the first
                for (int secondIdx = 0; secondIdx < seconds->second.size(); ++secondIdx) {

                    if (seconds->second[secondIdx] > firstPos) {
                        int secondPos = seconds->second[secondIdx];

                        // for every third item after the second
                        for (int thirdIdx = 0; thirdIdx < thirds->second.size(); ++thirdIdx) {

                            if (thirds->second[thirdIdx] > secondPos) {
                                triplets += thirds->second.size() - thirdIdx;
                                break;
                            }
                        }
                    }
                }
            }
        }
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

