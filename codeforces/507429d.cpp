#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << "no" << endl;
            break;
        }

        vector<int> l;

        vector<int> r;

        int mid;

        for (int i = 0; i < n / 2; i++)
        {
            int x;
            cin >> x;
            l.push_back(x);
        }

        cin >> mid;

        if (mid != 7)
        {
            cout << "no" << endl;
            break;
        }

        for (int i = n / 2 + 1; i < n; i++)
        {
            int x;
            cin >> x;
            r.push_back(x);
        }

        int flag = false;

        for (int i = 0; i < n / 2; i++)
        {
            if (i > 0)
            {
                if ((l[i] - l[i - 1]) != 1 && (l[i] - l[i - 1]) != 0)
                {
                    flag = true;
                    break;
                }
            }

            if (l[i] != r[n / 2 - i - 1] || l[i] >= 7 || r[n / 2 - i - 1] >= 7 || l[i] <= 0 || r[n / 2 - i - 1] <= 0 )
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "no" << endl;
        }

        else
        {
            cout << "yes" << endl;
        }
    }
}