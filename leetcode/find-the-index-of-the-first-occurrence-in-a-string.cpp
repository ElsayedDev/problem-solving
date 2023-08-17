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
    int strStr(string haystack, string needle)
    {
        for (int i = 0; i < haystack.length(); i++)
            if (haystack.substr(i, needle.size()) == needle)
                return i;

        return -1;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    cout << solution.strStr("abc", "c") << endl;

    return 0;
}
