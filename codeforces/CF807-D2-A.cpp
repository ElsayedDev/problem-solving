#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr_l[n];
    int arr_r[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr_l[i] >> arr_r[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr_l[i] != arr_r[i])
        {
            cout << "rated";
            return 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (arr_l[i] > arr_l[i - 1])
        {

            cout << "unrated";
            return 0;
        }
    }
    cout << "maybe";
    return 0;
}