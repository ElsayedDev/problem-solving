#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n] = {0};

    int m = n;

    

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x] = 1;

        while (arr[m] == 1)
        {
            cout << m << " ";
            m--;
        }
        cout << endl;
    }
}
