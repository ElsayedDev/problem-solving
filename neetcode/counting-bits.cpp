#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;

        // iterating from 0 to n
        for (int i = 0; i <= n; i++)
        {
            // sum is initialised as 0
            int sum = 0;
            int num = i;
            // while num not equals zero
            while (num != 0)
            {
                // we have to count 1's in binary representation of i, therefore % 2
                sum += num % 2;
                num = num / 2;
            }
            // add sum to ans vector
            ans.push_back(sum);
        }
        // return
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> ans = sol.countBits(9);
    for (auto element : ans)
    {
        cout << element << " ";
    }
    return 0;
}

/*
1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 110
7 -> 111 (n & n - 1)
8 -> 1000


 */