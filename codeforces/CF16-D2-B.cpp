#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n, m, ans = 0;
    cin >> n >> m;

    if (m == 1)
    {
        ll a, b;
        cin >> a >> b;

        if (n > a)
        {
            ans += a * b;
        }
        else
        {
            ans += n * b;
        }
    }
    else
    {
        vector<pair<ll, ll>> v;

        while (m--)
        {
            ll a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        // sort v by second element
        sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b)
             { return a.second > b.second; });

        for (ll i = 0; n > 0; i++)
        {
            if (n > v[i].first)
            {

                ans += v[i].first * v[i].second;

                n -= v[i].first;
            }
            else
            {
                ans += (n)*v[i].second;
                n -= n;
            }
        }
    }

    cout << ans;
}