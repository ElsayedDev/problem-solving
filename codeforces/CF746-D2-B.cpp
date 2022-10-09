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

    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;

    while (n)
    {
        if (n % 2 == 0)
        {
            ans += s[n / 2 - 1];
            // ans += "_";
            s.erase(s.begin() + (n / 2 - 1));
        }
        else

        {
            ans += s[n / 2 + 1];
            if (n != 1)
            {

                s.erase(s.begin() + (n / 2 + 1));
            }
        }
        n--;
    }
    cout << ans << endl;
}
