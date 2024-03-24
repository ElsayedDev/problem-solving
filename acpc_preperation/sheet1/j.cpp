#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

int f(int t)
{
    return t * t + 2 * t + 3;
}

int WeirdFunction(int t)
{
    return f(f(f(t) + t) + f(f(t)));
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int t;
    cin >> t;
    cout << WeirdFunction(t);

    return 0;
}
