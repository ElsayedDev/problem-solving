#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, a, ans = 0;
    cin >> n >> a;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // in case the position i have had a 1
    if (arr[a - 1])
    {
        ans++;
    }

    int distance = 1;
    // left & right of my position
    for (int i = a; i < n; i++)
    {
        int left_index = a - distance - 1;

        if (left_index < 0)
        {
            break;
        }


        if (arr[i] && arr[left_index])
        {
            ans++;
        }

        distance++;
    }

    // remain positions

}

/*

    1 2 3 4 5 6 7 8 9
    4 3 2 1 0 1 2 3 4

 */