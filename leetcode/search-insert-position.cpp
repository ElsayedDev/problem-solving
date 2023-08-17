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
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] > target)
                right = mid;

            else
                left = mid + 1;
        }

        return nums[left] < target ? left + 1 : left;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    vector<int> data = {1, 3, 5, 6};
    cout << solution.searchInsert(data, 2) << endl;

    return 0;
}
