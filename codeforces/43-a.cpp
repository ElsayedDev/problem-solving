#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;

    cin >> n;
    string arr[n];
    string winner = "";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (i == 0)
        {
            winner = arr[0];
        }
        else
        {

            if (count(arr, arr + n, arr[i]) > count(arr, arr + n, winner))
            {
                winner = arr[i];
            }
        }
    }

    cout << winner;
}
