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

    vector<ll> v(n);

    for (ll i = 0; i < n; i++)
        cin >> v[i];

    int flag = 0;
    ll a, b;
    for (ll i = 0; i < n; i++)
    {
        if (flag > 1 && i < n - 1)
        {
            cout << "no";
            return 0;
        }
        else
        {
            if (i > 0 && i < n - 1)
            {
                if (v[i - 1] > v[i] || v[i] < v[i + 1])
                {
                    flag++;

                    a = v[i - 1];
                    b = v[i + 1];

                    // swap
                    ll temp = v[i];

                    v[i] = v[i - 1];
                    v[i - 1] = temp;
                }
            }
        }
    }
    if (flag > 1)
        cout << "no";
    else
        cout << "yes\n"
             << b << " " << a;
}
