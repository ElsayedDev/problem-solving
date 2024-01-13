#include <bits/stdc++.h>
#include "common.h"
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
            {
                int start = nums[i];
                while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
                {
                    i++;
                }
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
            else
            {
                result.push_back(to_string(nums[i]));
            }
        }

        return result;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    /// convert [4,2,7,1,3,6,9] to tree
    TreeNode *root = new TreeNode(4,
                                  new TreeNode(2,
                                               new TreeNode(1),
                                               new TreeNode(3)),
                                  new TreeNode(7,
                                               new TreeNode(6),
                                               new TreeNode(9)));

    // TreeNode *inverted = solution.invertTree(root);

    return 0;
}
