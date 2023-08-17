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

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int unique = 1;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1])
                nums[unique++] = nums[i];

        return unique;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    vector<int> data = {1, 1, 2};
    cout << solution.removeDuplicates(data) << endl;

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}
