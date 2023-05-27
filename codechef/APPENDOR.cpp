#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

int main()
{
    ReadDataWithSpeed();

    ll t, n, y;
    cin >> t;

    while (t--)
    {
        cin >> n >> y;

        ll b_or = 0;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            b_or = b_or | x;
        }

        ll res = (b_or ^ y);

        if ((b_or | res) == y)
        {
            cout << res << "\n";
        }
        else
        {
            cout << "-1"
                 << "\n";
        }
    }

    return 0;
}