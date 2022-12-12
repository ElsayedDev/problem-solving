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
        ll n, min_element = 0, ans = 0;
        cin >> n;
        ll arr[n];

        vector<ll> even_positions;

        // read data
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (i == 0)
            {
                min_element = arr[i];
            }

            else if (arr[i] < min_element)
            {
                min_element = arr[i];
            }

            if (arr[i] % 2 == 0)
            {
                even_positions.push_back(arr[i]);
            }
        }

        for (auto x : even_positions)
        {
            ans += x / min_element - min_element;
        }

        cout << ans << endl;
    }
}
