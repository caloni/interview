// https://www.hackerrank.com/test/dkhlrnnee8l/questions/1bk6i05ja
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'maxValue' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY rounds
 */

long maxValue(int n, vector<vector<int>> rounds) {
    vector<long> assets;
    for( const vector<int>& investment: rounds ) {
        for( size_t i = investment[0]-1; i < investment[1]; ++i ) {
            if (assets.size() < investment[1]) assets.resize(investment[1]);
            assets[i] += investment[2];
        }
    }
    sort(assets.begin(), assets.end());
    long biggerAsset = assets[assets.size()-1];
    return biggerAsset;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string rounds_rows_temp;
    getline(cin, rounds_rows_temp);

    int rounds_rows = stoi(ltrim(rtrim(rounds_rows_temp)));

    string rounds_columns_temp;
    getline(cin, rounds_columns_temp);

    int rounds_columns = stoi(ltrim(rtrim(rounds_columns_temp)));

    vector<vector<int>> rounds(rounds_rows);

    for (int i = 0; i < rounds_rows; i++) {
        rounds[i].resize(rounds_columns);

        string rounds_row_temp_temp;
        getline(cin, rounds_row_temp_temp);

        vector<string> rounds_row_temp = split(rtrim(rounds_row_temp_temp));

        for (int j = 0; j < rounds_columns; j++) {
            int rounds_row_item = stoi(rounds_row_temp[j]);

            rounds[i][j] = rounds_row_item;
        }
    }

    long result = maxValue(n, rounds);

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

