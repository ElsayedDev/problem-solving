#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
private:
    string extend(string s, int i, int j)
    {
        for (; 0 <= i && j < s.length(); i--, j++)
        {
            if (s[i] != s[j])
                break;
        }
        return s.substr(i + 1, j - i - 1);
    }

public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len < 2)
            return s;
        string max = "";
        for (int i = 0; i < s.length(); i++)
        {
            string s1 = extend(s, i, i), s2 = extend(s, i, i + 1);
            if (s1.length() > max.length())
                max = s1;
            if (s2.length() > max.length())
                max = s2;
        }
        return max;
    }
};