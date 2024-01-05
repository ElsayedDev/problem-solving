#include <bits/stdc++.h>
#include "common.h"
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {

                if (grid[i][j] == 1)
                {
                    perimeter += 4;

                    if (i > 0 && grid[i - 1][j] == 1)
                    {
                        perimeter -= 2;
                    }

                    if (j > 0 && grid[i][j - 1] == 1)
                    {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    /// convert [4,2,7,1,3,6,9] to tree
    TreeNode *root = new TreeNode(4,
                                  new TreeNode(2,
                                               new TreeNode(1),
                                               new TreeNode(3)),
                                  new TreeNode(7,
                                               new TreeNode(6),
                                               new TreeNode(9)));

    // TreeNode *inverted = solution.invertTree(root);

    return 0;
}
