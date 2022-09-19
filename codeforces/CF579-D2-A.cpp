#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int x, ans = 0;
    cin >> x;

    while (x > 0)
    {
        if (x % 2 == 1)
        {
            ans++;
        }
        x /= 2;
    }
    cout<<ans;
}

//
//