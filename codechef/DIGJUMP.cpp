#include <bits/stdc++.h>

#define Node map<string, map<string, int>>

#define Node2 map<string, set<string>>

using namespace std;

int infinity = 999999;

map<string, int>::iterator find_lowest_cost_node(map<string, int> &costs, map<string, int> processed)
{
    int lowest_cost = infinity;
    map<string, int>::iterator iter = costs.begin();
    map<string, int>::iterator lowest_cost_node = costs.end();

    while (iter != costs.end())
    {
        if (iter->second <= lowest_cost && processed[iter->first] == 0)
        {
            lowest_cost = iter->second;
            lowest_cost_node = iter;
        }
        iter++;
    }

    return lowest_cost_node;
}

pair<vector<string>, int> dijkstra(Node graph)
{
    // results
    pair<vector<string>, int> result;

    if (graph.empty())
    {
        return result;
    }

    // to check if it processed or not
    map<string, int> processed;

    // path
    map<string, string> parents;

    // cost of each vertices from start to x
    map<string, int> costs;

    // initial cost
    costs["start"] = 0;

    // first node
    map<string, int>::iterator node = find_lowest_cost_node(costs, processed);

    while (node != costs.end())
    {
        map<string, int> neighbor = graph[node->first];
        int previous_cost = node->second;

        for (map<string, int>::iterator iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
        {
            int total_cost = (previous_cost + iter_neighbor->second);
            if (costs.find(iter_neighbor->first) == costs.end() || total_cost < costs[iter_neighbor->first])
            {
                costs[iter_neighbor->first] = total_cost;
                parents[iter_neighbor->first] = node->first;
            }
        }

        // it's ok
        processed[node->first]++;

        // go to next
        node = find_lowest_cost_node(costs, processed);
    }

    result.second = costs["fin"];
    result.first.push_back("fin");

    while (result.first.back() != "start")
    {
        result.first.push_back(parents[result.first.back()]);
    }

    return result;
}

int dijkstra_count(Node2 graph, string start)
{
    // results
    int result = 0;

    if (graph.empty())
    {
        return result;
    }

    // to check if it processed or not
    map<string, int> processed={};

    // path
    map<string, string> parents={};

    // cost of each vertices from start to x
    map<string, int> costs={};

    // initial cost
    costs[start] = graph[start].size();

    // first node
    map<string, int>::iterator node = find_lowest_cost_node(costs, processed);

    while (node != costs.end())
    {
        set<string> neighbor = graph[node->first];
        int previous_cost = node->second;

        for (set<string>::iterator iter_neighbor = neighbor.begin(); iter_neighbor != neighbor.end(); ++iter_neighbor)
        {
            int total_cost = (previous_cost + iter_neighbor->second);
            if (costs.find(iter_neighbor->first) == costs.end() || total_cost < costs[iter_neighbor->first])
            {
                costs[iter_neighbor->first] = total_cost;
                parents[iter_neighbor->first] = node->first;
            }
        }

        // it's ok
        processed[node->first]++;

        // go to next
        node = find_lowest_cost_node(costs, processed);
    }

    return result;
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    Node2 node2;

    for (int i = 0; i < s.length(); i++)
    {
        if (i != 0 && string(1, s[i]) != string(1, s[i - 1]))
        {

            node2[string(1, s[i])].insert(string(1, s[i - 1]));
        }
        if (i + 1 < s.length() && string(1, s[i]) != string(1, s[i + 1]))
        {
            node2[string(1, s[i])].insert(string(1, s[i + 1]));
        }
    }
    Node2::iterator node2_iterator = node2.begin();

    while (node2_iterator != node2.end())
    {
        cout << node2_iterator->first << " { ";

        for (auto child : node2_iterator->second)
        {

            cout << child << ", ";
        }

        cout << "};" << endl;

        // go next
        node2_iterator++;
    }

    cout << dijkstra_count(node2, string(1, s[0])) << endl;

    // graph["start"]["a"] = 5;
    // graph["start"]["b"] = 0;
    // graph["a"]["c"] = 15;
    // graph["a"]["d"] = 20;
    // graph["b"]["c"] = 30;
    // graph["b"]["d"] = 35;
    // graph["c"]["fin"] = 20;
    // graph["d"]["fin"] = 10;

    // pair<vector<string>, int> result = dijkstra(graph);

    // for (int i = 0; i < result.first.size(); i++)
    // {
    //     cout << result.first[i] << endl;
    // }

    return 0;
}
