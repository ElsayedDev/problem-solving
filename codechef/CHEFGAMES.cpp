#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    while (n--)
    {
        int r1, r2, r3, r4;
        cin >> r1 >> r2 >> r3 >> r4;

        if (r1 + r2 + r3 + r4)
        {
            cout << "OUT" << endl;
        }
        else
        {
            cout << "IN" << endl;
        }
    }
}
