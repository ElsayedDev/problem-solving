#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

ll n;

void reverse(ll arr[], ll l, ll r)
{
    ll arr2[n];

    for (ll i = l, j = r; i <= r; i++, j--)
    {
        arr2[i] = arr[j];
    }

    for (ll i = l; i <= r; i++)
    {
        arr[i] = arr2[i];
    }
}

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    cin >> n;

    ll arr[n], temp[n];

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        arr[i] = x;
        temp[i] = x;
    }

    sort(temp, temp + n);

    ll l = -1, r = -1;

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] != temp[i])
        {
            l = i;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (arr[i] != temp[i])
        {
            r = i;
            break;
        }
    }

    if (l == -1)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    reverse(arr, l, r);

    for (ll i = 0; i < n; i++)
    {
        if (arr[i] != temp[i])
        {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes\n"
         << l + 1 << " " << r + 1;
}
