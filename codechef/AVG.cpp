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
        int n, k, v;
        cin >> n >> k >> v;

        int sum = 0, arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        int sum_given = v * (n + k);

        if (sum_given > sum && (sum_given - sum) % k == 0)
        {
            cout << (sum_given - sum) / k << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
