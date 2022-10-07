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

    const string temp = "ROYGBIV";
    int n;
    cin >> n;
    string s = "";
    int index = 0;
    int fraction = 7;
    for (int i = 0; i < n; i++)
    {
        if (i % (fraction + 1) == fraction)
        {
            fraction = (fraction - 1) / 2;
            index = fraction;
        }
        else
        {
            index = i % 7;
        }

        s += temp[index];
    }

    cout << s << endl;
}
