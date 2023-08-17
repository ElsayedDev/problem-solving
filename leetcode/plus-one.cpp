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
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }
        vector<int> nininininini(digits.size() + 1);
        nininininini[0] = 1;
        return nininininini;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();
    vector<int> data = {1, 2, 9};
    auto result = solution.plusOne(data);

    for (auto element : result)
    {
        cout << element << endl;
    }

    return 0;
}
