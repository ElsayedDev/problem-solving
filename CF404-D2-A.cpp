#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    set<char> se;
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {

            se.insert(s[i]);
        }
    }

    if (se.size() > 2 || se.size() == 1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
}
