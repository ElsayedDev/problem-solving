#include <bits/stdc++.h>
using namespace std;

int r1, r2, c1, c2, d1, d2;
bool checker(int a, int b, int c, int d)
{
    return (a + b == r1 && c + d == r2 && a + c == c1 && b + d == c2 && a + d == d1 && b + c == d2);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    int c = abs((r2 - d1 + c1) / 2);
    int a = c1 - c;
    int b = r1 - a;
    int d = c2 - b;

    if (checker(a, b, c, d) && a * b * c * d > 0 && (a != b && b != d && a != c && c != d && a != d && b != c) && (a <= 9 && b <= 9 && c <= 9 && d <= 9))
    {
        cout << a << " " << b << endl;
        cout << c << " " << d << endl;
    }
    else
    {
        cout << -1;
    }
}
