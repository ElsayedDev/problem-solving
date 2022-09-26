#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int main()
{
    SPEED
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t;
    cin >> t;

    while (t--)
    {
        map<string, int> temp = {
            {"cakewalk", 0},
            {"simple", 0},
            {"easy", 0},
            {"easy-medium", 1},
            {"medium", 1},
            {"medium-hard", 1},
            {"hard", 1},
        };

        ll n;
        cin >> n;

        map<string, int> mm;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            mm[s]++;
        }
        
        bool flag = false;

        if (mm.size() >= 5)
        {
            for (auto i : mm)
            {
                if (temp[i.first] == 0)
                {
                    if (i.second != 1)
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }
        else
        {
            flag = true;
        }

        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
