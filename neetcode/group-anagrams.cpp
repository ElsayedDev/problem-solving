#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }

        for (auto it = mp.begin(); it != mp.end(); it++)
            res.push_back(it->second);

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