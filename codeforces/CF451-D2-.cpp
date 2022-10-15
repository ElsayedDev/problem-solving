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

    ll n;
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
        if (arr[i] == temp[i])
            continue;
        else
        {
            if (l == -1)
            {
                l = i;
            }
            else if (r == -1)
            {
                r = i;
            }
            else
            {
                cout << "no";
                return 0;
            }
        }
    }
    if (arr[r] < arr[l])
    {
        swap(arr[l], arr[r]);
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] != temp[i])
            {
                cout << "no";
                return 0;
            }
        }

        cout << "yes\n"
             << l + 1 << " " << r + 1;
    }

    else if (r == -1 && l == -1)
    {
        cout << "yes\n"
             << 1 << " " << 1;
    }
    else
    {
        cout << "no";
        return 0;
    }
}
