#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    int a = c1 - r1 + d1 - r1;
    int C = c1 - r2 + d2 - r2;

    cout << a << endl
         << C << endl;
}

/*

 */