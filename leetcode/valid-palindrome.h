#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
    string removeSpaces(string str)
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

public:
    bool isPalindrome(string s)
    {
        if (s.empty())
            return true;

        int first = 0;
        int last = s.length() - 1;

        while (first <= last)
        {
            if (!isalnum(s[first]) || s[first] == ' ')
                first++;

            else if (!isalnum(s[last]) || s[last] == ' ')
                last--;

            else
            {
                if (tolower(s[first]) != tolower(s[last]))
                    return false;
                first++;
                last--;
            }
        }

        return true;
    }
};