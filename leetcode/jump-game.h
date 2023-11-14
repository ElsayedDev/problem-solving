#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        // if (*(nums.end() - 1) != nums.size())
        //     return false;

        int steps_needed = 1;

        // reverse loop on nums with index
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] >= steps_needed)
            {
                steps_needed = 1;
            }
            else
            {
                steps_needed++;
            }
        }
        cout << steps_needed << endl;

        if (steps_needed > nums[0])
            return false;

        return true;
    }
};