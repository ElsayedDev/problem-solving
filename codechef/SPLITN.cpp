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
        ll n, ans = 0;
        cin >> n;
        
        while (n > 0)
        {
            if (n & 1 == 1)
                ans++;
            n = n >> 1;
        }
        cout << ans - 1 << endl;
    }
}