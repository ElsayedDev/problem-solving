#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] > nums[h])
                l = mid + 1;

            else
                h = mid;
        }

        return nums[l];
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
