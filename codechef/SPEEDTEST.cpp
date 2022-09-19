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
        int a, x, b, y;
        cin >> a >> x >> b >> y;

        double f = (a * 1.0 / x * 1.0);
        double s = (b * 1.0 / y * 1.0);


        if (f == s)
        {
            cout << "Equal" << endl;
        }
        else if (f > s)
        {
            cout << "Alice" << endl;
        }
        else
        {
            cout << "Bob" << endl;
        }
    }
}
