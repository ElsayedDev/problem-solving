#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    int majorityElement(vector<int> &nums)
    {
        map<int, Node> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]].value++;

        int max = 0;
        for (auto element : m)
            if (element.second.value > max)
                max = element.first;

        return max;
    }

    struct Node
    {
        int value = 0;
    };
};