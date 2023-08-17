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
    map<char, int> rd = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s)
    {

        int sum = 0;

        for (int i = s.length(); i >= 0; i--)
        {
            if (rd[s[i - 1]] < rd[s[i]])
            {
                sum += (rd[s[i]] - rd[s[i - 1]]);
                i--;
            }
            else
            {
                sum += rd[s[i]];
            }
        }

        return sum;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    cout << solution.romanToInt("IV") << endl;

    return 0;
}
