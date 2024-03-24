#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

bool TinyArithmeticSequence(int arr[3])
{
    sort(arr, arr + 3);

    if (arr[1] - arr[0] == arr[2] - arr[1])
        return true;

    return false;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int arr[3] = {0};
    cin >> arr[0] >> arr[1] >> arr[2];
    cout << (TinyArithmeticSequence(arr) ? "Yes" : "No");

    return 0;
}
