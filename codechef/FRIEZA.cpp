#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    map<char, bool> r = {
        {'f', true},
        {'r', true},
        {'i', true},
        {'e', true},
        {'z', true},
        {'a', true},
    };

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int in_r_counter = 0, not_in_r_counter = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (r[s[i]])
            {
                if (in_r_counter == 0 && not_in_r_counter != 0)
                {
                    cout << not_in_r_counter;
                    not_in_r_counter = 0;
                }
                in_r_counter++;
            }
            else
            {
                if (not_in_r_counter == 0 && in_r_counter != 0)
                {
                    cout << in_r_counter;
                    in_r_counter = 0;
                }
                not_in_r_counter++;
            }
        }
        if (not_in_r_counter != 0)
            cout << not_in_r_counter;
        
        if (in_r_counter != 0)
            cout << in_r_counter;

        cout << endl;
    }
}
