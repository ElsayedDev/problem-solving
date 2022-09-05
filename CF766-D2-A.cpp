#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string tmp, s;
    cin >> tmp >> s;
    long long int ans = -1;
    if (tmp == s)
    {
    }
    else if (tmp.length() > s.length())
    {
        ans = tmp.length();
    }
    else
    {
        ans = s.length();
    }

    cout << ans;
}
