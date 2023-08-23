#include <bits/stdc++.h>
#include "common.h"

#include "maximum-depth-of-binary-tree.h"

using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    TreeNode *p = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    solution.maxDepth(p);

    return 0;
}
