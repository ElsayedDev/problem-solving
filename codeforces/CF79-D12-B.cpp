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
        ll n, sum = 0;
        cin >> n;

        ll arr[n];

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        ll s = (sum / (n + 1));

        for (ll i = 0; i < n; i++)
        {
            ll x = arr[i] - s;

            cout << x << " ";
        }

        cout << endl;
    }
}
