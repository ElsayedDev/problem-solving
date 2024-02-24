#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<int> arr)
{

    sort(arr.begin(), arr.end());

    int n = arr.size();

    return arr[n / 2];
}

int main()
{

    return 0;
}
