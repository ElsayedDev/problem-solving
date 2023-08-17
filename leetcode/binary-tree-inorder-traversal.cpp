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

    vector<int> inOrder(TreeNode *root)
    {

        if (root == nullptr)
        {
            return {};
        }

        vector<int> left = inOrder(root->left);
        vector<int> right = inOrder(root->right);
        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        return inOrder(root);
    }
};

int main()
{
    ReadDataWithSpeed();

    // make ListNode of [1,2,4]
    Solution solution = Solution();

    TreeNode *data = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    auto out = solution.inorderTraversal(data);

    for (auto element : out)
    {
        cout << element << endl;
    }

    return 0;
}
