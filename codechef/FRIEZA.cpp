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

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            int count = 1;
            if (s[i] == '0')
            {
                continue;
            }
            else
            {
                for (int j = i + 1; j < s.length(); j++)
                {
                    if (s[i] == s[j])
                    {
                        count++;

                        s.erase(s.begin() + i);
                    }
                }
            }
            s[i] = count + '0';
        }
        cout << s << endl;
    }
}
