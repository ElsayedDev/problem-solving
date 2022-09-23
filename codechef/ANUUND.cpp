#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    	int T;
	
	scanf("%d", &T);
	
	while (T--) {
	    int n;
	    scanf("%d", &n);
	    
	    vector<int> a(n);
	    
	    for (int i = 0; i < n; i++) {
	        scanf("%d", &a[i]);
	    }
	    
	    sort(a.begin(), a.end());
	    
	    int half = (n + 1) / 2;
	    
	    for (int i = 0; i < half; i++) {
	        printf("%d ", a[i]);
	        if (i + half < n) {
	            printf("%d ", a[i + half]);
	        }
	    }
	    printf("\n");
	}

    // ll t;
    // cin >> t;

    // while (t--)
    // {
    //     ll n;
    //     cin >> n;

    //     ll arr[n];

    //     for (ll i = 0; i < n; i++)
    //     {
    //         cin >> arr[i];
    //     }
    //     // sort arr by even and odd
    //     sort(arr, arr + n, [](ll a, ll b)
    //          { return (a <= b && (a % 2 == 0)); });

    //     for (ll i = 0; i < n; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }
}
