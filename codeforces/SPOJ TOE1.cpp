#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

char shift_player(char ch)
{

    return ch == 'X' ? 'O' : 'X';
}

bool is_win(string pattern)
{
    bool rows =
        (pattern[0] != '.' && pattern[0] == pattern[1] && pattern[1] == pattern[2]) ||
        (pattern[3] != '.' && pattern[3] == pattern[4] && pattern[4] == pattern[5]) ||
        (pattern[6] != '.' && pattern[6] == pattern[7] && pattern[7] == pattern[8]);

    bool columns =
        (pattern[0] != '.' && pattern[0] == pattern[3] && pattern[3] == pattern[6]) ||
        (pattern[1] != '.' && pattern[1] == pattern[4] && pattern[4] == pattern[7]) ||
        (pattern[2] != '.' && pattern[2] == pattern[5] && pattern[5] == pattern[8]);

    bool diagonals =
        (pattern[0] != '.' && pattern[0] == pattern[4] && pattern[4] == pattern[8]) ||
        (pattern[2] != '.' && pattern[2] == pattern[4] && pattern[4] == pattern[6]);

    return rows || columns || diagonals;
}

void bfs(queue<pair<string, char>> qu, string board, string start)
{
    string ans = "no";

    while (qu.size())
    {
        string cur = qu.front().first;
        char cur_player = qu.front().second;
        qu.pop();

        // find the ans
        if (cur == board)
        {
            ans = "yes";
            break;
        }

        if (is_win(cur))
        {
            continue;
        }

        for (int i = 0; i < 9; i++)
        {
            if (cur[i] == '.')
            {

                if (cur_player == board[i])
                {
                    qu.push({cur, shift_player(cur_player)});
                    cur[i] = cur_player;
                }
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        string board = "";
        for (int i = 0; i < 3; i++)
        {
            string row;
            cin >> row;
            board += row;
        }

        // initial
        string start = ".........";
        queue<pair<string, char>> qu;
        qu.push({start, 'X'});

        bfs(qu, board, start);
    }
}
