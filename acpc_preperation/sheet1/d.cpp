#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

// int SquaredError1(int n)
// {

//     long long sum = 0;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {

//         cin >> arr[i];

//         sum += (n - 1) * arr[i] * arr[i];
//     }

//     // cout << "sum FIRST: " << sum << endl;

//     int loop = 1;
//     while (loop < n)
//     {
//         int sum2 = 0;
//         for (int i = loop; i < n; i++)
//             sum2 += arr[i];

//         sum += -2 * arr[loop - 1] * sum2;

//         // cout << "sum SECOND: " << sum2 << endl;

//         loop++;
//     }

//     // cout << "Total: " << sum << endl;
//     return sum;
// }

int SquaredError2(int n)
{
    int prod = 0, sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        prod += (n - 1) * x * x;
        prod += -2 * x * (sum - x);
    }

    // cout << prod << endl;
    return prod;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int n;
    cin >> n;
    cout << SquaredError2(n);
}
