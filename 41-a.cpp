#include <bits/stdc++.h>

using namespace std;
int main()
{

    string  s = "ABS" , t;

    cin>>s>>t; 

    do{

        if(t==s){
            cout<<"YES";
            return 0 ;
        }

    }while (next_permutation(s.begin(), s.end()));
    
    cout<<"NO";
    return 0;    
}
    