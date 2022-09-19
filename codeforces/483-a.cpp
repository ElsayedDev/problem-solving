
#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int a, b;
    cin >> a >> b;

    if (a % 2 != 0)
    {
        a++;
    }
    if (abs(a - b) < 2)
    {
        cout << -1;
    }
    else
    {

        cout << a << " " << (a + 1) << " " << (a + 2);
    }
}