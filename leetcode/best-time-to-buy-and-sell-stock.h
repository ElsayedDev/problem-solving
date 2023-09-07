#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX;
        int diff = 0;
        int dummy = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < min)
                min = prices[i];

            dummy = prices[i] - min;

            if (dummy > diff)
                diff = dummy;
        }

        return diff;
    }
};