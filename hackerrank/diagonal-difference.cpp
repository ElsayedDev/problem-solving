#include <bits/stdc++.h>

using namespace std;

int diagonalDifference(vector<vector<int>> arr)
{
    int n = arr.size(), d1 = 0, d2 = 0;

    for (int i = 0, j = 0; i < n; i++, j++)
    {
        int second_index = n - 1 - i;

        d1 += arr[j][second_index];
        d2 += arr[j][j];
    }

    return abs(d1 - d2);
}

int main()
{
}
