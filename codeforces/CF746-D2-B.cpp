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

    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;

    if (n % 2 == 0)
    {

        for (int i = n - 1; i >= 0; i--)
        {
            if (i % 2 == 0)
            {
                ans += s[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 != 0)
            {
                ans += s[i];
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (i % 2 != 0)
            {
                ans += s[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans += s[i];
            }
        }
    }

    cout << ans << endl;
}

//