#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

string rearrange(string s, string stack)
{
    string ans = stack;

    if (s[1] == '>')
    {
        ans += s[2];
        ans += s[0];
    }
    else
    {
        ans += s[0];
        ans += s[2];
    }
    return ans;
}

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s[3], ans = "";

    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 3; i++)
    {
        ans = rearrange(s[i], ans) + " ";
    }

    vector<string> sol;

    for (int i = 1; i < 2; i++)
    {
        for (int j = i * 3; j < ans.length(); j += 3)
        {

            if (ans[i * 3] == ans[j + 1])
            {
                string res = "";
                res += ans[j];
                res += ans[i * 3];
                res += ans[i * 3 + 1];
                sol.push_back(res);
            }
            else if ((ans[i * 3 - 1] == ans[j + 2]) && (ans[i * 3 + 1] != ans[j + 1]))
            {
                string res = "";
                res += ans[i * 3];
                res += ans[i * 3 + 1];
                res += ans[j + 1];
                sol.push_back(res);
            }
        }
    }

    if (sol.size() >= 1)
    {
        for (int i = 0; i < sol.size() - 1; i++)
        {
            if (sol[i] != sol[i + 1])
            {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        cout << sol[0] << endl;
        return 0;
    }
    else
    {
        cout << "Impossible" << endl;
        return 0;
    }
}


//