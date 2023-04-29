// https://www.hackerrank.com/challenges/crush/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
To solve the [array manipulation problem] ChatGPT helped me with the code.
Now in the review I realized how segment tree work and how binary trees can
be implemented using arrays.

The issue about this problem is that summing up intervals costs too much
processing to large intervals. In order to do that segment trees help, since
theirs nodes contain the sum of all its nodes bellow. This way, to get the sum
of determined intervals all we need to do is to get the bigger intervals and sum
it up.
*/

// Segment tree to array manipulation implementation
//

long query(int node, int left, int right, int pos, const vector<long>& tree) {
    if (left == right) {
        return tree[node];
    }
    else {
        int nodeLeft = 2 * node;
        int nodeRight = 2 * node + 1;
        int middle = (left + right) / 2;
        if (pos <= middle)
            return tree[node] + query(nodeLeft, left, middle, pos, tree);
        else
            return tree[node] + query(nodeRight, middle + 1, right, pos, tree);
    }
}

void update(int node, int left, int right, int posLeft, int posRight, int value, vector<long>& tree) {
    if (posLeft > posRight) return;
    if (posLeft == left && posRight == right) {
        tree[node] += value;
    }
    else {
        int nodeLeft = 2 * node;
        int nodeRight = 2 * node + 1;
        int middle = (left + right) / 2;
        update(nodeLeft, left, middle, posLeft, min(posRight, middle), value, tree);
        update(nodeRight, middle + 1, right, max(posLeft, middle + 1), posRight, value, tree);
    }
}

// Solution
long arrayManipulation(int n, vector<vector<int>> queries) {
    int m = queries.size();
    vector<long> t(4 * n); // room for binary tree

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

