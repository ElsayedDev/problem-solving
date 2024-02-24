#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (mp.find(diff) != mp.end())
                return {mp[diff], i};

            // mp[nums[i]] = i;
        }

        return {};
    }
};
;

int main()
{

    return 0;
}

/*

    circle: to connection (not allowed)



 */