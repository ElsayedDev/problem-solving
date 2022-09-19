#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> a;
    int temp;
    for (size_t i = 0; i < n; i++)
    {
        cin >> temp;
        a[temp] ++;
    }
    n = n - (*a.begin()).second;
    auto it = a.end();
    it--;
    n = n - (*it).second;
    if (n > 0)
    {
        cout << n;
    }
    else
        cout << 0;
}