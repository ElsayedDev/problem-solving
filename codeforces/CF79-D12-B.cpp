#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

const string temp_arr[3] = {"Carrots", "Kiwis", "Grapes"};

int main()
{
    SPEED
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int x = 2, y = 1, mm = 3;
    cout << (y * (x ) +  );
    return 0;

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    int arr[n][m];

    memset(arr, 0, sizeof(arr));

    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = i + 1;
    }

    for (ll i = 0; i < t; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (arr[x - 1][y - 1] > 0)
        {
            cout << "Waste" << endl;
        }
        else
        {
            ll w = 0;
            ll s = x;
            while (s)
            {
                for (ll j = y - 1; j >= 0; j--)
                {
                    if (arr[s - 1][j] > 0)
                    {
                        w = arr[s - 1][j];
                        break;
                    }
                }

                s--;
            }
            // int pos = x * y - w - 1;
            // cout << temp_arr[pos % 3] << endl;

            // number of cells farmers from x , y

            ll total_cell = x * (y - 1) + y % m;
        }
    }
}
