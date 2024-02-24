#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
                return i;

            if ((n != i + 1) && (nums[i + 1] < nums[i]) && target > (nums[i] - nums[i + 1]))
                break;
        }

        if (nums[n - 1] == target)
            return n - 1;

        return -1;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
