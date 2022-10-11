#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int n, m;
char col;

bool valid(int x, int y)
{
    return x > -1 && x < n && y > -1 && y < m;
}

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, 1, 0, -1};

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    char room[101][100];
    set<char> ans;

    cin >> n >> m >> col;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> room[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (room[i][j] == col)
                for (int k = 0; k < 4; k++)
                {
                    int tox = i + dirx[k];
                    int toy = j + diry[k];
                    if (valid(tox, toy) && room[tox][toy] != col && room[tox][toy] != '.')
                        ans.insert(room[tox][toy]);
                }
        }
    cout << ans.size() << endl;
}
