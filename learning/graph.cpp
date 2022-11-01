#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int y;                 /* adjacency info */
    int weight;            /* edge weight, if any */
    struct edgenode *next; /* next edge in list */
} edgenode;

typedef struct
{
    edgenode *edges[10000];
    int degree[1000];
    int nVertices;
    int nEdges;
    int directed;

} graph;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
