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
    int minValue = INT_MAX;
    int prev = -1;

public:
    int getMinimumDifference(TreeNode *root)
    {
        if (root == NULL)
            return minValue;

        getMinimumDifference(root->left);

        if (prev != -1)
            minValue = min(minValue, root->val - prev);

        prev = root->val;

        getMinimumDifference(root->right);

        return minValue;
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
