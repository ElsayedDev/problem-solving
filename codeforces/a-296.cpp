#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin >> n;
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    bool valid = true;

    for (const auto &it : m)
    {
        if (n < (2 * it.second + 1))
        {
            valid = false;
            break;
        }
    }
    if (valid)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
