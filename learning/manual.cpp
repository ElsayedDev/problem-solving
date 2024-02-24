#include <bits/stdc++.h>
#define fr(a, b) for (int i = a; i < b; i++)
using namespace std;

#define ll long long int
int dp[10000];

int main()
{

    int n = 10000;
    vector<int> dp(n + 1, 0);

    fr(1, n + 1)
    {
        dp[0] = 1;
        for (int j = 1; j <= 6; j += i)
        {
            if (j > i)
                break;

            dp[i] += dp[i - j];
        }
    }

    return 0;
};
