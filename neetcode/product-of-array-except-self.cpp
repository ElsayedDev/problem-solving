#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
private:
    map<int, int> mp;
    int product(vector<int> &nums)
    {
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            res *= nums[i];
        }
    }

public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        int l = 1, r = 1;

        for (int i = 0; i < n; i++)
        {
            res[i] *= l;
            l *= nums[i];
            res[n - i - 1] *= r;
            r *= nums[n - i - 1];
        }

        return res;
    }
};

/*

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

      int total = 1, n = nums.size();
        bool flag = false;

        vector<int> res(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                res[i] == 1;
                flag = true;
            }

            else
                total *= nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (flag)
            {
                if (nums[i] == 1)
                    res[i] = total;
            }
            else
            {
                res[i] = total / nums[i];
            }
        }

        return res;

 */