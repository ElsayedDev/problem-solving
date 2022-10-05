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

    map<char, int> temp = {
        {'A', 0},
        {'B', 0},
        {'C', 0},
    };

    for (int i = 0; i < 3; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        if (b == '>')
        {
            temp[a]++;
        }
        else
        {
            temp[c]++;
        }
    }

    if (temp['A'] == 1 && temp['B'] == 1 && temp['C'] == 1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        if (temp['A'] == 0)
            cout << 'A';
        else if (temp['B'] == 0)
            cout << 'B';
        else if (temp['C'] == 0)
            cout << 'C';

        if (temp['A'] == 1)
            cout << 'A';
        else if (temp['B'] == 1)
            cout << 'B';
        else if (temp['C'] == 1)
            cout << 'C';

        if (temp['A'] == 2)
            cout << 'A';
        else if (temp['B'] == 2)
            cout << 'B';
        else if (temp['C'] == 2)
            cout << 'C';
    }
}
