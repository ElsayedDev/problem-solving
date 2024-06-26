#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, int> m1;
        unordered_map<string, int> m2;
        istringstream in(s);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i)
        {
            if (i == n || m1[pattern[i]] != m2[word])
                return false;
            m1[pattern[i]] = m2[word] = i + 1;
        }
        return i == n;
    }
};