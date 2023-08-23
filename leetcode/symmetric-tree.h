#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }

    bool isSymmetricHelp(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
            return left == right;

        if (left->val != right->val)
            return false;

        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};