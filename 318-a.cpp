#include <bits/stdc++.h>

using namespace std;
int main()
{

    long long int n, k;

    cin >> n >> k;

    if (n % 2 == 0)
    {
        // even
        if (k > n / 2)
        {
            cout << (k - (n / 2)) * 2;
        }
        else
        {
            cout << k * 2 - 1;
        }
    }
    else
    {
        if (k > n / 2 + 1)
        {
            cout << (k - ((n / 2) + 1)) * 2;
        }
        else
        {
            cout << k * 2 - 1;
        }
    }
}
