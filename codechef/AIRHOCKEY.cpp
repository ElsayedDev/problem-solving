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
        int a, b;
        cin >> a >> b;
        cout << min(7 - a, 7 - b) << endl;
    }
}
