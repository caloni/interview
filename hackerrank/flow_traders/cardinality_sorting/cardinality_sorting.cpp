// https://www.hackerrank.com/test/dkhlrnnee8l/questions/ddt8r4cect9
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'cardinalitySort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY nums as parameter.
 */

string toBin(int num) {
    ostringstream os;
	os << bitset<31>(num);
    return os.str();
}

int binCardinality(int num) {
    string s = toBin(num);
	return count(s.begin(), s.end(), '1');
}


vector<int> cardinalitySort(vector<int> nums) {
    sort(nums.begin(), nums.end(), [](int i1, int i2){
        int c1 = binCardinality(i1), c2 = binCardinality(i2);
        if( c1 != c2 ) return c1 < c2;
        return i1 < i2;
    });
    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ' << toBin(nums[i]) << ' ' << binCardinality(nums[i]) << endl;
    return nums;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nums_count_temp;
    getline(cin, nums_count_temp);

    int nums_count = stoi(ltrim(rtrim(nums_count_temp)));

    vector<int> nums(nums_count);

    for (int i = 0; i < nums_count; i++) {
        string nums_item_temp;
        getline(cin, nums_item_temp);

        int nums_item = stoi(ltrim(rtrim(nums_item_temp)));

        nums[i] = nums_item;
    }

    vector<int> result = cardinalitySort(nums);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

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

