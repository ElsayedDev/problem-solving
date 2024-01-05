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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {

            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr ? root->left->val : 0);
        }
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
