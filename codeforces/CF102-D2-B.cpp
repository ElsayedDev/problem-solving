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

    string s;
    cin >> s;

    ll ans = 0;
    while (s.length() > 1)
    {
        ll sum = 0;
        for (ll i = 0; i < s.length(); i++)
        {
            sum += s[i] - '0';
        }

        s = to_string(sum);

        ans++;
    }
    cout << ans << endl;
}
