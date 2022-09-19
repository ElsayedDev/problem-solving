#include <bits/stdc++.h>

using namespace std;

int is_prime(int n)
{
    int i, m = 0, flag = 0;

    m = n / 2;
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {

            flag = 1;
            break;
        }
    }
    if (flag == 0)
        return n;
    else
        return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    vector<int> v;

    for (int i = a; i <= b; i++)
    {
        if (is_prime(i) != 0)
        {
            v.push_back(i);
        }
    }
   

    if (v[1] == b)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
