#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;

    cin >> n;

    int a[n], b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    copy(a, a + n, b);

    sort(b, b + n);

    for (int i = 0; i < n; i++)
    {
        auto itr = find(a, a + n, b[i]);

        cout << distance(a, itr) + 1 << " ";
    }
}
