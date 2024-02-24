#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long int> arr = {1, 3, 9, 7, 5};

    sort(arr.begin(), arr.end());

    long long int n = arr.size();

    long long int sum = 0;
    for (long long int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }

    cout << sum << " ";
    sum = 0;

    for (long long int i = 1; i < n; i++)
    {
        sum += arr[i];
    }

    cout << sum;

    return 0;
}
