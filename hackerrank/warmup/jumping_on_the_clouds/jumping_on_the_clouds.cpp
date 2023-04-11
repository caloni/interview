// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
To solve the [cloud jump problem] create a loop and advance current position until
finished. Try the double jump at first and ordinary jump else by incrementing
position by 1 or 2 and incrementing jump counter. If in the end position just
increment and get out of the loop. Return the jump counter.

This solution has a complexity of O(n).
*/
int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    size_t i = 0;

    while (i < c.size()) {
        if (i < c.size() - 2 && c[i + 2] == 0) {
            i += 2;
            ++jumps;
        }
        else if (i < c.size() - 1) {
            i += 1;
            ++jumps;
        }
        else {
            i += 1;
        }
    }

    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

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

