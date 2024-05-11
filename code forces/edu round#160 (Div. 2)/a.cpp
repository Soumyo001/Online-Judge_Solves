#include <iostream>
#include <string>
using namespace std;
pair<int, int> find_values(const string &s)
{
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != '0')
        {
            string a_str = s.substr(0, i);
            string b_str = s.substr(i);
            int a = stoi(a_str);
            int b = stoi(b_str);
            if (a != 0 && b != 0 && b > a)
            {
                return make_pair(a, b);
            }
        }
    }
    return make_pair(-1, -1);
}

int main()
{
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test)
    {
        string s;
        cin >> s;

        pair<int, int> result = find_values(s);

        if (result.first == -1)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}