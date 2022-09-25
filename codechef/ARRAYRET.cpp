#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

ll count_numbers(ll n)
{
    ll x = (n * (n + 1) / 2) - 1;

    return (x);
}

int main()
{
    SPEED
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];

        ll min_v = 0;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (i == 0)
            {
                min_v = arr[0];
            }
            else
            {
                min_v = min(arr[i], min_v);
            }
        }

        for (ll i = 0; i < n; i++)
        {
            cout << arr[i] - min_v + 1 << " ";
        }

        cout << endl;
    }
}