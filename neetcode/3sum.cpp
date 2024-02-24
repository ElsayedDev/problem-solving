#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++)
        {
            // bad case
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // find low

            int low = i + 1, high = nums.size() - 1, sum = 0;

            while (low < high)
            {
                sum = nums[i] + nums[low] + nums[high];
                if (sum < 0)
                {
                    low++;
                }
                else if (sum > 0)
                {
                    high--;
                }
                else if (sum == 0)
                {
                    res.push_back({nums[i], nums[low], nums[high]});
                    // for the sam i but try other sol
                    int last_low = nums[low], last_high = nums[high];

                    while (low < high && nums[low] == last_low)
                        low++;
                    while (low < high && nums[high] == last_high)
                        high--;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
