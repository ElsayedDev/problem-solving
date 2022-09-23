#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll arr[n];


        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        ll ans = 0;

        for (ll i = n - 1; i > 0; i--)
        {
            ans += arr[i] - arr[i - 1];
        }

        cout << ans + 1 << endl;
    }
}
