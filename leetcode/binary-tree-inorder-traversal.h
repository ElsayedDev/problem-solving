#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        dfs(root, result);
        return result;
    }

private:
    void dfs(TreeNode *node, vector<int> &result)
    {
        if (node == nullptr)
            return;

        dfs(node->left, result);
        result.push_back(node->val);
        dfs(node->right, result);
    }
};
