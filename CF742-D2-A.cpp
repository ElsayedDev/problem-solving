#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n;
    cin >> n;

    if (n == 0)
        cout << 1;
    else
    {
        int arr[4] = {8, 4, 2, 6};
        cout << arr[((n - 1) % 4)];
    }
}
