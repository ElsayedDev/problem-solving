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

    const string temp_1 = "ROYGBIV";
    const string temp_2 = "BIVROYG";
    int n;
    cin >> n;
    string s = "";

    for (int i = 0; i < n; i++)
    {
        int right_digit = i % 10;

        if (right_digit < 7 && n - i > 1)
        {
            s += temp_1[right_digit % 7];
        }
        else if (right_digit >= 7)
        {
            if (n - i > 1)
            {
                const string temp_3 = "ROYG";

                s += temp_3[right_digit % 4];
            }
            else
            {
                s += temp_2[right_digit % 7];
            }
        }
    }

    cout << s << endl;
}
