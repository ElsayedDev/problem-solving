#include <bits/stdc++.h>

using namespace std;
int main()
{

    string s;
    cin >> s;
    string ans="";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '+')
        {
            ans.push_back(s[i]);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] ;
        if (i != ans.size() - 1)
        {
            cout << "+";
        }
    }
}
