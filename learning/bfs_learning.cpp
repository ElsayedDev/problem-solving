#include <bits/stdc++.h>

using namespace std;

bool is_this_the_value(string s)
{
    return s == "f";
}

int main()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    map<string, vector<string>> values = {
        {"s", {"a", "c"}},
        {"a", {"b", "f"}},
        {"b", {}},
        {"c", {"b", "d"}},
        {"d", {"f"}},
    };

    queue<vector<string>> qu;
    qu.push(values["s"]);

    int path = 0;
    while (!qu.empty())
    {
        vector<string> value = qu.front();
        qu.pop();

        path++;
        for (int i = 0; i < value.size(); i++)
        {

            if (is_this_the_value(value[i]))
            {
                cout << "shortest path is: " << path << endl;
                return 0;
            }
            else
            {
                qu.push(values[value[i]]);
            }
        }
    }
    cout << ":: :( bad after: " << path << endl;
}
