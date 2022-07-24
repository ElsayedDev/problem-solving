
#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int a, b;
    cin >> a >> b;

    if (abs(a - b) < 2)
    {
        cout << -1;
    }
    else
    {
        if (a % 2 == 0)
        {
            a++;
        }

        cout << a << " " << (a + 1) << " " << (a + 2);
    }
}