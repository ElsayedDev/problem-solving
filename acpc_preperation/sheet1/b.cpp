#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

int Unexpressed(int n)
{
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        int x = i * i;
        while (x <= n)
        {
            count++;
            x *= i;
        }
    }
    return n - count;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int n;
    cin >> n;
    cout << Unexpressed(n);

    return 0;
}
