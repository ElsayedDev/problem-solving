#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l, r = height.size() - 1, maxArea = 0;

        while (l < r)
        {
            if (height[l] >= height[r])
                maxArea = max(maxArea, height[r] * (r - l)), r -= 1;

            else
                maxArea = max(maxArea, height[l] * (r - l)), l -= 1;
        }

        return maxArea;
    }
};