#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, a, ans = 0;
    cin >> n >> a;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // in case the position i have had a 1
    if (arr[a - 1])
    {
        ans++;
        arr[a - 1] = 0;
    }

    int distance = 1;
    // left & right of my position

    if (n > 1)
    {
        for (int i = a; i < n; i++)
        {
            int left_index = a - distance - 1;

            if (left_index < 0)
            {
                break;
            }

            if (arr[i] == 1 && arr[left_index] == 1)
            {
                ans += 2;
            }

            arr[i] = 0;
            arr[left_index] = 0;

            distance++;
        }

        // remain positions

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                ans++;
            }
        }
    }

    cout << ans;
}