// https://www.hackerrank.com/challenges/crush/problem
// https://en.wikipedia.org/wiki/Segment_tree
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 *
 * ChatGPT helped me to solve this problem with the code and explaining
 * that the fastest solution to this problem is using a segment tree. A
 * segment tree is like a binary tree that keeps the value in segments,
 * avoiding the O(n) complexity using a binary search. In this way, to
 * update the intervals in the problem is a recursive task using a 4-size
 * array in that the position is structure as a binary tree. To the query
 * for the lastest value we need to add all the values in each range. It
 * is somewhat tricky for me to understand this part, but I got the
 * general idea.
 */

// Segment tree implementation

void update(int v, int tl, int tr, int l, int r, int x, vector<long>& t) {
    if (l > r) return;
    if (l == tl && r == tr) {
        t[v] += x;
    }
    else {
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), x, t);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x, t);
    }
}

long query(int v, int tl, int tr, int pos, vector<long>& t) {
    if (tl == tr) {
        return t[v];
    }
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return t[v] + query(v * 2, tl, tm, pos, t);
        }
        else {
            return t[v] + query(v * 2 + 1, tm + 1, tr, pos, t);
        }
    }
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    int m = queries.size();

    vector<long> t(4 * n); // segment tree of size 4 * n

    for (int i = 0; i < m; i++) {
        int l, r, x;
        l = queries[i][0];
        r = queries[i][1];
        x = queries[i][2];
        update(1, 1, n, l, r, x, t);
    }

    long max_val = 0;
    for (int i = 1; i <= n; i++) {
        max_val = max(max_val, query(1, 1, n, i, t));
    }

    return max_val;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

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

