#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int x;
vector<pair<int, int>> posKey[26], shift;
bool can[26];

int dist(int i, int j, int shr, int shc)
{
    return (i - shr) * (i - shr) + (j - shc) * (j - shc);
}

bool check(int i, int j)
{
    for (int w = 0; w < shift.size(); w++)
    {
        int dis = dist(i, j, shift[w].first, shift[w].second);
        if (dis <= x * x)
            return true;
    }
    return false;
}

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;

    // n: rows, m: keys in each row, x: distance between center & key
    cin >> n >> m >> x;

    char ch[31][31];

    for (int i = 0; i < n; i++)
    {
        cin >> ch[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ch[i][j] == 'S')
            {
                shift.push_back(make_pair(i, j));
            }
            else
            {
                posKey[ch[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < posKey[i].size() && !can[i]; j++)
        {
            can[i] = can[i] | check(posKey[i][j].first, posKey[i][j].second);
        }
    }

    int q, res = 0;
    cin >> q;
    string txt;
    cin >> txt;
    for (int i = 0; i < q; i++)
    {
        if (islower(txt[i]))
        {
            if (posKey[txt[i] - 'a'].empty())
            {
                res = -1;
                break;
            }
        }
        else
        {
            txt[i] = tolower(txt[i]);
            if (shift.empty() || posKey[txt[i] - 'a'].empty())
            {
                res = -1;
                break;
            }
            if (!can[txt[i] - 'a'])
            {
                res++;
            }
        }
    }
    cout << res;
}
