#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> nodes;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    // for (auto x : node)
    // {

    //     cout << x.first << " :: ";
    //     for (int i = 0; i < x.second.size(); i++)
    //     {
    //         cout << x.second[i] << " ";
    //     }

    //     cout << endl;
    // }

    int total_groups = 0;
    while (nodes.size() > 0)
    {

        vector<map<int, vector<int>>::iterator> nodes_will_removed;

        map<int, vector<int>>::iterator nodes_iterator = nodes.begin();

        while (nodes_iterator != nodes.end())
        {
            if (nodes_iterator->second.size() == 1)
            {
                nodes_will_removed.push_back(nodes_iterator);

                // remove it from the nodes
                nodes.erase(nodes_iterator);
            }
            
            if (nodes_iterator != nodes.end())
            {

                nodes_iterator++;
            }
        }

        // bool flag = false;

        // if (nodes.size() > 1)
        // {
        //     for (int k = 0; k < nodes_will_removed.size(); k++)
        //     {
        //         // will removed from all nodes
        //         int value = nodes_will_removed[k]->first;

        //         for (int i = 0; i < nodes_will_removed[k]->second.size(); i++)
        //         {
        //             int tied_node = nodes_will_removed[k]->second[i];

        //             for (auto it = nodes[tied_node].begin(); it != nodes[tied_node].end(); ++it)
        //             {

        //                 if (*it == value)
        //                 {
        //                     flag = true;

        //                     nodes[tied_node].erase(it);
        //                 }
        //             }
        //         }
        //     }
        // }

        // // increase number of removed group by 1
        // if (flag)
        // {
        //     total_groups++;
        // }
    }
    cout << total_groups << endl;
}

