#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string pattern1[4] = {"####", "###", "##", "#"};
    string pattern2[4] = {"....", "...", "..", "."};

    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    string data[4] = {s1, s2, s3, s4};

    for (int i = 0; i < 3; i++)
    {
        string *pat;

        string total = data[i] + data[i + 1];

        int total_count = count(total.begin(), total.end(), '#');

        if (total_count != 4)
        {
            cout << "YES";
            return 0;
        }
        else
        {
            string total2 = data[i + 1] + data[i];

            if (total == total2)
            {
                cout << "YES";
                return 0;
            }
            if (total.find(pattern1[3]) || total2.find(pattern1[3]) || total.find(pattern2[3]) || total2.find(pattern2[3]))
            {
                cout << "YES";
                return 0;
            }

            // else
            // {
            //     if (data[i].find(pattern1[2]))
            //         pat = pattern1;
            //     else if (data[i].find(pattern2[2]))
            //         pat = pattern2;
            //     else
            //         continue;

            //     string need = "";
            //     if (data[i] == pat[0])
            //         need = pat[3];

            //     else
            //         need = pat[2];

            //     if (data[i + 1].find(need))
            //     {
            //         cout << "YES";
            //         return 0;
            //     }
            // }
        }
    }

    cout << "NO";
    return 0;
}
