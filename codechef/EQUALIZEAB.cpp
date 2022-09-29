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
        ll a, b, x;
        cin >> a >> b >> x;
        ll arr[2] = {abs(b - x), b + x};

        for (int i = 0; i < 2; i++)
        {

            if ((arr[i] == abs(a - x)) || (arr[i] == a + x))
            {
                cout << "YES" << endl;
                break;
            }
            if (i == 1)
            {
                cout << "NO" << endl;
                break;
            }
        }
    }
}
