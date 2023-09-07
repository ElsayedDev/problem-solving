#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> ref(256, -1);
        int maxLen = 0, start = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (ref[s[i]] > start)
                start = ref[s[i]];

            ref[s[i]] = i;

            maxLen = max(maxLen, i - start);
        }
    }
};