#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

bool RollingDice(int times, int target)
{
    if ((target * 1.0 / times * 1.0) <= 6.0 && target >= times)
        return true;

    return false;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int a, b;
    cin >> a >> b;
    cout << (RollingDice(a, b) ? "Yes" : "No");

    return 0;
}
