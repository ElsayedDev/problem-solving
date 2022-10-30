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
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for (ll i = n; i >= 3; i--)
    {

        if (arr[i - 1] + arr[i - 2] > arr[i - 3] && arr[i - 1] + arr[i - 3] > arr[i - 2] && arr[i - 2] + arr[i - 3] > arr[i - 1])
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
