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
        ll n;
        cin >> n;

        double sq = sqrt(n);
        double remind = sq - (int)sq;

        int sq_i = (int)sq;
        if (remind > 0.5)
        {
            cout << ((sq_i + 1) * (sq_i + 1)) - n << endl;
        }
        else
        {
            cout << n - (sq_i * sq_i) << endl;
        }
    }
}
