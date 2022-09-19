#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;
        long long int counter = 0;
        for (long long int i = 0; i < s.length(); i++)
        {
            if (s[i] == '4')
            {
                counter++;
            }
        }

        cout << counter << endl;
    }
}
