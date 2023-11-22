#include <bits/stdc++.h>
#include "common.h"
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {

        int steps_needed = 0;

        // reverse loop on nums with index
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] > steps_needed)
            {
                // cout << nums[i] << " " << steps_needed << endl;

                steps_needed = nums[i] - steps_needed;
            }
            else
            {
                steps_needed++;
            }
        }

        return steps_needed + 1;
    }
};