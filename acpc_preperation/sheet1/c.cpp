#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

long long PlaySnuke(int n)
{
    long long mn = INT_MAX;

    while (n--)
    {
        long long a, p, x;
        cin >> a >> p >> x;
        if (x - a > 0)
            mn = min(mn, p);
    }

    return mn == INT_MAX ? -1 : mn;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int n;
    cin >> n;
    cout << PlaySnuke(n);

    return 0;
}
