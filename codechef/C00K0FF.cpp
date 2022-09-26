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

    ll t;
    cin >> t;

    map<string, int> temp = {
        {"cakewalk", 0},
        {"simple", 1},
        {"easy", 2},
        {"easy-medium", 3},
        {"medium", 3},
        {"medium-hard", 4},
        {"hard", 4},
    };

    while (t--)
    {
        ll arr[5];
        memset(arr, 0, sizeof(arr));

        ll n;
        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            arr[temp[s]]++;
        }

        if (arr[0] >= 1 && arr[1] >= 1 && arr[2] >= 1 && arr[3] >= 1 && arr[4] >= 1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
