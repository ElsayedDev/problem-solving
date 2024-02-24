#include <bits/stdc++.h>

using namespace std;

int flippingMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size(), result = 0;

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int max_value = max(matrix[i][j], matrix[i][n - 1 - j]);
            max_value = max(max_value, matrix[n - 1 - i][j]);
            max_value = max(max_value, matrix[n - 1 - i][n - 1 - j]);

            result += max_value;
        }
    }

    return result;
}