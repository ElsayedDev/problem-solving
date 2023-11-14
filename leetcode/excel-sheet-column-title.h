#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;
        while (columnNumber > 0)
        {
            columnNumber--;
            int current = columnNumber % 26;
            res.push_back(current + 'A');
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};