#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, t;
    cin >> n >> t;

    if (n == 1 && t >= 10)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout<<t;
        
        int end = n-2;
        if(t <10){
            end = n-1;
        }
        for (long long int i = 0; i <  end; i++)
        {
            cout<<0;
        }
        

    }
}