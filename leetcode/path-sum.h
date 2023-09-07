#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr && targetSum - root->val == 0)
            return true;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};