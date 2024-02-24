#include <bits/stdc++.h>
#define fr(a, b) for (int i = a; i < b; i++)
using namespace std;

#define ll long long int

bool isSubsequence(string s, string t)
{
    for (int i = 0; i < t.size(); i++)
    {
        if (s[0] == t[i])
        {
            s.erase(0, 1);
        }
    }
    return s.size() == 0;
}

int main()
{

    return 0;
};
