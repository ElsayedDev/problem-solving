#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long int t;
    cin >> t;

    while (t--)
    {
        int x, y, k;
        long long int n;

        cin >> x >> y >> k >> n;

        bool flag = false;

        if (x >= y)
        {

            for (long long int i = 0; i < n;)
            {
                int p, c;
                cin >> p >> c;

                if (((p + y) >= x) && k >= c)
                {

                    flag = true;
                    break;
                }

                i++;
            }

            if (flag == false)
            {
                cout << "UnluckyChef\n";
            }

            else
            {
                cout << "LuckyChef\n";
            }
        }
    }
}
