#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int ans = 0;
    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == s2[i])
        {
            ans++;
        }
    }

    cout << ans;
}

//
