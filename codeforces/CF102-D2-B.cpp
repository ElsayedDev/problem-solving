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

    ll n = 19;
    // cin >> n;

    // convert n from decimal to binary
    string s = "";

    while (n > 0)
    {
        s += to_string(n % 2);
        n /= 2;
    }

    cout << s << endl;

    // // convert from binary string to decimal int
    // ll ans = 0;
    // s="01111";
    // for (int i =0; i < s.length(); i++)
    // {
    //     ans += (s[i] - '0') * pow(2, i);
    // }
    // cout << ans << endl;
}
