#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        int longestStreak = 0;
        for (int num : s)
        {
            if (s.find(num - 1) == s.end())
            {

                int currentNum = num;
                int currentStreak = 1;

                while (s.find(currentNum + 1) != s.end())
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};

int main(int argc, char const *argv[])
{

    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;
    s.longestConsecutive(nums);

    return 0;
}
