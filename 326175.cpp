#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin >> n;

    int f1 = n % 10, f2 = n / 10;

    bool condition = f1 % f2 == 0 || f2 % f1 == 0;

    if (condition)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
