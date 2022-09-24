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
        int n;
        cin >> n;

        int arr[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        int max_el = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i + j < n)
                    sum += arr[i + j][j];
            }
            max_el = max(max_el, sum);
        }

        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i + j < n)
                    sum += arr[j][i + j];
            }
            max_el = max(max_el, sum);
        }
        cout << max_el << endl;
    }
}
