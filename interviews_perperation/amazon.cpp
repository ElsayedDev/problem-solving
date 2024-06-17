#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}

int digitSquareSum(int n)
{
    int sum = 0, tmp;

    while (n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int fast = n, slow = n;

    do
    {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(digitSquareSum(fast));
    } while (fast != slow);

    if (slow == 1)
        return true;

    return false;
}

int main(int argc, char const *argv[])
{
    ReadDataWithSpeed();

    int n;
    cin >> n;

    cout << isHappy(n);

    return 0;
}
