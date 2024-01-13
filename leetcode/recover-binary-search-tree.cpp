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
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left != NULL && root->left->val >= root->val)
            swap(root->left, root);

        if (root->right != NULL && root->right->val <= root->val)
            swap(root->right, root);

        recoverTree(root->left);
        recoverTree(root->right);
    }

    // swap between two nodes
    void swap(TreeNode *a, TreeNode *b)
    {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
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
