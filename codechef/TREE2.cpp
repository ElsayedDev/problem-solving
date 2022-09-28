#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int main()
{
    SPEED
    
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        set<int> se;
        
        for (int i = 0; i < n; i++)
        {
            
            cin >> arr[i];
            if (arr[i] > 0)
                se.insert(arr[i]);
        }
        cout << se.size() << endl;
    }
}
