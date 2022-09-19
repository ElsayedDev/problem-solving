#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long int t;
    cin >> t;
    while (t--)
    {
        unsigned int x;
        cin >> x;

        unsigned int sq = (int)sqrt(x);

        if (sq * sq == x)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
