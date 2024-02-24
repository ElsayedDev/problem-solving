#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{

public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        if (n == 1)
            return s;

        string res = "";
        int max_len = 0;

        for (int i = 0; i < n; i++)
        {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > max_len)
                {
                    max_len = r - l + 1;
                    res = s.substr(l, max_len);
                }
                l--;
                r++;
            }

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > max_len)
                {
                    max_len = r - l + 1;
                    res = s.substr(l, max_len);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}

/*

    circle: to connection (not allowed)



 */