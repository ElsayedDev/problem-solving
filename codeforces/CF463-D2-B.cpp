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
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    if (arr[n - 2] < arr[n - 1])
    {
        cout << arr[n - 1];
        return 0;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] == arr[i])
            {
            }
            else if (arr[i + 1] > arr[i])
            {

                arr[i + 1] = 0;
            }
            else
            {
                arr[i + 1] = arr[i] - arr[i + 1];
            }
        }

        cout << arr[n - 1];
        return 0;
    }
}
