#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX_VERTICES 50

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

typedef struct Node
{

    int value;
    bool isVisited = false;

} Node;

void bfs()
{
    // input
    map<int, vector<int>> graph = {
        {3, {5, 6}},
        {5, {3, 6, 4}},
        {1, {4}},
        {2, {4, 6}},
        {4, {2, 1, 5, 6}},
        {6, {2, 3, 5, 4}},
    };

    map<int, bool> visited = {};
    deque<int> dq;

    int value = 1;

    visited[value] = true;

    dq.push_back(value);

    while (!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();

        cout << ":: " << x << endl;

        for (auto element : graph[x])
        {
            if (visited[element] == false)
            {
                visited[element] = true;
                dq.push_back(element);
            }
        }
    }
}

int main()
{
    ReadDataWithSpeed();

    bfs();

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     int f;
    //     cin >> f;

    //     for (int i = 0; i < f; i++)
    //     {
    //     }
    // }

    return 0;
}