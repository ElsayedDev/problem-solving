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
    const char *ws = " \t\n\r\f\v";

public:
    int lengthOfLastWord(string s)
    {
        if (s.empty())
            return 0;

        int count = 0, right = s.length() - 1;

        while (right >= 0 && s[right] == ' ')
            right--;

        if (right == s.length() - 1)
        {
            return s.length();
        }

        while (right > 0 && s[right] != ' ')
        {
            count++;
            right--;
        }

        return count == 0 ? 1 : count;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    cout << solution.lengthOfLastWord("Hello world") << endl;

    return 0;
}
