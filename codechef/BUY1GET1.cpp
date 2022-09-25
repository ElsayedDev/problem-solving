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
        map<char, ll> m;
        string s;
        cin >> s;
        for (ll i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
        }
        ll count = 0;

        for (auto i : m)
            count += (i.second + 1) / 2;

        cout << count << endl;
    }
}
