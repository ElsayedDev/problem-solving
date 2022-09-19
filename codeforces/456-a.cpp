#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long int n, ans = 0;
    cin >> n;

    for (long long int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        if (a < b)
        {
            ans++;
        }
    }
    if (n % 2 != 0)
    {
        cout << (ans > (n / 2) ? "Happy Alex" : "Poor Alex");
    }
    else    
    {
        cout << (ans >= (n / 2) ? "Happy Alex" : "Poor Alex");
    }
}
