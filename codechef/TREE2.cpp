#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    const string p1 = "010";
    const string p2 = "101";

    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        set<ll> se;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            se.insert(x);
        }

        ll ans = 0;

        for (int i = 0; i < se.size() - 1; i++)
        {
            
            auto it = *se[i];
            
        }
    }
}
