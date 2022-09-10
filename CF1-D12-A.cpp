#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n, m, a;
    cin >> n >> m >> a;

    long long int x = n / a;

    long long int y = m / a;

    if (n % a != 0)
        x++;
    if (m % a != 0)
        y++;

    cout << x * y;
}
