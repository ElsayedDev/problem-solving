#include <bits/stdc++.h>

using namespace std;
int main()
{

    string s, task, l, r;
    cin >> s;

    int cross = s.find('|');
    l = s.substr(0, cross);
    r = s.substr(cross + 1);

    cin >> task;

    for (auto it : task)
    {
        if (l.size() <= r.size())
        {
            l += it;
        }
        else
        {
            r += it;
        }
    }

    cout << (l.size() == r.size() ? l + '|' + r : "Impossible");
}
