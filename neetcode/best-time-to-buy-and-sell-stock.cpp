#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = INT_MAX;
        int max = 0;
        for (auto element : prices)
        {
            if (min > element)
            {
                min = element;
            }

            else if (element - min > max)
            {
                max = element - min;
            }
        }

        return max;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
