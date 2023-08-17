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
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];
        int i = 0;
        while (i < s1.length() && i < s2.length())
        {
            if (s1[i] == s2[i])
                i++;
            else
                break;
        }

        return s1.substr(0, i);
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    vector<string> test = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(test) << endl;

    return 0;
}
