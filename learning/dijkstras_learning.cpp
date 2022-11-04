#include <bits/stdc++.h>

using namespace std;

#define V 9

int minDistance(int distance[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
    {
        if (sptSet[i] == false && distance[i] <= min)
        {
            min = distance[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    // hold the shortest distance bt src & x
    int distance[V];

    // visited
    bool sptSet[V];

    // memset all with initial values
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    // add first (src) with 0
    distance[src] = 0;

    int _count = V - 1;
    while (_count--)
    {
        int min_index = minDistance(distance, sptSet);

        sptSet[min_index] = true;

        for (int j = 0; j < V; j++)
        {
            if (!sptSet[j] && graph[min_index][j] && distance[min_index] != INT_MAX && distance[min_index] + graph[min_index][j] < distance[j])
            {
                distance[j] = distance[min_index] + graph[min_index][j];
            }
        }
    }

    cout << "Vertex   Distance from Source\n";

    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0},
    };

    dijkstra(graph, 0);
}
