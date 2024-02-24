#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> ref(128, -1);

        // st => start of the substring
        int max = 0, st = -1, n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (ref[s[i]] > st)
                st = ref[s[i]];

            ref[s[i]] = i;

            max = std::max(max, i - st);
        }

        return max;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
