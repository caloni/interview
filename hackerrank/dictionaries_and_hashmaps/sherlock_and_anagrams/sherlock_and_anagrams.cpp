// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
#include <stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// transform a string to its anagramatic information
// to be compared with another string
inline map<char, int> ss2anal(string s) {
    map<char, int> anal;
    for( char c: s ) {
        anal[c] += 1;
    }
    return anal;
}

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    int pairs = 0;
    
    //cout << "s: " << s << endl;
    
    // for each substring size 1-character to size-1 characters
    for( int ssSz = 1; ssSz <= (int) s.size()-1; ++ssSz ) {
        
        // for each position...
        for( int i = 0; i < (int) s.size() - ssSz; ++i ) {
            string ss = s.substr(i, ssSz);
            map<char, int> anal = ss2anal(ss);
            
            // ...compare for each subsequent position
            for( int j = i+1; j <= (int) s.size() - ssSz; ++j ) {
                string ss2 = s.substr(j, ssSz);
                map<char, int> anal2 = ss2anal(ss2);
                
                //cout << "ss:" << ss << " and ss2:" << ss2 
                    //<< " are" << (anal == anal2 ? "" : " NOT") << " anagramic" << endl;
                
                if( anal == anal2 ) {
                    ++pairs;
                }
            }
        }
    }
    
    return pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

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

