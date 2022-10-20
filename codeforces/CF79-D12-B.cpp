#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

const map<char, string> temp = {
    {'w', "Waste"},
    {'c', "Carrots"},
    {'k', "Kiwis"},
    {'g', "Grapes"},
};

int main()
{
    SPEED
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    char arr[n][m];

    memset(arr, 0, sizeof(arr));

    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = 'w';
    }

    ll index = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (arr[i][j] == 'w')
            {
                arr[i][j] = 'w';
            }
            else
            {
                if (index % 3 == 0)
                {
                    arr[i][j] = 'c';
                }
                else if (index % 3 == 1)
                {
                    arr[i][j] = 'k';
                }
                else
                {
                    arr[i][j] = 'g';
                }
                index++;
            }
        }
    }

    for (ll i = 0; i < t; i++)
    {
        ll x, y;
        cin >> x >> y;
        cout << temp.at(arr[x - 1][y - 1]) << endl;
    }
}

//