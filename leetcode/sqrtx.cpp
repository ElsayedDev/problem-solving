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

public:
    int mySqrt(int x)
    {
        if (x < 2)
            return x;

        int left = 0, right = x;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            int temp = x / mid;
            if (temp == mid)
                return mid;

            else if (temp < mid)
                right = mid;

            else
                left = mid + 1;
        }
        return left - 1;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();
    cout << solution.mySqrt(10);

    return 0;
}
