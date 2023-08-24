#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
    int depth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
    
        return max(depth(root->left), depth(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int left = depth(root->left);
        int right = depth(root->right);

        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};