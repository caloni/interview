// https://www.hackerrank.com/challenges/triple-sum/problem
#include <stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    long total = 0;

    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    sort(b.begin(), b.end());
    last = unique(b.begin(), b.end());
    b.erase(last, b.end());

    sort(c.begin(), c.end());
    last = unique(c.begin(), c.end());
    c.erase(last, c.end());

    for (int p = a.size() - 1; p >= 0; --p) {
        int q = b.size() - 1;
        int r1 = 0, r2 = 0;
        if (a[p] <= b[q]) {
            --q;
            while (q >= 0 && a[p] <= b[q]) --q;
            ++q;
            for (int qi = q; qi < b.size() && r2 < c.size(); ++qi) {
                if (b[qi] >= c[r2]) {
                    ++r2;
                    while (r2 < c.size() && b[qi] >= c[r2]) ++r2;
                    --r2;

                    cout << "(" << a[p] << "," << b[qi] << "," << c[r1] << ") ... (" << a[p] << "," << b[b.size()-1] << "," << c[r2] << ")\n";
                    /*
                    for (int i = qi; i < b.size(); ++i) {
                        for (int j = r1; j < r2 + 1; ++j) {
                            cout << "(" << a[p] << "," << b[i] << "," << c[j] << ")\n";
                        }
                    }
                    */
                    int tripleRange = (b.size() - qi) * (r2 - r1 + 1);
                    total += tripleRange;
                    r1 = ++r2;
                }
            }
        }
    }

    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
        return x == y and x == ' ';
        });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

