#include <bits/stdc++.h>

using namespace std;
int main()
{
    string k = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char a;
    cin >> a;
    string s;
    cin >> s;
    for (auto &b : s)
    {
        for (int i = 0; i < k.length(); i++)
        {
            if (k[i] == b)
            {
                (a == 'R' ? cout << k[i - 1] : cout << k[i + 1]);
            }
        }
    }
}
