#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();

        if (nums[size - 1] == target)
            return size - 1;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == target)
                return i;

            if ((size != i + 1) && (nums[i + 1] < nums[i]) && target > (nums[i] - nums[i + 1]))
                break;
        }

        return -1;
    }
};