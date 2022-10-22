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
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    map<int, vector<int>> blocks;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        blocks[y].push_back(x);
    }

start:
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;

        int blocks_count = 0;

        for (int j = y; j > 0; j--)
        {

            if (blocks[j].size() == 0)
                continue;
            // cout << "j: " << j << " size:" << blocks[j].size() << endl;

            for (int kj = 0; j == y ? kj < x : kj < blocks[j].size(); kj++)
            {
                if (j == y && x == blocks[j][kj])
                {
                    cout << "Waste" << endl;
                    goto start;
                }
                blocks_count++;
            }
        }
        // cout << endl;
        int total = (y - 1) * n - blocks_count + x - 1;
        cout << "all: " << (y - 1) * n << " bc: " << blocks_count << " x: " << x << " result: " << total << endl;
        // cout << temp_arr[(total) % 3] << endl;
    }

    return 0;
}
