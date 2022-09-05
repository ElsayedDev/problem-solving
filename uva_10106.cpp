#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int arr_sorted[n];

    copy(arr, arr + n, arr_sorted);

    sort(arr_sorted, arr_sorted + n);

    for (int i = 0; i < n; i++)
    {
        int mx = arr_sorted[n - 1];
        int mn = arr_sorted[0];

        if (mx - arr[i] == 0)
        {
            mx = arr_sorted[i - 1];
        }

        if (mn - arr[i] == 0)
        {
            mn = arr_sorted[i + 1];
        }

        int max_v = max_element(abs(arr[i] - mn), abs(arr[i] - mx));
        int min_v = min_element(abs(arr[i] - mn), abs(arr[i] - mx));

        cout << min_v << " " << max_v << endl;
    }
}
