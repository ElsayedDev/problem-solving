#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int fib(int n)
{
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{

    return 0;
};
