#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int div = target - nums[i];

            if (numMap.count(div))
                return {numMap[div], i};

            numMap[div] = i;
        }
        return {};
    }
};