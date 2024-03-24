#include <bits/stdc++.h>
using namespace std;

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
}

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int SecretNumber(string s)
{
    int o = 0, x = 0, q = 0;
    for (auto c : s)
    {
        if (c == 'o')
            o++;
        else if (c == 'x')
            x++;
        else if (c == '?')
            q++;
    }

    if (o > 4 || x == 0)
        return 0;

    if (o == 4)
        return 24;

    return fact(o) * fact(q) * q;
}

int main(int argc, const char **argv)
{
    ReadDataWithSpeed();

    string s;
    cin >> s;
    cout << SecretNumber(s);

    return 0;
}
