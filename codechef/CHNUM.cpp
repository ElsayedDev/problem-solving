#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int pos_counter = 0, neg_counter = 0, x;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x > 0)
            {
                pos_counter++;
            }
            else
            {
                neg_counter++;
            }
        }
        if (pos_counter == 0)
        {
            pos_counter = neg_counter;
        }

        if (neg_counter == 0)
        {
            neg_counter = pos_counter;
        }
        cout << max(pos_counter, neg_counter) << " " << min(pos_counter, neg_counter) << endl;
    }
}
