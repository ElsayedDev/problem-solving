#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{

public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        if (p == nullptr || q == nullptr)
        {
            return true;
        }
        else
        {
            return ((p->val == q->val)) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        }
    }
};

int main()
{
    ReadDataWithSpeed();

    // make ListNode of [1,2,4]
    Solution solution = Solution();

    TreeNode *p = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    auto out = solution.isSameTree(p, q);

    cout << out << endl;

    return 0;
}
