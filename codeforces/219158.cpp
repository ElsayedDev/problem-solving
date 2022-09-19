#include <bits/stdc++.h>

using namespace std;
int main()
{

    long long int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((b * logl(a)) > (d * logl(c)))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
