#include <bits/stdc++.h>

#define Node map<string, map<string, int>>

#define Node2 map<string, set<string>>

using namespace std;

int infinity = 999999;

// map<string, int>::iterator find_lowest_cost_node(map<string, int> &costs, map<string, int> processed)
// {
//     int lowest_cost = infinity;
//     map<string, int>::iterator iter = costs.begin();
//     map<string, int>::iterator lowest_cost_node = costs.end();

//     while (iter != costs.end())
//     {
//         if (iter->second <= lowest_cost && processed[iter->first] == 0)
//         {
//             lowest_cost = iter->second;
//             lowest_cost_node = iter;
//         }
//         iter++;
//     }

//     return lowest_cost_node;
// }

// int dijkstra_count(Node2 graph, string start, string goal)
// {
//     // results
//     int result = 0;

//     if (graph.empty())
//     {
//         return result;
//     }

//     // to check if it processed or not
//     map<string, int> processed = {};

//     // path
//     map<string, string> parents = {};

//     // cost of each vertices from start to x
//     map<string, int> costs = {};

//     // initial cost
//     costs[start] = graph[start].size();

//     // first node
//     map<string, int>::iterator node = find_lowest_cost_node(costs, processed);

//     while (node != costs.end())
//     {
//         set<string> neighbor = graph[node->first];
//         int previous_cost = node->second;

//         for (set<string>::iterator iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
//         {
//             int neighbor_cost = costs[*iter_neighbor] > 0 ? costs[*iter_neighbor] : 0;
//             int total_cost = (previous_cost + neighbor_cost);

//             if (costs.find(*iter_neighbor) == costs.end() || total_cost <= costs[*iter_neighbor])
//             {
//                 costs[*iter_neighbor] = total_cost;
//                 parents[*iter_neighbor] = node->first;
//             }
//         }

//         // it's ok
//         processed[node->first]++;

//         // go to next
//         node = find_lowest_cost_node(costs, processed);
//     }

//     return result;
// }

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    map<char, set<pair<char, int>>> node2;

    for (int i = 0; i < s.length(); i++)
    {
        if (i != 0 && s[i] != s[i - 1])
        {

            node2[s[i]].insert(make_pair(s[i - 1], 1));
        }
        if (i + 1 < s.length() && s[i] != s[i + 1])
        {
            node2[s[i]].insert(make_pair(s[i + 1], 1));
        }
    }

    map<char, set<pair<char, int>>>::iterator node2_iterator = node2.begin();

    char start = s[0];

    char goal = s[s.length() - 1];

    map<char, int> costs;

    map<char, bool> visited;

    while (node2_iterator != node2.end())
    {
        visited[node2_iterator->first] = true;

        set<pair<char, int>> neighbor = node2_iterator->second;

        int min_cost = infinity;
        pair<char, int> best_node = {'x', infinity};

        for (auto element : neighbor)
        {
            if (element.second <= min_cost && visited[node2_iterator->first] == false)
            {
                min_cost = element.second;
                best_node = element;
            }
        }

        if (best_node.second == infinity)
        {
            // skip
        }else {
            
        }

        node2_iterator++;
    }

    return 0;
}

//