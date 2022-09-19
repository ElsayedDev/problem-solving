#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m, ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            ll a;
            cin >> a;
            if (a <= m / 2)
            {
                ans += (m - a);
            }
            else
            {
                ans += (a - 1);
            }
        }

        cout << ans << endl;
    }
}
