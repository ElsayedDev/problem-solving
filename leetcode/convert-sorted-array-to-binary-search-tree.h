#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int val = nums.size() / 2;
        vector<int> left = {nums.begin(), nums.begin() + val};
        vector<int> right = {nums.begin() + val + 1, nums.end()};

        return new TreeNode(nums[val], sortedArrayToBST(left), sortedArrayToBST(right));
    }
};