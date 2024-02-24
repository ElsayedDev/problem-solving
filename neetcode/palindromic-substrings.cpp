#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += countPalindromes(s, i, i);     // odd length
            count += countPalindromes(s, i, i + 1); // even length
        }
        return count;
    }
};

int main()
{

    return 0;
}

/*

    circle: to connection (not allowed)



 */