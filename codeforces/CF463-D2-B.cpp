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

    ll n, ans = 0;
    cin >> n;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > ans)
        {
            ans = x;
        }
    }
    cout << ans;
}
