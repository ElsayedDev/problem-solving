#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        priority_queue<pair<int, int>> pq;
        for (auto element : mp)
            pq.push({element.second, element.first});

        vector<int> res;
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

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