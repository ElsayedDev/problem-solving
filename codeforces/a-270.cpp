#include <bits/stdc++.h>

using namespace std;
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        float x = 2.0 / (1.0 - a / 180.0);

        bool check = (((int)round(x * 100)) % 100) != 0;
        if (check)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
