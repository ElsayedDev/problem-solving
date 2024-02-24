#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                s[i] = (s[i] - 'A' + k) % 26 + 'A';
            }
            else
            {
                s[i] = (s[i] - 'a' + k) % 26 + 'a';
            }
        }
    }

    return s;
}

int main()
{
    cout << caesarCipher("abcde", 2) << endl;

    return 0;
}
