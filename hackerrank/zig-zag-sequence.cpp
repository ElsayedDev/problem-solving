#include <bits/stdc++.h>

using namespace std;

int palindromeIndex(string s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            if (s[i + 1] == s[n - i - 1] && s[i + 2] == s[n - i - 2])
                return i;
            else
                return n - i - 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}
