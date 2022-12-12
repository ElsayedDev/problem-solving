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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, p = 0;
        cin >> n;

        // read data
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            if (x % 2 == 0)
            {
                p++;
            }
        }

        cout << ((p != n) ? p : 0) << endl;
    }
}
