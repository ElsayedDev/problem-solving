#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, int> m = {
        {"Tetrahedron", 4},
        {"Cube", 6},
        {"Octahedron", 8},
        {"Dodecahedron", 12},
        {"Icosahedron", 20},
    };
    
    long long int n, ans=0;
    cin>>n;

    while (n--)
    {
        string s; 
        cin>>s;
        ans+=m[s];
    }

    cout<<ans;
    
}
