#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    bool flag = false;

    set<char> se;

    if (s.length() >= 26)
    {

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                char x = s[i] + 'a' - 'A';
                se.insert(x);
            }
            else
            {
                se.insert(s[i]);
            }
        }
    }

    if (se.size() == 26)
    {
        flag = true;
    }

    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}