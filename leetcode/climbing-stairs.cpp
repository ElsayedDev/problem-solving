#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

class Solution
{

    map<int, int> dp;

    int bt(int x)
    {
        if (dp[x] > 0)
        {
            return dp[x];
        }

        if (x < 0)
            return 0;

        if (x == 0 || x == 1)
            return 1;

        dp[x] = bt(x - 1) + bt(x - 2);

        return dp[x];
    }

public:
    int climbStairs(int n)
    {
        // return bt(n);
        return dp[5];
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();
    cout << solution.climbStairs(10);

    return 0;
}
