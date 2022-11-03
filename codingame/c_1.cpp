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

    ll ans = 0;
    int n;
    cin >> n;
    cin.ignore();

    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            mat[i][j] = value;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == (j - 1))
            {

                for (int k = j; k < n; k++)
                {
                    ans += mat[i][k];
                }

                break;
            }
        }
    }

    cout << ans << endl;
}