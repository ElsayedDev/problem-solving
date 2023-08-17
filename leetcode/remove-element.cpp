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
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                nums[index++] = nums[i];

        return index;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    vector<int> data = {3, 2, 2, 3};
    cout << solution.removeElement(data, 3) << endl;

    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }

    return 0;
}
