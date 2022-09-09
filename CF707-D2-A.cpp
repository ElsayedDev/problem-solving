#include <bits/stdc++.h>

using namespace std;

bool isColor(char c)
{

    switch (c)
    {
    case 'C':
    case 'M':
    case 'Y':
        return true;

    default:
        return false;
        break;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int arr[m];

    while (n--)
    {
        for (int i = 0; i < m; i++)
        {
            char c;
            cin >> c;
            if (isColor(c))
            {
                cout << "#Color";
                return 0;
            }
        }
    }

    cout << "#Black&White";
    return 0;
}


//