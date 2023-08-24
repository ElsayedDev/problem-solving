#include <bits/stdc++.h>
#include "common.h"

#include "balanced-binary-tree.h"

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

    vector<int> v = {-10, -3, 0, 5, 9};

    solution.isBalanced(p);

    return 0;
}
