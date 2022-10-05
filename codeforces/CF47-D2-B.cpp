#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

string rearrange(string s)
{
    string ans = "";

    if (s[1] == '>')
    {
        ans += s[2];
        ans += s[0];
    }
    else
    {
        ans += s[0];
        ans += s[2];
    }
    return ans;
}

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 3; i++)
    {
        s[i] = rearrange(s[i]);
    }

    vector<string> v;

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                v.push_back(s[i] + s[j]);
            }
        }
    }

    for (string value : v)
    {
        for (int i = 0; i < value.length() - 1; i++)
        {
            if (value[i] == value[i + 1])
            {
                cout << value.substr(0, i) << value.substr(i + 1, 3 - i) << endl;
                return 0;
            }
        }
    }
    cout << "Impossible" << endl;
}
