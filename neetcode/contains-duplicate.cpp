#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[nums[i]])
                return true;

            mp[nums[i]] = true;
        }

        return false;
    }
};

int main()
{

    return 0;
}

/*

    circle: to connection (not allowed)



 */