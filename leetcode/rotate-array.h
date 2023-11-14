#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if ((n == 0) || (k <= 0))
            return;

        vector<int> temp(n);
        for (auto element : nums)
            temp.push_back(element);

        for (int i = 0; i < n; i++)
        {
            nums[(k + i) % n] = temp[i];
        }

        for (auto elem : nums)
            cout << elem << endl;
    }
};