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

void algorithm1(int a, int b, int *counter)
{

    while (a != b)
    {

        if (a > 1)
        {
            a /= 2;
            *counter++;
        }

        if (b > 1)
        {
            b /= 2;
            *counter++;
        }
    }
}

void algorithm2(int a, int b, int *counter)
{

    // counter right & left

    vector<int> aV;
    vector<int> bV;

    while (a > 0)
    {
        aV.push_back(a);
        a /= 2;
    }

    while (b > 0)
    {
        bV.push_back(b);
        b /= 2;
    }

    // check double side

    int aSize = aV.size();
    int bSize = bV.size();

    int x = 0;
    for (int i = 0; i < min(aSize, bSize); i++)
    {
        if (aV[aSize - i - 1] != bV[bSize - i - 1])
        {
            break;
        }
        else
        {
            x += 2;
        }
    }

    *counter = aSize + bSize - x;
}

int main()
{
    ReadDataWithSpeed();

    int t, counter;
    cin >> t;
    while (t--)
    {
        counter = 0;

        int a, b;
        cin >> a >> b;

        algorithm2(a, b, &counter);

        cout << counter << endl;
    }

    return 0;
}