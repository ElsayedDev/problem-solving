#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << n / 2;
    }
    else
    {
        cout << n / 2 - n;
    }
}
