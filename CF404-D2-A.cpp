#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n;
    char this_c = ' ';

    bool is_ok = true;

    for (int i = 0; i < n / 2; i++)
    {
        cin >> s;
        if (i == 0)
        {
            this_c = s[0];
        }
        if (s[i] == s[n - 1 - i])
        {
        }
        else
        {
            if (s[i + 1] == s[i])
            {

                is_ok = false;
                break;
            }
        }
    }
    if (is_ok)
    {
        cin >> s;
        if (!(s[n / 2] == this_c))
        {
            is_ok = false;
        }
        else
        {
            for (int i = 0; i < n / 2; i++)
            {
                if ((s[i] != s[n - 1 - i]) || s[i] == this_c || s[n - 1 - i] == this_c)
                {
                    is_ok = false;
                }
            }
        }
    }
    if (is_ok)
    {
        for (int i = n / 2 + 1; i < n; i++)
        {
            cin >> s;
            if (s[i] == s[n - 1 - i])
            {
            }
            else
            {
                is_ok = false;
                break;
            }
        }
    }

    cout << (is_ok ? "YES" : "NO");
}
