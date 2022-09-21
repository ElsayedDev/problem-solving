#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v;
    int ans[n];

    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++)
    {
        ans[i]++;
        // left ro right

        for (int j = i + 1; j != v.size() && ((v[j] <= v[j - 1])); j++)
        {
            ans[i]++;
        }

        // right to left

        for (int j = i - 1; j >= 0 && ((v[j] <= v[j + 1])); j--)
        {
            ans[i]++;
        }
    }

    cout << *max_element(ans, ans + n) << endl;
}