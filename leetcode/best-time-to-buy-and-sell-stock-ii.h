#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, n = prices.size() - 1, buy, sell, res = 0;

        while (i < n)
        {
            while (i < n && prices[i + 1] <= prices[i])
                i++;
            buy = prices[i];

            cout << "buy> i: " << i << " price: " << prices[i] << endl;

            while (i < n && prices[i + 1] > prices[i])
                i++;
            sell = prices[i];

            cout << "sell> i: " << i << " price: " << prices[i] << endl;

            res += sell - buy;
        }
        return res;
    }
};