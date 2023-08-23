#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int maxRight = 1 + maxDepth(root->right);
        int maxLeft = 1 + maxDepth(root->left);

        return max(maxLeft, maxRight);
    }
};