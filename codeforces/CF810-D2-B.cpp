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

    ll n, f;
    cin >> n >> f;
    vector<pair<ll, ll>> v;

    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    // sort v by b
    sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.second > b.second; });


    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {

        if (v[i].first != 0 && v[i].second * 2 >= v[i].first)
        {

            ans += v[i].second;
            f--;
        }

        if (f == 0)
        {
            break;
        }
    }

    cout << ans << endl;
}
