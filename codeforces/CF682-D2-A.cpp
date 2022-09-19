#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n, m, sum = 0;
    double db;

    cin >> n >> m;
    sum = (n * m) / 5;

    db = (double)((n * m) / 5.0);

    if (db - sum > .5)
    {
        cout << sum + 1;
    }

    else
    {
        cout << sum;
    }
}
