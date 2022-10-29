#include <bits/stdc++.h>
 
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
 
#define ll long long int
 
using namespace std;
 
const string temp_arr[3] = {"Carrots", "Kiwis", "Grapes"};
 
int main()
{
    SPEED
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
 
    ll n, m, k, t;
    cin >> n >> m >> k >> t;
 
    map<int, vector<int>> blocks;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        blocks[y].push_back(x);
    }
 
    for (int i = 0; i < t; i++)
    {
 
        int y, x;
        cin >> y >> x;
        int count = 0;
        bool flag = false;
 
        // count blocks
        for (int j = y; j > 0; j--)
        {
 
            if (j != y)
            {
                count += blocks[j].size();
            }
            else
            {
                for (int jk = 0; jk < x && jk < blocks[j].size(); jk++)
                {
                    if (blocks[j][jk] == x)
                    {
                        cout << "Waste" << endl;
                        flag = true;
                        break;
                    }
                    else if (blocks[j][jk] > x)
                    {
                        break;
                    }
                    else
                    {
                        count++;
                    }
                }
            }
        }
 
        if (!flag)
        {
            int ans = (y - 1) * m + x - count;
 
            cout << temp_arr[(ans - 1) % 3] << endl;
        }
    }
 
    return 0;
}
//