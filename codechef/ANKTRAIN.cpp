#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

int main()
{

    ReadDataWithSpeed();

    string arr[8];
    arr[0] = "SL";
    arr[1] = "LB";
    arr[2] = "MB";
    arr[3] = "UB";
    arr[7] = "SU";
    arr[6] = "UB";
    arr[5] = "MB";
    arr[4] = "LB";

    int n, x;
    cin >> n;

    while (n--)
    {
        cin >> x;

        int r = x % 8;

        int out = 0;

        if (r == 7)
        {
            out = (x + 1);
        }
        else if (r == 0)
        {
            out = abs(x - 1);
        }
        else if (r == 3 || r == 2 || r == 1)
        {
            out = (x + 3);
        }
        else if (r == 6 || r == 5 || r == 4)
        {
            out = abs(x - 3);
        }

        cout << out << arr[r] << endl;
    }

    return 0;
}