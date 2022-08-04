#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, ans = 0;

        cin >> n;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        while (true)
        {

            if (v.begin() >= v.end() - 1)
            {
                break;
            }
            else
            {
                sort(v.begin(), v.end());

                ans += *(v.end() - 1) - *v.begin();

                v.erase(v.end() - 1);

                v.begin() += ans;
            }
        }
        cout << ans << endl;
    }
}
