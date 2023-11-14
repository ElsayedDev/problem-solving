#include <bits/stdc++.h>
#include "common.h"

#include "jump-game.h"

using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
}

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    TreeNode *p = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    vector<int> v = {2, 3, 1, 1, 4};

    bool f = solution.canJump(v);
    // cout << out << endl;

    // for (auto element : v)
    // {
    //     cout << element << endl;
    // }
    return 0;
}
