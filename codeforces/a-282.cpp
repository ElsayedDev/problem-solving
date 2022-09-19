#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        if (x != 0)
        {
            arr[x - 1] += y - 1;
        }
        if (x != n - 1)
        {
            arr[x + 1] += arr[x] - y;
        }

        arr[x] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}
