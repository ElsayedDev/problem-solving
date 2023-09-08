#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    int reverse(int x)
    {
        long long int res = 0;

        while (x != 0)
        {
            long long int v = x % 10;
            long long int r = res * 10 + v;

            if ((r - v) / 10 != res)
                return 0;

            res = r;
            x /= 10;
        }

        return (res > 0 && res > INT_MAX) || (res < 0 && res < INT_MIN) ? 0 : res;
    }
};