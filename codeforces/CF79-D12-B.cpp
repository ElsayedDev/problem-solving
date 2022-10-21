#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

const string temp_arr[3] = {"Carrots", "Kiwis", "Grapes"};

typedef struct holder
{
    int y, x, total;
};

int main()
{
    SPEED
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    int arr[m][n];

    memset(arr, 0, sizeof(arr));

    map<int, int> blocks;
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;

        if (blocks[y] <= 0)
        {
            blocks[y] = x;
        }
        else
        {
            blocks[y] += blocks[y];
        }
    }

    for (ll i = 0; i < t; i++)
    {
        ll y, x;
        cin >> x >> y;

        if (blocks[y] == x)
        {
            cout << "Waste" << endl;
            continue;
        }
        else
        {
            ll w = 0;
            ll s = y;

            while (s > 0)
            {
                if (blocks[s] > 0)
                {
                    w++;
                    break;
                }

                s--;
            }

            // ll pos = (y * m + x) - w;
            // cout << temp_arr[(pos ) % 3] << endl;

            // cout << temp_arr[pos % 3] << endl;
        }
    }
}

//