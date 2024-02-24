#include <bits/stdc++.h>

using namespace std;

int lonelyinteger(vector<int> a)
{
    int n = a.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result ^= a[i];
    }

    return result;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 5, 6, 6, 7, 2};
    int n = a.size();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result ^= a[i];

        cout << result << endl;
    }

    return 0;
}
