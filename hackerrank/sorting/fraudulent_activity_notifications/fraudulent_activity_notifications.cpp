// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
    int notifications = 0;
    bool odd = d % 2;
    size_t med = d / 2;
    vector<int> lookback(expenditure.begin(), expenditure.begin() + d);
    
    sort(lookback.begin(), lookback.end()); // we will keep it sorted
    
    for( size_t i = d; i < expenditure.size(); ++i ) {
        /* An important lesson here is that the median using mid1+mid2/2 could
           make the math wrong because the result is not round. When dealing
           with integers is important to notice if there are some divisions
           that can make this happen. My first version did this and I needed
           to fix it by debugging the code.
        */
        int medianX2 = odd ? lookback[med] * 2 : lookback[med - 1] + lookback[med];
        if( expenditure[i] >= medianX2 ) {
            ++notifications;
        }
        
        // remove the day minus d
        auto oldDayPos = lower_bound(lookback.begin(), lookback.end(), expenditure[i-d]);
        lookback.erase(oldDayPos);
        
        // insert current day
        auto newDayPos = lower_bound(lookback.begin(), lookback.end(), expenditure[i]);
        lookback.insert(newDayPos, expenditure[i]);
    }
    
    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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

