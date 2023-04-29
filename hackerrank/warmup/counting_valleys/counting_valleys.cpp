// https://www.hackerrank.com/challenges/counting-valleys/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
To solve the [counting valleys problem] keep a valley counter that only increments
when the hiker is coming up to the sea level. Monitor the altitude and the new
altitude and compare. If the altitude was negative (into a valley) and the new
altitude is zero (sea level) then that's a new valley to count. This strategy
avoid to count valleys inside valleys before the hiker gets up to sea level.

This solution has a complexity of O(n).
*/
int countingValleys(int steps, string path) {
    int valleys = 0;
    int altitude = 0;

    for (int s = 0; s < steps; ++s)
    {
        int step = path[s] == 'D' ? -1 : 1;
        int newAltitude = altitude + step;

        if (altitude < 0 && newAltitude == 0)
        {
            valleys++;
        }
        altitude = newAltitude;
    }

    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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

