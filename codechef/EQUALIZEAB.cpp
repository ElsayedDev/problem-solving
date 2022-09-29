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
        ll a, b, x;
        cin >> a >> b >> x;
        if (a > b)
        {
            swap(b, a);
        }

        if ((b - a) % (2 * x) == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
