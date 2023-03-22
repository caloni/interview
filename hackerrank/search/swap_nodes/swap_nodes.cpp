// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

void traverseNodes(map<int, vector<int>>& nodes, vector<int>& visits,
    map<int, int>& nodeDepth, map<int, bool>& swaps,
    int node) {

    auto fndNode = nodes.find(node / 2);
    int nodeValue = node == 1 ? 1 : fndNode != nodes.end() ? fndNode->second[node % 2] : -1;
    if (nodeValue == -1) return;
    int nodeLeft = node * 2;
    int nodeRight = node * 2 + 1;
    bool inverted = swaps[nodeDepth[node]];
    traverseNodes(nodes, visits, nodeDepth, swaps, inverted ? nodeRight : nodeLeft);
    visits.push_back(nodeValue);
    traverseNodes(nodes, visits, nodeDepth, swaps, inverted ? nodeLeft : nodeRight);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> screenshots;

    // build nodeXdepth relation
    map<int, int> nodeDepth;
    nodeDepth[1] = 1;
    nodeDepth[2] = nodeDepth[3] = 2;
    int node = 4;
    int depth = 3;
    int endDepth = 8;
    while (node < indexes.size()) {
        while (node < endDepth) {
            nodeDepth[node++] = depth;
        }
        ++depth;
        endDepth *= 2;
    }

    // build nodes map to consider empty nodes
    map<int, vector<int>> nodes;
    int idx = 0;
    list<int> parents{ 1 };
    do {
        int parent = parents.front();
        nodes[parent] = indexes[idx];
        if (indexes[idx][0] != -1) parents.push_back(parent * 2);
        if (indexes[idx][1] != -1) parents.push_back(parent * 2 + 1);
        ++idx;
        parents.pop_front();
    } while (parents.size());

    // build each swap list before visiting tree
    map<int, bool> swaps;
    for (int q : queries) {
        for (int i = q; i <= depth; i += q) {
            swaps[i] = !swaps[i]; // toogle swap
        }
        vector<int> visits;
        traverseNodes(nodes, visits, nodeDepth, swaps, 1);
        screenshots.push_back(visits);
    }

    return screenshots;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

