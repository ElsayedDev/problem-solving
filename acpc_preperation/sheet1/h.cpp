#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

int FactorialYenCoin(int p)
{
    int coins[11] = {};
    coins[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        coins[i] = coins[i - 1] * i;
    }

    int ans = 0;
    for (int i = 10; i >= 0; i--)
    {
        ans += p / coins[i];
        p %= coins[i];
    }

    return ans;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int p;
    cin >> p;
    cout << FactorialYenCoin(p);

    return 0;
}
