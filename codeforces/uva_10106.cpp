#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        int max_v = 0;

        int min_v = 0;

        if (i == 0)
        {
            max_v = abs(arr[i] - arr[n - 1]);
            min_v = abs(arr[i] - arr[i + 1]);
        }
        else if (i == (n - 1))
        {
            max_v = abs(arr[i] - arr[0]);
            min_v = abs(arr[i] - arr[i - 1]);
        }
        else
        {
            max_v = max(abs(arr[i] - arr[0]), abs(arr[i] - arr[n - 1]));
            min_v = min(abs(arr[i] - arr[i + 1]), abs(arr[i] - arr[i - 1]));
        }

        cout << min_v << " " << max_v << endl;
    }
}
