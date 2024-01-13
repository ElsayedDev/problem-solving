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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
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
