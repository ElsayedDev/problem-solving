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

    for (int i = 0; i < 3; i++)
    {
        cout<< s[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        string val = "";
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                val += s[j];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (val[i] == val[i + 1])
            {
                // val[i] = '0';
                cout << val << endl;
                return 0;
            }
            cout << val[i] << endl;
        }

        cout << endl;
      
    }
    cout << "Impossible" << endl;
}
