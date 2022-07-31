#include <bits/stdc++.h>

using namespace std;
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long int c, ans = 0;

        cin >> n >> c;

        for (int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            ans += x;
        }

        if (ans > c)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}
