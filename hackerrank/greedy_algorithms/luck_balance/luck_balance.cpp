// https://www.hackerrank.com/challenges/luck-balance/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'luckBalance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. 2D_INTEGER_ARRAY contests
 */

int luckBalance(int k, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end(), []
    (const vector<int>& contest1, const vector<int>& contest2) {
            if (contest1[1] != contest2[1]) return contest1[1] > contest2[1];
            return contest1[0] < contest2[0];
        });
    auto findMinor = find_if(contests.begin(), contests.end(), [](const vector<int>& c) { return c[1] == 0; });
    int minorPos = findMinor != contests.end() ? findMinor - contests.begin() : contests.size();
    // I don't know why, if k=N Lena has to lose all contests (test #7 broken because of that).
    // So I am defining a special treatment if k is greater than the number of important contests.
    int loses = minorPos > k ? minorPos - k : -1;
    int bestLuck = 0;
    for (int i = 0; i < contests.size(); ++i) {
        const int& luck = contests[i][0];
        const int& importance = contests[i][1];
        if (i < loses) {
            bestLuck -= luck;
        }
        else {
            bestLuck += luck;
        }
    }
    return bestLuck;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> contests(n);

    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        string contests_row_temp_temp;
        getline(cin, contests_row_temp_temp);

        vector<string> contests_row_temp = split(rtrim(contests_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int contests_row_item = stoi(contests_row_temp[j]);

            contests[i][j] = contests_row_item;
        }
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

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

