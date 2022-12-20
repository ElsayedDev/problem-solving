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
        ll n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int dif = (i + 1) - arr[i];
            if (dif < 0)
            {
                ans = -1;
                break;
            }
            else
            {
                ans += dif;
            }
        }

        cout << ans << endl;
    }
}
