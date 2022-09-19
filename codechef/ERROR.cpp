#include <bits/stdc++.h>

#define ll long long int

using namespace std;

void first_search(ll t, string p1, string p2)
{
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

void second_search(ll t, string p1, string p2)
{

next:
    while (t--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.length(); i++)
        {
            if (s.substr(i, 2) == p1.substr(0,2))
            {
                if (s.substr(i + 2, p1.length() - 2) == p1.substr(2))
                {
                    cout << "Good" << endl;
                    goto next;
                }
                else
                {
                    i = i + 2;
                }
            }

            else if (s.substr(i, 2) == p2.substr(0,2))
            {
                if (s.substr(i + 2, p2.length() - 2) == p2.substr(2))
                {
                    cout << "Good" << endl;
                    goto next;
                }
                else
                {
                    i = i + 2;
                }
            }
        }

        cout << "Bad" << endl;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    const string p1 = "010";
    const string p2 = "101";

    int t;
    cin >> t;

    second_search(t, p1, p2);
}
