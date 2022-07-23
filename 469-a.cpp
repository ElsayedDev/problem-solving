#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    set<int> se;

    for (int i = 0; i < 2; i++)
    {
        int f;
        cin >> f;
        for (int i = 0; i < f; i++)
        {
            int x;
            cin >> x;
            se.insert(x);
        }
    }

    if (se.size() == n)
    {
        cout << "I become the guy.";
    }
    else
    {
        cout << "Oh, my keyboard!";
    }
}
