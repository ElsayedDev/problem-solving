#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (p == nullptr && q == nullptr)
            return true;
        else if (p != nullptr && q != nullptr)
            return ((p->val == q->val)) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);

        else
            return false;
    }
};