#include <bits/stdc++.h>

#define ll long long int

using namespace std;




int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    const string p1 = "010";
    const string p2 = "101";

    int t;
    cin >> t;

next:
    while (t--)
    {
        string s;
        cin >> s;

        // linear search
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (s.substr(i, 3) == p1 || s.substr(i, 3) == p2)
            {
                cout << "Good" << endl;
                goto next;
            }
        }

        cout << "Bad" << endl;
    }
}
